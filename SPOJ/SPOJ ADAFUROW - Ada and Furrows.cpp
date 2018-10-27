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

const int maxn = 30500;

bitset<maxn> a[maxn];

char st[2];

int main(){
	int q;  sci(q);
	int x, y;
	while (q--){
		scanf("%s%d%d", st, &x, &y);
		if (st[0] == '+') a[x][y] = 1;
		else if (st[0] == '-') a[x][y] = 0;
		else if (st[0] == 'v') pri((a[x] | a[y]).count());
		else if (st[0] == '^') pri((a[x] & a[y]).count());
		else if (st[0] == '!') pri((a[x] ^ a[y]).count());
		else pri((a[x] & ~(a[y])).count());
	}
}