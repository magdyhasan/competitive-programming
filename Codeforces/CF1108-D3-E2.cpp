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


vector<int> st[maxn], en[maxn];
int a[maxn];

int n;

int segT[maxn * 4], lazy[maxn * 4];

void push(int idx,int l,int r){
    if (lazy[idx]){
        segT[idx] += lazy[idx];
        if (l != r){
            lazy[idx << 1] += lazy[idx];
            lazy[(idx << 1) | 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void updateSeg(int x, int y, int v, int idx = 1, int l = 0, int r = n - 1){
    push(idx, l, r);
    if (x > r || y < l) return;
    if (x <= l && y >= r){
        lazy[idx] += v;
        push(idx, l, r);
        return;
    }
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    updateSeg(x, y, v, lidx, l, mid);
    updateSeg(x, y, v, ridx, mid + 1, r);
    segT[idx] = min(segT[lidx], segT[ridx]);
}

int querySeg(int x, int y, int idx = 1, int l = 0, int r = n - 1){
    if (x > r || y < l) return 1e9+60;
    push(idx, l, r);
    if (x <= l && y >= r) return segT[idx];
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    return min(querySeg(x, y, lidx, l, mid), querySeg(x, y, ridx, mid + 1, r));
}

void build(int idx = 1, int l = 0, int r = n - 1){
    if (l == r){
        segT[idx] = a[l];
        return;
    }
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    build(lidx, l, mid);
    build(ridx, mid + 1, r);
    segT[idx] = min(segT[lidx], segT[ridx]);
}

int al[maxn], ar[maxn];

void solve(){
    int m; scii(n,m);
    lp(i,n) sci(a[i]);
    build();
    lp(i,m){
        int u,v; scii(u,v);
        --u; --v;
        al[i] = u; ar[i] = v;
        st[u].push_back(v);
        en[v].push_back(u);
        updateSeg(u,v,-1);
    }
    int ret = -1e8, id;
    lp(i,n){
        for(auto j:st[i])
            updateSeg(i,j,1);
        if(ret < a[i]-segT[1]){
            ret = a[i]-segT[1];
            id = i;
        }
        for(auto j:en[i])
            updateSeg(j,i,-1);
    }
    vector<int> v;
    lp(i,m) if(!(id>=al[i]&&id<=ar[i]))
        v.push_back(i+1);
    pri(ret);
    pri(v.size());
    for(auto i:v) printf("%d ",i);
}


int main() {
    freopen("in.txt","r",stdin);
    solve();
}
















