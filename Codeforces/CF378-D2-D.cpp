/*
notice that the function is montonic in number if days,
i.e if we can solve all bus in n days, then we can solve them in n+1 days for sure

so binary search for number of days

now when we have fixed number of days(us), meaning we can use each student ( if we gonna use it ) us times

so start from hardest bug, find all students that can solve this problem, and choose minimum one
this can be done by sorting bugs and keeping student with levels >= bugs complexities in current set
and then find minimum cost in this set
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

const int maxn = 200010;

pair<int, int> bu[maxn];
pair<int, pair<int, int>> st[maxn];

int ret[maxn];
int n, m, s;

set<pair<int, int>> av;

bool ch(int us){
	int is = 0;
	ll co = 0, rem = 0;
	av.clear();
	for (int d = 0; d < m; d += us){
		while (is < n && st[is].first >= bu[d].first)
			av.insert(st[is].second), is++;
		if (av.empty()) return 0;
		co += av.begin()->first;
		av.erase(av.begin());
		if (co > s) return 0;
	}
	return co <= s;
}


void print(int us){
	int is = 0;
	av.clear();
	for (int d = 0; d < m;){
		while (is < n && st[is].first >= bu[d].first)
			av.insert(st[is].second), is++;
		int j = us;
		int id = av.begin()->second;
		av.erase(av.begin());
		while (j--){
			ret[bu[d].second] = id;
			d++;
			if (d >= m) break;
		}
	}
	puts("YES");
	lp(i, m) printf("%d ", ret[i] + 1);
}




int main() {
	scii(n, m); sci(s);
	lp(i, m) sci(bu[i].first);
	lp(i, m) bu[i].second = i;
	lp(i, n) st[i].second.second = i;
	lp(i, n) sci(st[i].first);
	lp(i, n) sci(st[i].second.first);
	sort(st, st + n);
	reverse(st, st + n);
	sort(bu, bu + m);
	reverse(bu, bu + m);
	int l = 1, r = m + 1, ans = 0;
	while (l <= r){
		int mid = (l + r) / 2;
		if (ch(mid)){
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	if (ans == 0) puts("NO");
	else print(ans);
}