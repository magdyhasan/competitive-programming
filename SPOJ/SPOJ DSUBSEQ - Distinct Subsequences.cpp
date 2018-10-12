/*
	let dp[i] be the number of subsequences ending at index i
	let s[i] = dp[i-1] + dp[i-2] + ... dp[0]
	now if we gonna append char at i+1 we can append to s[i] places
	but this way we might overcounted same char that appear at index j where j < i+1
	so we can store la[char] for each character that give last position of char
	if we adding c, we can say dp[i] = s[i-1] - the number of times that last position of same char could've been added
*/
#include<bits/stdc++.h>
using namespace std;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)


const int md = (int) 1e9 + 7;

inline void add(int &a, int b) {
	a += b;
	if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += md;
}

inline int mul(int a, int b) {
	return (int)((long long)a * b % md);
}

inline int power(int a, long long b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

char st[300500];
int dp[300500], s[300500], la[128];

int main(){
    freopen("uva.txt","rt",stdin);
	int t; sci(t);
	while (t--){
		memset(la, 0, sizeof la);
		memset(s, 0, sizeof s);
		scanf("%s", st + 1);
		int n = strlen(st + 1);
		s[0] = 1;
		lpi(i, 1, n + 1){
			dp[i] = s[i - 1];
			if (la[int(st[i])])
				sub(dp[i], s[la[int(st[i])] - 1]);
			add(s[i], s[i - 1] + dp[i]);
			la[int(st[i])] = i;
		}
		printf("%d\n", s[n]);
	}
}
