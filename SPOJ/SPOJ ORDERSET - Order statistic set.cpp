/*
  First compress all numbers so we can store them wtihin BIT
  query is standard BIT query
  k-th query can be done using lower_bound on BIT in logN instead of logN^2
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
const int maxn = 1<<22;//2e5+5;
const double EPS = 1e-7;

char st[maxn][2];
int v[maxn];
bool in[maxn];

int bit[maxn];

void update(int idx, int val){
    for (int x = idx; x < maxn; x += (x & -x)){
        bit[x] += val;
    }
}

int query(int idx){
    int ret = 0;
    for (int x = idx; x > 0; x -= (x&-x))
        ret += bit[x];
    return ret;
}

int lower_bound(int val) {
    int key = 0;
    for (int len = (maxn >> 1); len; len >>= 1) {
        if (val > bit[key + len]) {
            val -= bit[key += len];
        }
    }
    return key + 1;
}

void solve() {
    int q; sci(q) ;
    vector<int> va;
    lp(i,q){
        scanf("%s %d",st[i],&v[i]);
        if(st[i][0] == 'I') va.push_back(v[i]);
    }
    sort( va.begin(), va.end() );
    va.erase( unique( va.begin(), va.end() ), va.end() );
    lp(i,q){
        int mv = lower_bound(va.begin(),va.end(),v[i]) - va.begin() + 1;
        if(st[i][0] == 'I'){
            if(!in[mv]){
                in[mv] = 1;
                update(mv,1);
            }
        }else if(st[i][0] == 'D'){
            if(in[mv] && va[mv-1] == v[i]){
                in[mv] = 0;
                update(mv,-1);
            }
        }else if(st[i][0] == 'K'){
            int id = lower_bound(v[i]) - 1;
            if(id >= va.size()) puts("invalid");
            else printf("%d\n", va[id]);
        }else{
            printf("%d\n",query(mv-1));
        }
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
        //printf("Case %d:\n",tt+1);
        solve();
    }
}

