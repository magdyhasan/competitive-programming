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

const int maxn = 300500;

int lr[] = { 0, 1, 1, 1, 2, 3 };
int rr[] = { 0, 4, 5, 6, 6, 6 };

int di[] = { 0, 1, 1 };
int dj[] = { 1, 0, 1 };


char gr[32][32];

int dp[1 << 20];

int rec(){
	int msk = 0;
	for (int i = 1; i < 6; i++){// build mask of current board
		for (int j = lr[i]; j < rr[i]; j++) {
			msk <<= 1;
			if (gr[i][j] == 'O') msk = msk | 1;
		}
	}
	int &ret = dp[msk];
	if (ret != -1) return ret;
	for (int i = 1; i < 6 && ret < 0; i++) for (int j = lr[i]; j < rr[i] && ret < 0; j++) if (gr[i][j] == 'O'){
		for (int k = 0; k < 3 && ret < 0; k++){// try all moves
			int ni = i, nj = j;
			while (gr[ni][nj] == 'O'){
				gr[ni][nj] = '*';
				ni += di[k];
				nj += dj[k];
				if (!rec()){// if he loses, i win
					ret = 1;
					break;
				}
			}
			while (ni != i || nj != j){// backtrack what we did
				ni -= di[k];
				nj -= dj[k];
				gr[ni][nj] = 'O';
			}
		}
	}
	return ret != -1;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("CF.in", "rt", stdin);
#endif
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i < 6; i++) for (int j = lr[i]; j < rr[i]; j++)
		scanf(" %c", gr[i] + j);
	puts(rec() ? "Karlsson" : "Lillebror");
}

