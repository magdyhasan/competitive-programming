#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prii(a, b)	printf("%d %d\n",a, b)
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const ll  inf = 1000000000000000000LL;
const double EPS = 1e-9;
const ll mod = 1000000007ll;
#define PI acos(-1)

const int maxn = 500500;


int longestP[1000500];
char pat[1000500];

void KMP(){
	for (int i = 1, k = 0; pat[i]; i++){
		while (k > 0 && pat[i] != pat[k]) k = longestP[k - 1];
		if (pat[i] == pat[k]) longestP[i] = ++k;
		else longestP[i] = k;
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif	
	scanf("%s", pat);
	int n = strlen(pat);
	KMP();
	if (longestP[n - 1] == 0){
		puts("Just a legend");	return 0;
	}
	for (int i = 0; i + 1 < n; i++) if (longestP[n - 1] == longestP[i]){
		for (int j = 0; j < longestP[i]; j++) putchar(pat[j]); return 0;
	}
	if (longestP[longestP[n - 1] - 1] == 0){
		puts("Just a legend");	return 0;
	}
	for (int j = 0; j < longestP[longestP[n - 1] - 1]; j++) putchar(pat[j]);
}
