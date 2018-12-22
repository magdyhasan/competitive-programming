/*
	we only care about parities of numbers, because we can add vertical bricks
	so it doesn't matter height, but only parity of number

	now let's think about array as sequence of segments
	if the length of segment is even, then we can change it's parity from 0 to 1 or vice versa

	this means for even sequence we can group it with left segment and right segment
	and after each merging we have less segments to work on
	so at the end, if there's one segment, then answer is 'YES' else 'NO'
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

int n;
int a[maxn];
set<pair<int, int>> seg, eseg;

int main() {
	//freopen("in.in", "r", stdin);	
	sci(n);
	lp(i, n){
		sci(a[i]);
		a[i] %= 2;
	}
	lp(i, n){
		int j = i;
		while (j + 1 < n && a[j + 1] == a[i]) ++j;
		seg.insert({ i, j });
		if ((j - i + 1) % 2 == 0) eseg.insert({ i, j });
		i = j;
	}
	while (!eseg.empty() && seg.size()>1){
		auto cur = *eseg.begin();
		seg.erase(cur);
		eseg.erase(cur);
		auto it = seg.lower_bound(cur);
		if (it != seg.end()){
			if ((it->second - it->first + 1) % 2 == 0)
				eseg.erase(*it);
			cur.second = it->second;
			seg.erase(it);
		}
		it = it = seg.lower_bound(cur);
		if (it != seg.begin()){
			--it;
			if ((it->second - it->first + 1) % 2 == 0)
				eseg.erase(*it);
			cur.first = it->first;
			seg.erase(it);
		}
		seg.insert(cur);
		if ((cur.second - cur.first + 1) % 2 == 0)
			eseg.insert(cur);
	}
	puts(seg.size() == 1 ? "YES" : "NO");
}