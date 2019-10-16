/*
  if we know at position i, where to move to, we can solve this easily with dp[i][j], i position and j left of m
  
  to build next[i], create vector of starting position of each event and end of it
  iterate through all positions and add/remove and build next
*/
#include <bits/stdc++.h>
using namespace std;
 
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
 
 
 
typedef long long ll;
 
const ll mod = 1e6+3;
 
const int maxn = 100500;
 
vector<pair<int,int>> st[maxn], en[maxn];
pair<int,int> nxt[maxn];
 
ll dp[maxn][205];
 
void solve(){
    int n;sci(n);
    int m; sci(m);
    int k; sci(k);
    int s,e,w,d;
    lp(i,k){
        scii(s,e)   ; scii(d,w);
        st[s].emplace_back(w,d);
        en[e].emplace_back(w,d);
    }
    multiset<pair<int,int>> cur;
    lp(i,n+1){
        for(auto it:st[i]) cur.insert(it);
        nxt[i].first = i + 1;
        if(cur.size()){
            nxt[i].first = cur.rbegin()->second + 1;
            nxt[i].second = cur.rbegin()->first;
        }
        for(auto it:en[i]) cur.erase(cur.find(it));
    }
    for(int i=n;i>=0;i--) for(int j=0;j<=m;j++){
        dp[i][j] = dp[nxt[i].first][j] + 1LL*nxt[i].second;
        if(j){
            dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
        }
    }
    prll(dp[0][m]);
}
 
 
int main() {
  //  freopen("in.txt","r",stdin);
    int tc;
    //sci(tc);
    tc = 1;
    lp(tt,tc){
        //printf("Case #%d: ",tt+1);
        solve();
    }
}
