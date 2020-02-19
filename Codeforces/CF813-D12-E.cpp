/*
  first let's create another array b, 
  where b[i] = -1, if number of a[i] till now < k
  else b[i] = location of a[i] at the k-th index before this
  
  now given array b, query is just asking for how many elements in range l,r are <= l
  as this means that occurance of this elements doesn't exceed k times
  
  now this standard problem using merege segment tree or presistent segment tree
  
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


template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}


#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const int inf = 1<<30;
const int maxn = 600500;//2e5+5;



vector<int> segT[maxn * 8];
int a[maxn], b[maxn];
int n;


void build(int idx = 1, int l = 1, int r = n) {
    if (l == r) {
        segT[idx] = vector<int>(1, b[l]);
    } else {
        int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
        build(lidx, l, mid);
        build(ridx, mid + 1, r);
        merge(segT[lidx].begin(), segT[lidx].end(), segT[ridx].begin(), segT[ridx].end(),
              back_inserter(segT[idx]));
    }
}

int query(int x, int y, int z, int idx = 1, int l = 1, int r = n){
    if (r < x || l > y) return 0;
    if (x <= l && r <= y) {
        return lower_bound(segT[idx].begin(), segT[idx].end(), z) - segT[idx].begin();
    }
    int mid = (l + r) >> 1, lidx = idx << 1, ridx = lidx | 1;
    return query(x, y, z, lidx, l, mid) + query(x, y, z, ridx, mid + 1, r);
}


vector<int> pos[maxn];


void solve() {
    int k; scii(n,k);
    lpi(i,1,n+1){
        sci(a[i]);
        if(pos[a[i]].size()< k)
            b[i] = -1;
        else
            b[i] = pos[a[i]][pos[a[i]].size()-k];
        pos[a[i]].push_back(i);
    }
    build();
    int l,r,last = 0;
    int q; sci(q);
    while(q--){
        int x,y; scii(x,y);
        l = ((x + last) % n) + 1;
        r = ((y + last) % n) + 1;
        if (l > r)  swap(l, r);
        last = query(l,r,l);
        pri(last);
    }
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
