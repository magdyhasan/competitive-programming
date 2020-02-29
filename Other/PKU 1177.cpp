/*
  let's solve for each axis independently
  we can sort point in axis, and just run through them, and mark the used segment of rectangle with brute-force, to not over count it
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

struct da{
    int x,s,e,ty;
    bool operator < (const da & ot) const {
        return (make_pair(x,s) < make_pair(ot.x,ot.s));
    }
};

int su[maxn];

void upd(int l,int r, int v){
    lpi(i,l,r+1)
        su[i] += v;
}

int get(int l,int r){
    int ret = 0;
    lpi(i,l,r+1)
        ret += su[i];
    return ret;
}

int cnt(vector<da> &a){
    int ret = 0;
    memset(su,0,sizeof su);
    sort(a.begin(),a.end());
    for(auto i:a){
        if(i.ty == 0){
            ret += (i.e-i.s+1)-get(i.s,i.e);
            upd(i.s,i.e,1);
        }else{
            upd(i.s,i.e,-1);
            ret += (i.e-i.s+1)-get(i.s,i.e);
        }
    }
    return ret;
}

const int max_i = 100500;

void solve() {
    int n; sci(n);
    vector<da> xs,ys;
    lp(i,n){
        int a,b,c,d;
        scii(a,b);
        scii(c,d);
        a += max_i; b += max_i; c += max_i; d += max_i;
        xs.push_back({a,b,d-1,0});
        xs.push_back({c,b,d-1,1});

        ys.push_back({b,a,c-1,0});
        ys.push_back({d,a,c-1,1});
    }
    pri(cnt(xs) + cnt(ys));
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
