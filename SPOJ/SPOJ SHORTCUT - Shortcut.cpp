/*
  solve for x and y independtly
  sort x points, now when we have same x for some points
  this can be a shortcut
*/
#include<bits/stdc++.h>
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



const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const int inf = 1<<30;
const int maxn = 600500;//2e5+5;
const double EPS = 1e-7;


typedef  pair<int,pair<int,pair<int,char>>> result;
char s[maxn];

string DIR = "NSEW";
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int x[maxn], y[maxn];
vector<int> po;

void solve() {
    int n; sci(n);
    scanf("%s",s);
    int cx = 0, cy = 0;
    po.clear();
    po.push_back(0);
    lp(i,n){
        int id = DIR.find(s[i]);
        cx += dx[id];
        cy += dy[id];
        x[i+1] = cx;
        y[i+1] = cy;
        po.push_back(i+1);
    }
    // go over x's
    sort(po.begin(),po.end(),[&](int i,int j){
        return (make_pair(x[i],y[i]) < make_pair(x[j],y[j]));
    });
    result ret = {1e9,{1e9,{1e9,'w'}}};
    lpi(i,1,n+1) if(x[po[i]] == x[po[i-1]] && abs(po[i]-po[i-1]) > 1){
        result cur = {abs(y[po[i]]-y[po[i-1]]),{min(po[i],po[i-1]),{-max(po[i],po[i-1]),'w'}}};
        if(y[cur.second.first] < y[-cur.second.second.first]) cur.second.second.second = 'N';
        else cur.second.second.second = 'S';
        ret = min(ret,cur);
    }
    // go over y's
    sort(po.begin(),po.end(),[&](int i,int j){
        return (make_pair(y[i],x[i]) < make_pair(y[j],x[j]));
    });
    lpi(i,1,n+1) if(y[po[i]] == y[po[i-1]] && abs(po[i]-po[i-1]) > 1){
        result cur = {abs(x[po[i]]-x[po[i-1]]),{min(po[i],po[i-1]),{-max(po[i],po[i-1]),'w'}}};
        //printf("de %d %d %d %c\n",ret.first,ret.second.first,-ret.second.second.first,ret.second.second.second);
        if(x[cur.second.first] < x[-cur.second.second.first]) cur.second.second.second = 'E';
        else cur.second.second.second = 'W';
        ret = min(ret,cur);
    }
    printf("%d %d %d %c\n",ret.first,ret.second.first,-ret.second.second.first,ret.second.second.second);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
