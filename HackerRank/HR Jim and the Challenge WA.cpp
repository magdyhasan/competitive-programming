#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 300500;

typedef long long ll;

const ll mod = 1000000009;

int h[maxn], x[5][maxn];
pair<int, int> p[maxn];

ll u[maxn], v[maxn];// u: sum(hj*xj), v: sum(hj)

int main(){
    freopen("uva.txt","rt",stdin);
	int n, d; scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++){
		scanf("%d", h + i);
		for (int j = 0; j < d; j++) scanf("%d", &x[j][i]);
	}
	int ret = 0;
	for (int dd = 0; dd < d; dd++){
		for (int i = 0; i < n; i++) p[i].first = x[dd][i], p[i].second = h[i];
		sort(p, p + n);
		u[0] = 1LL * p[0].second * p[0].first, v[0] = p[0].second;
		for (int i = 1; i < n; i++) 
			u[i] = u[i - 1] + 1LL * p[i].second * p[i].first, v[i] = v[i - 1] + p[i].second;
		for (int i = 0; i < n; i++)
			ret = (ret + (p[i].second * u[i + 1] - p[i].second * p[i].first * v[i + 1])) ;
	}
	printf("%d\n", ret);
}
