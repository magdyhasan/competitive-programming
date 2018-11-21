/*
	first to simplify problem, let's make all operations on height h
	so any operation on height < h, we can convert it easily to height h by making l = l*2, r = r*2+1
	and we can see that this doesn't effect operation at all

	solving the problem with 2 operatins needs handling lot of cases
	what about making it just one operation !
	let's convert operation that has ans = 1 on range [l,r]
	to operation of that has ans = 0 on range [2^(h-1),l-1] and [r+1,2^h-1]

	now we have some segments on one axis that mark segment as not valid

	we can sort all this segments and handle intersection between them to find answer
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 1000500;

typedef pair<ll, bool> plb;

#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)

int main(){
	int h, q;  scii(h, q);
	int i, ans; 
	ll l, r;
	vector<plb> v;
	pair<ll, ll> se = { 1ll << (h - 1), (1ll << h) - 1 };
	while (q--){
		scanf("%d%lld%lld%d", &i, &l, &r, &ans);
		lp(j, h - i) l *= 2ll, r = r * 2ll + 1;
		if (ans){
			//0 to l
			if (l != se.first){
				v.push_back({ se.first, 0 });
				v.push_back({ l - 1, 1 });
			}
			//r to en
			if (r != se.second){
				v.push_back({ r + 1, 0 });
				v.push_back({ se.second, 1 });
			}
		}
		else{
			v.push_back({ l, 0 });
			v.push_back({ r, 1 });
		}
	}
	sort(all(v));
	ll last = se.first - 1;
	ll emp = 0, empPos = 0, curInter = 0;
	v.push_back({ se.second + 1, 0 });
	for (auto it : v){
		if (it.second){
			--curInter;
			last = it.first;
		}
		else{
			if (curInter == 0 && last + 1 < it.first){
				emp += it.first - (last + 1);
				empPos = last + 1;
			}
			curInter++;
		}
	}
	if (emp == 0)puts("Game cheated!");
	else if (emp > 1) puts("Data not sufficient!");
	else printf("%lld", empPos);
}