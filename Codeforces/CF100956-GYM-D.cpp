/*
	Let's sort the array by maximum A's then by maximum B's

	now let's suppose that player b, plays all turns

	but when take a value b[i], he keep this value in a set

	now in player a turn, he will take minimum from that set

	we can see this optimal because:
	-in first turn, player a take first elemtn because it's only element in the set
	-in second turn player b take it and add it to set
	-in third turn player b take it again, and add it to set, so now we have 2 elements in the set,
	we choose minimum from them for a to take, because player b had the choice to take either of them
	in his turn, and it was optimal for him to take largest, and now when player a take minimum from
	this, we achieve our goal
	- and so on..
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
#define prll(a)	printf("%lld\n",a)

typedef long long ll;
const int maxn = 300500;

int a[maxn], b[maxn];

int main(){
	int n; sci(n);
	lp(i, n) sci(a[i]);
	lp(i, n) sci(b[i]);
	vector<pair<int, int>> v;
	lp(i, n) v.push_back({ -a[i], -b[i] });
	sort(all(v));
	multiset<int> ms;
	ll ret = 0;
	lp(i, n){
		ret += -v[i].second;
		ms.insert(-v[i].second);
		if (i % 2 == 0){
			ret -= *ms.begin();
			ms.erase(ms.begin());
		}
	}
	prll(ret);
}
