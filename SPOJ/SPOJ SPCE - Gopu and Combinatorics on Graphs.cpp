/*
  sort all people by they first competition result
  now when iterating we now this person can be excellent only if no previous person have better result in b,c compeition
  to check this effiecntly use BIT, use b as position and c as value at this position
  now given a new person, get minimum value in any position < b
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
const int maxn = 800500;

int tree[maxn*4];

int get(int idx){
    int ret = inf;
    for (; idx > 0; idx -= (idx & -idx)){
        ret = min(ret, tree[idx]);
    }
    return ret;
}

void update(int idx, int v){
    for (; idx <= maxn; idx += (idx & -idx))
        tree[idx] = min(tree[idx], v);
}

struct pe{
    int a,b,c;
    bool operator < (const pe& ot) const {
        return a < ot.a;
    }
}a[maxn];

void solve() {
    int n; sci(n);
    lp(i,n){
        sci(a[i].a); scii(a[i].b,a[i].c);
    }
    sort(a,a+n);
    fill(tree,tree+maxn,inf);
    //pri(tree[0]);
    int ret = 0;
    lp(i,n){
        if(get(a[i].b) > a[i].c)
            ++ret;
        update(a[i].b,a[i].c);
    }
    pri(ret);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    sci(tc);
    lp(tt,tc){
       // printf("Case %d:\n",tt+1);
        solve();
    }
}

