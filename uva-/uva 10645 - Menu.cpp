#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> pii;

pii dp[22][55][105];
int k, n, m;
int c[55], v[55];

bool vis[22][55][105];



pii rec(int idx, int last, int bud){
	if (idx >= k) return{ 0, 0 };
	pii &ret = dp[idx][last][bud];
	if (vis[idx][last][bud]) return ret;
	ret = { -1, -1 };
	for (int i = 0; i < n; i++) if (i != last){
		pii tcur = { 0, 0 };
		for (int cnt = 0; cnt + idx < k; cnt++){
			if (cnt == 0) tcur.first += v[i];
			else if (cnt == 1) tcur.first += v[i] / 2;
			tcur.second += c[i];
			if (bud < tcur.second) break;
			pii cur = rec(idx + cnt + 1, i, bud - tcur.second);
			if (cur.first == -1) continue;
			cur.first += tcur.first, cur.second += tcur.second;
			if (cur.first > ret.first || (ret.first == cur.first && ret.second > cur.second))
				ret = cur;
		}
	}
	vis[idx][last][bud] = 1;
	return ret;
}

vector<int> pa;

void build(int idx, int last, int bud){
	if (idx >= k) return;
	pii ret = dp[idx][last][bud];
	for (int i = 0; i < n; i++) if (i != last){
		pii tcur = { 0, 0 };
		for (int cnt = 0; cnt + idx < k; cnt++){
			if (cnt == 0) tcur.first += v[i];
			else if (cnt == 1) tcur.first += v[i] / 2;
			tcur.second += c[i];
			if (bud < tcur.second) break;
			pii cur = rec(idx + cnt + 1, i, bud - tcur.second);
			if (cur.first == -1) continue;
			cur.first += tcur.first, cur.second += tcur.second;
			if (cur == ret){
				for (int p = 0; p <= cnt; p++) pa.push_back(i+1);
				build(idx + cnt + 1, i, bud - tcur.second);
				return;
			}
		}
	}
	return;
}

int main(){
    freopen("uva.txt","rt",stdin);
	bool fi = 0;
	while (scanf("%d%d%d", &k, &n, &m)){
		if (!n && !k && !m) break;
		if (fi) puts("");
		fi = 1;
		for (int i = 0; i < n; i++) scanf("%d%d", c + i, v + i), v[i] *= 2;
		memset(vis, 0, sizeof(vis));
		int ret = rec(0, 52, m).first;
		if (ret == -1) puts("0.0");
		else  {
			printf("%.1lf\n", ret / 2.);
			pa.clear();
			build(0, 52, m);
			for (int i : pa) printf("%d ", i);
			puts("");
		}
	}
}
