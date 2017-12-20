/*
	hint1: we can solve for number of out of range for rows independent of columns, and then add them together




	hint2: if we tried all possible start poition in same row/column we can see this is unimodal funtion
	at first is high, then it decreases to reach minimum then by moving too much to right we start to increase again



	so just solve for column by ternary search to find minimum position and so for rows
*/

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

char st[maxn];
int n, m; 

int cnt1(int p){
	int s = p, r= 0;
	for (int i = 0; st[i]; i++) {
		if (st[i] == '<') {
			if (s == 0) r++;
			else s--;
		}
		if (st[i] == '>'){
			if (s + 1 >= m) r++;
			else s++;
		}
	}
	return r;
}

int cnt2(int p){
	int s = p, r= 0;
	for (int i = 0; st[i]; i++) {
		if (st[i] == 'v') {
			if (s == 0) r++;
			else s--;
		}
		if (st[i] == '^'){
			if (s + 1 >= n) r++;
			else s++;
		}
	}
	return r;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
	int T; scanf("%d", &T);;
	while (T--){
		scii(n, m);
		scanf("%s", st);
		int l = 0, r = m - 1, ret = 0, m1, m2, mm = 123456789;
		while (l <= r){
			m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			if (cnt1(m1) < cnt1(m2)) r= m2 - 1, mm =  min(mm,cnt1(m1));
			else l = m1 + 1, mm = min(mm, cnt1(m2));
		}
		ret += mm;
		l = 0, r = n - 1, mm = 123456789;
		while (l <= r){
			m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
			if (cnt2(m1) < cnt2(m2)) r= m2 - 1, mm =  min(mm,cnt2(m1));
			else l = m1 + 1, mm = min(mm, cnt2(m2));
		}
		ret += mm;
		pri(ret);
	}
}
