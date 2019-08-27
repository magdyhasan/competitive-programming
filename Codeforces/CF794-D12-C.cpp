/*
 * main greedy is for each player put largest/smallest avaiable one
 * corner case when the other one  biggest char is smaller than our smallest
 * then we change greedy and build from right instead from left
 */
#include <bits/stdc++.h>
using namespace std;


#define all(v)          ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


const int maxn = 2e5+50;
typedef long long ll;

int a[maxn];
int n;

vector<pair<int,int>> adj[maxn];

int ret[maxn];
ll su[maxn], st[maxn];

void rec(int u,int de, ll s){
	st[de] = u;
	su[de] = s;
	int l = lower_bound(su,su+de+1,s-a[u])-su-1;
	--ret[st[l]]; ++ret[u];
	for(auto v:adj[u]){
		rec(v.first,de+1,s+v.second);
		ret[u] += ret[v.first];
	}
}


void solve(){
	fast_cin();
	string sa,sb; cin >> sa >> sb;
	sort(all(sa));
	sort(all(sb));
	reverse(all(sb));
	int n = sa.size();
	deque<char> a,b;
	lp(i,(n+1)/2) a.emplace_back(sa[i]);
	lp(i,n/2) b.emplace_back(sb[i]);
	string retl,retr;
	bool rev = 0;
	for(int i=0;i<n;i++){
		if(i&1){
			if(!a.empty() && a.front()>= b.front())
				rev = 1;
			if(rev){
				retr += b.back();
				b.pop_back();
			}else{
				retl += b.front();
				b.pop_front();
			}
		}else{
			if(!b.empty() && a.front()>= b.front())
				rev = 1;
			if(rev){
				retr += a.back();
				a.pop_back();
			}else{
				retl += a.front();
				a.pop_front();
			}
		}
	}
	reverse(all(retr));
	retl += retr;
	cout << retl;
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		puts("");
	}
}
