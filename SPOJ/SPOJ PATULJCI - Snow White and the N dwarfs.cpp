/*
	if for some segment there's a dominating color, then there'll be exactly one color


	so we can try randomised solution, for each segment test some random colors from that segments

	and we can count number of color in segment easily using binary search
*/
#include <bits/stdc++.h>	
using namespace std;


#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)


const int maxn = 300500;

typedef long long ll;

vector<int> occ[maxn];
int l, r;
int co[maxn];

int cnt(int c){
	return upper_bound(all(occ[c]), r) - lower_bound(all(occ[c]), l);
}

void solve(){
	lp(t, 50){
		int c = co[l + rand() % (r - l + 1)];
		if (cnt(c) * 2 > (r - l + 1)) {
			printf("yes %d\n", c);
			return;
		}
	}
	puts("no");
}

int main() {
	freopen("in.in", "r", stdin);
	srand(time(NULL));
	int n, cos;
	scii(n, cos);
	lp(i, n) sci(co[i + 1]), occ[co[i + 1]].push_back(i + 1);
	int q; sci(q);
	while (q--){
		scii(l, r);
		solve();
	}
}