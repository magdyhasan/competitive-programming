/*
  - notice that for a fixed i, to have maximum number we need to use all updates including that i
  - but doing that for each i will TLE
  - use seomthing like segment tree, traverse from above and keep for each range all possible updates and do them 
  while going down, when we reach reaf we possible answer for that leaf
  - for updating it's something like knapsack, so we can use a dp or just a bitset 
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

//100000100
const int mxb = 10100;
bitset<mxb> ans;
int n,q;

vector<int> sg[maxn];

void add(int ql, int qr, int x,int idx = 1,int l=1, int r=n){
    if(l>=ql && r <= qr){
        sg[idx].push_back(x);
        return ;
    }
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    if(ql<=mid) add(ql,qr,x,lidx,l,mid);
    if(qr>mid) add(ql,qr,x,ridx,mid+1,r);
}

void tra(bitset<mxb> bs, int idx = 1,int l=1, int r=n){
    for(auto x:sg[idx])
        bs |= bs << x;
    if(l == r){
        ans |= bs;
        return;
    }
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    tra(bs,lidx,l,mid);
    tra(bs,ridx,mid+1,r);
}

void solve() {
    scii(n,q);
    int l,r,x;
   // puts("bef add");
    lp(i,q){
        scii(l,r), sci(x);
        add(l,r,x);
    }
  //  puts("done add");
    bitset<mxb> bs; bs[0] = 1;
    tra(bs);
    vector<int> v;
    lp(i,n+1) if(i && ans[i])
        v.push_back(i);
    pri(v.size());
    for(auto i:v) printf("%d ",i);
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}

