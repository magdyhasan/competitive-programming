/*
  let's solve using events sorting
  -if current is openning, just increment cnt(number of opened intervals)
  -if it's required problem, if no opened interval, then answer impossible, otherwise temporary remove one interval so we don't use it for another problem
  -for closing, just decrement cnt
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

const int maxn = 300500;


ll pa[maxn], su[maxn], suf[maxn], pre[maxn];

ll par(int x){
    return (x == pa[x]?x:pa[x]=par(pa[x]));
}

ll d[maxn], c[maxn], res[maxn];


void solve(){
    int n;sci(n);
    int m; sci(m);
    vector<pair<int,int>> v;
    lp(i,n){
        int a,b; scii(a,b);
        v.emplace_back(a,0);
        v.emplace_back(b,2);
    }
    lp(i,m){
        int a; sci(a);
        v.emplace_back(a,1);
    }
    sort(v.begin(),v.end());
    int cnt = 0, temp = 0, ret = 0;
    for(auto i:v){
        if(i.second == 0) ++cnt;
        else if(i.second == 2){
            if(temp) --temp;
            else --cnt;
        }else{
            ret = max(ret,n-cnt+1);
            ++temp;
            --cnt;
        }
    }
    if(ret>n) puts("IMPOSSIBLE!");
    else pri(ret);
}


int main() {
    freopen("in.txt","r",stdin);
    int tc; sci(tc);
    lp(tt,tc){
        printf("Case #%d: ",tt+1);
        solve();
    }
}










