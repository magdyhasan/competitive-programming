/*
	after some tracing, notice that
	for each pair of maximum numbers after removing edges,
	max of them must be == n, if not then output no

	now let's build tree from small to greater
	sort all input number ( that != n )
	we don't have to put small number that doesn't appear in in input
	we can safely build edge with last elment because it's always smaller so max of this edge will be current number

	just corner case we need to handle when number appear more than once,
	we have to put a smaller number in that place ( from unused elements we kept so far, if there's none, output no )
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
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)


const int maxn = 300500;

int n;

int u[maxn], v[maxn];
int occ[maxn];

void solve(){
	multiset<int> no;
	lp(i, n - 1){
		if (v[i] != n){
			puts("NO"); return;
		}
		no.insert(u[i]);
	}
	set<int> av;
	int cur = 1;
	vector<pair<int, int>> ed;
	int la = -1;
	for (auto i : no){
		while (cur < i) av.insert(cur++);
		cur = i + 1;
		int ta = -1;
		if (occ[i] > 0){
			if (av.empty()){
				puts("NO"); return;
			}
			ta = *av.begin();
			av.erase(av.begin());
		}
		else
			ta = i;
		occ[i] = 1;
		if (la == -1) la = ta;
		else{
			ed.push_back({ la, ta });
			la = ta;
		}
	}
	ed.push_back({ la, n });
	if (ed.size() != n - 1){
		puts("NO"); return;
	}
	puts("YES");
	for (auto i : ed) printf("%d %d\n", i.first, i.second);
}


int main() {
	freopen("in.in", "r", stdin);
	sci(n);
	lp(i, n - 1){
		scii(u[i], v[i]);
		if (v[i] < u[i]) swap(u[i], v[i]);
	}
	solve();
}