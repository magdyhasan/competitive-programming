/*
	for each pair of check if one polygon is inside another or if they intersecting
	use DSU to maintain number of groups
*/
#include<bits/stdc++.h>
using namespace std;


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

point reflect(point p, point p0, point p1) {
	point z = p - p0, w = p1 - p0;
	return conj(z / w)*w + p0; // Refelect point p1 around p0p1
}


bool isPointOnSegment(point a, point b, point c) {
	double acb = length(a - b), ac = length(a - c), cb = length(b - c);
	return dcmp(acb - (ac + cb), 0) == 0;
}

// Accurate and efficient
int isInsidePoly(vector<point> p, point p0) {
	int wn = 0;  // the winding number counter

	for (int i = 0; i < p.size(); i++) {
		point cur = p[i], nxt = p[(i + 1) % (p.size())];
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

bool intersectSegments(point a, point b, point c, point d) {
	double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
	if (fabs(d1) < EPS)
		return false;  // Parllel || identical

	double t1 = d2 / d1, t2 = d3 / d1;
	point intersect = a + (b - a) * t1;

	if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS || t1 > 1 + EPS)
		return false;  //e.g ab is ray, cd is segment ... change to whatever
	return true;
}


int p[128];
int par(int x){
	return (p[x] == x ? x : p[x] = par(p[x]));
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	string li;
	int cnt = 1;
	while (cin >> n && n){
		cnt++;
		getline(cin, li);
		vector<vector<point>> po;
		for (int i = 0; i < n; i++){
			po.push_back(vector<point>());
			getline(cin, li);
			double a, b;
			istringstream iss(li);
			while (iss >> a >> b){
				po.back().push_back({ a, b });
			}
		}
		for (int i = 0; i < n; i++) p[i] = i;
		int forests = n;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++){
			bool in = 0;
			int u = par(i), v = par(j);
			if (u == v) continue;
			for (auto p : po[i]) if (isInsidePoly(po[j], p)){
				in = 1;
				break;
			}
			if (!in)
			for (auto p : po[j]) if (isInsidePoly(po[i], p)){
				in = 1;
				break;
			}
			for (int pi = 0, pii = po[i].size()-1; pi < po[i].size(); pii = pi ++) 
				for (int pj = 0, pjj = po[j].size()-1; pj < po[j].size(); pjj = pj ++) {
					if (intersectSegments(po[i][pi], po[i][pii], po[j][pj], po[j][pjj])) {
						in = 1;
						break;
					}
				}
			if (in){
				forests--;
				p[v] = u;
			}
		}
		cout << forests << "\n";
	}
}
