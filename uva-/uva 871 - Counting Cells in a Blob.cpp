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

const int maxn = 10000005;
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction

char li[32][32];
bool vis[32][32];


int n = 0, m = 0;
int cnt;

void dfs(int i,int j){
   if(i >= n || j >= m || vis[i][j] || li[i][j] != '1') return;
   vis[i][j] = 1;
   cnt++;
   for(int k=0;k<8;k++) dfs(i+dx[k],j+dy[k]);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("uva.txt", "rt", stdin);
#endif
   int t;
   sci(t);
   gets(li[0]); 
   gets(li[0]);
   while(t--){
      n = m = 0;
      while(gets(li[n++])){
         if(strlen(li[n-1]) == 0) break;
      }
      n--;
      m = strlen(li[0]);
      memset(vis,0,sizeof vis);
      int ret = 0;
      for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j] && li[i][j] == '1'){
         cnt = 0;
         dfs(i,j);
         ret = max(ret,cnt);
      }
      pri(ret);
      if(t) puts("");
   }
}

