/*
	make a directed graph where an edge a -> b means a is a polygon inside polygon b
	now construct a second graph where an edge a -> b means a is polygon that contains polygon b
	now for each query point iterate on all polygons that's doesn't beong to any polygon and recurse on this polgon if this polygon contain this point
*/
#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

const double EPS = (1e-8);	// use lower carefully, e.g. for binary search

int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1; }

typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
#define polar(r,ang)            ((r)*exp(point(0,ang))) 
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)

bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a - b), ac = length(a - c), cb = length(b - c);
	return dcmp(acb - (ac + cb), 0) == 0;
}
int isInsidePoly(vector<point> p, point p0) {
	int wn = 0;  // the winding number counter
	for (int i = 0; i < p.size(); i++) {
		point cur = p[i], nxt = p[(i + 1) % p.size()];
		if (isPointOnSegment(cur, nxt, p0))
			return true;
		if (cur.Y <= p0.Y) {    // Upward edge
			if (nxt.Y > p0.Y && cp(nxt - cur, p0 - cur) > EPS)
				++wn;
		}
		else {                // Downward edge
			if (nxt.Y <= p0.Y && cp(nxt - cur, p0 - cur) < -EPS)
				--wn;
		}
	}
	return wn != 0;
}
int n;
int np[512], pid[1024], vis[1024], dep[1024], pa[1024];

vector<point> po[1024];
vector<int> padj[1024], adj[1024];



void dfs(int u){
	vis[u] = 1; dep[u] = 0; pa[u] = -1;
	int	mxd = -1;
	for (auto v : padj[u]){
		if (!vis[v]) dfs(v);
		if (mxd < dep[v])
			mxd = dep[v], pa[u] = v;
	}
	dep[u] = mxd + 1;
}

vector<int> cur;

int query(int u, point p){
	for (auto i : adj[u])
		if (isInsidePoly(po[i], p))
			return query(i, p);
	return u;
}
int ret[1024];

int main(){
    freopen("uva.txt","rt",stdin);
	string li;
	int tc; scanf("%d", &tc);
	double a, b;
	while (tc--){
		scanf("%d", &n);
		while (getchar() != '\n');
		for (int i = 0; i < n; i++){
			getline(cin, li);
			istringstream iss(li);
			iss >> pid[i];
			po[i].clear();
			while (iss >> a >> b) {
				po[i].push_back({ a, b });
			}
		}
		pid[n] = 0;
		for (int i = 0; i < n; i++)
			padj[i].clear(), adj[i].clear(), vis[i] = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) if (i != j) {
				if (isInsidePoly(po[i], po[j][0]))
					padj[j].push_back(i);
			}
		}
		for (int i = 0; i < n; i++) if (!vis[i])
			dfs(i);
		for (int i = 0; i < n; i++) {
			if (pa[i] == -1) adj[n].push_back(i);
			else adj[pa[i]].push_back(i);
		}
		cur.clear();
		int m;  scanf("%d", &m);
		for (int i = 0; i < m; i++){
			cur.push_back(i);
			int id;
			scanf("%d %lf %lf", &id, &a, &b);
			ret[id] = query(n, { a, b });
		}
		for (int i = 1; i <= m; i++)
			printf("%d %d\n", i, pid[ret[i]]);
		if (tc) puts("");
	}
}
