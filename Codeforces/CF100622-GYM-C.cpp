/*
  since number of circles is just 100
  for each row, we go over all circles and find intersections with this line, sort all pairs of the intersections
  and add covered area to answer
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


const int maxn = 300500;
const double eps = 1e-8;

int n,m;
int x[maxn],y[maxn],r[maxn];

vector<pair<int,int>> ev;

void inter(int i,int y2){
    if(abs(y[i]-y2)>r[i]) return;
    int rem = sqrt(1LL*r[i]*r[i]-1LL*(y[i]-y2)*(y[i]-y2)+0.5);
    int l = max(0,x[i]-rem),r = min(m,x[i]+rem+1);
    ev.emplace_back(l,1);
    ev.emplace_back(r,-1);
}

int main(){
    freopen("in.txt","r",stdin);
    int k; scanf("%d %d %d",&m,&n,&k);
    lp(i,k) {
        scii(x[i],y[i]); sci(r[i]);
    }
    int cn = 0;
    lp(y2,n){
        ev.clear();
        lp(i,k) inter(i,y2);
        sort(ev.begin(),ev.end());
        int cur = 0;
        lp(i,ev.size()){
            if(cur)
                cn += ev[i].first - ev[i-1].first;
            cur += ev[i].second;
        }
     //   pri(cn);
    }
    printf("%lld ",1LL*n*m-cn);
    // solve();
}
