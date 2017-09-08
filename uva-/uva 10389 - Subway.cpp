#include<bits/stdc++.h>
using namespace std;


const int maxn = 300500;

double x[maxn], y[maxn];
int vis[maxn];
char li[maxn];

typedef pair<double, int> pii;

vector<pii> adj[maxn];

double di(double x1, double y1, double x2, double y2){
	double dx = x2 - x1;
	double dy = y2 - y1;
	return sqrt(dx*dx + dy*dy);
}


double dijskstra(){
	memset(vis, 0, sizeof(vis));
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	pq.push(pii(0, 0));
	while (pq.empty() == false) {
		pii u = pq.top();
		pq.pop();
		if (u.second == 1)	
			return u.first;
		if (vis[u.second])	continue;
		vis[u.second] = 1;
		for (auto v : adj[u.second])
			if (vis[v.second] == false)
				pq.push(pii(v.first + u.first, v.second));
	}
}

int main(){
	freopen("uva.txt", "rt", stdin);
	int T;  scanf("%d", &T);
	while (T--){
		for (int i = 0; i < maxn; i++) adj[i].clear();
		int n = 2;
		scanf("%lf%lf%lf%lf", &x[0], &y[0], &x[1], &y[1]);
		while (getchar() != '\n');
		while (gets(li)){
			if (li[0] == '\0') break;
			istringstream iss(li);
			double tx, ty;
			iss >> x[n] >> y[n];
			n++;
			while (iss >> tx >> ty){
				if (tx < 0) break;
				x[n] = tx, y[n] = ty;
				adj[n].push_back(make_pair(di(x[n], y[n], x[n - 1], y[n - 1]), n -1));
				adj[n - 1].push_back(make_pair(di(x[n], y[n], x[n - 1], y[n - 1]), n));
				n++;
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i!=j)
			adj[i].push_back(make_pair(di(x[i], y[i], x[j], y[j])*4., j));
		printf("%d\n", (int)(dijskstra() * 6 / 4000 + 0.5));
		if (T) puts("");
	}
}
