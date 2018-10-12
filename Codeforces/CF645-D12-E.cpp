/*
first: we must understand how we can obtain distinct distinct subsequence of string: https://www.geeksforgeeks.org/count-distinct-subsequences/

now as we can see, when we are adding new character at position i, we have to subtrach it's dp[lastOccuran[char[i]]
also notice that do[i] > dp[j], for all i > j
so it's always better to subtract dp[j] where j is minimum because it make dp[i] bigger

so first count number of distinct subsequence of string t

now when adding remaining n characters, we loop over all possible chars, and add one with least last occurance as we proved

time: O(n*k)
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



typedef long long ll;

const int maxn = 300500;


int dp[2000500];
int s[2000500];
int la[27];

char st[2000500];


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


int main(){
	ios::sync_with_stdio(0);
	int n, m, k;
	scanf("%d%d%s", &n, &k, st + 1);
	m = strlen(st + 1);
	s[0] = 1;
	lpi(i, 1, m + 1){
		dp[i] = s[i - 1];
		if (la[(st[i] - 'a')]) sub(dp[i], s[la[(st[i] - 'a')] - 1]);
		add(s[i], s[i - 1] + dp[i]);
		la[(st[i] - 'a')] = i;
	}
	for (int i = m + 1; i <= m + n; i++){
		int mxj = 0, mx = la[0];
		lp(j, k){
			if (la[j] < mx){
				mxj = j;
				mx = la[j];
			}
		}
		dp[i] = s[i - 1];
		sub(dp[i], s[la[mxj] - 1]);
		add(s[i], s[i - 1] + dp[i]);
		la[mxj] = i;
	}
	cout << s[n + m];
}