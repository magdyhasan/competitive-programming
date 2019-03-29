/*

	HINT: fix 2 rows or columns

	HINT2: think about 2 pointers
	
	if we fix 2 columns (or 2 rows), we now know what letter's should be on corners.
	so now iterate over all rows and find which rows have same letter's in those corners

	now to find number of pairs of rows given fixed columns,
	we use 2 pointers, with accumulative sum of square inside it to fit in time
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define scll(a)	scanf("%lld",&a)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)

const int maxn = 300500;

const int MOD = 1e9 + 7;
typedef pair<int, int> pii;


char st[450][450];

int s[450][450];

int pos[450][450], cn[450];


int gets(int i, int j, int i1, int j1){
	//printf("%d %d %d %d\n", i, j, i1, j1);
	return s[i + 1][j + 1] - s[i1][j + 1] - s[i + 1][j1] + s[i1][j1];
}

int main(){
	freopen("uva.txt", "r", stdin);
	int n, m, K; scii(n, m); sci(K);
	lp(i, n) scanf("%s", st[i]);
	lp(i, n) lp(j, m)
		s[i + 1][j + 1] = s[i][j + 1] + s[i + 1][j] - s[i][j] + (st[i][j] == 'a');
	ll ret = 0;
	lp(i, m) lpi(j, i + 1, m){
		clr(cn, 0);
		lp(k, n)	 if (st[k][i] == st[k][j])
			pos[(st[k][i] - 'a')][cn[(st[k][i] - 'a')]++] = k;
		lp(ch, 26){
			int k2 = 0;
			lp(k, cn[ch]){
				while (k2 < cn[ch] && gets(pos[ch][k2], j, pos[ch][k], i) <= K){
					++k2;
				}
				k2 = max(k2, k + 1);
				//printf("rect: %d %d %d %d\n", k, k2);
				ret += k2 - k - 1;
			}
		}
	}
	prll(ret);
}