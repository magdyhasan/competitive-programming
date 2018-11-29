/*
	we will have a set containing some price of previos days
	when we have new price, if have smaller price in our list then we use this price ( buy it )
	and sell our current price

	this set will be updated as follows:
	-if we have new price and no smaller price in our list, we just insert it in our list so we can use it later
	-if we have new price and there's a smaller price in our list,
	then we sell our current price, but we still add it to our set twice
	because now we have 2 options, we either won't use it again,
	or we want to unSELL it, so that means we will once use it in means of unSELLing it
	and we added second time so we can buy it again if we want

	ex:
	say we have price [1] in our set, and now we have price [2] coming,
	so we will buy [1] and sell [2], we remove [1] from our set and add [2] twice to our set
	so now our set have [2,2]
	now if we encounter [3] it was optimal to sell [3] and buy [1], we can do this option
	by removing one [2] from our set, which means we still have one [2] in our set
	and it's like we bought [1] and sell [3] and didn't do anything with [2]
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
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)

int main(){
	int n; sci(n);
	int t;
	ll ret = 0;
	multiset<int> s;
	while (n--){
		sci(t);
		if (!s.empty() && *s.begin() < t){
			ret += t - *s.begin();
			s.erase(s.begin());
			s.insert(t);
			s.insert(t);
		}
		else
			s.insert(t);
	}
	prll(ret);
}
