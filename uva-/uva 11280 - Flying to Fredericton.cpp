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
const int maxn = 100500;//2e5+5;


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)


struct edg{
    int u,v,c;
    int nxt;
    bool operator < (const edg & ot) const {
        return u > ot.u;
    }
} edge[maxn];
int head[maxn], e;

void addEdge(int u, int v, int c){
	//forward edge
	edge[e].u = u, edge[e].v = v, edge[e].c = c;
	edge[e].nxt = head[u], head[u] = e++;
}


map<string,int> to;
int id;
int getId(string &s){
    if(to.count(s))
        return to[s];
    to[s] = ++id;
    return id;
}

int n,m;
string tu,tv;
int d[maxn], ans[maxn];

void solve() {
    to.clear();
    id = 0;
    memset(head, -1, sizeof(head));
    e = 0;
    cin >> n;
    lp(i,n){
        cin >> tu;
        getId(tu);
    }
    string ts = "Calgary", tt = "Fredericton";
    int sid = getId(ts), tid = getId(tt);
    cin >> m;
    int co;
    lp(i,m){
        cin >> tu >> tv >> co;
        addEdge(getId(tu),getId(tv),co);
    }
    lp(i,n+2) d[i] = inf, ans[i] = inf;
    d[sid] = 0;
//    cout << "edge\n" ;
//    for(int i=0;i<e;i+=2)
//        cout << edge[i].u << " "<< edge[i].v << " " << edge[i].c << endl;
   // dbg(sid,tid);
    lp(st,n-1){
        for(int u=n;u>0;u--)if(d[u] < inf){
            for (int i = head[u]; i != -1; i = edge[i].nxt){
                if(d[edge[i].v] > d[u] + edge[i].c)
                    d[edge[i].v] = d[u] + edge[i].c;
            }
        }
//        cout << st << ":\n";
//        lp(i,n) cout << d[i+1] << " " ;
//        cout << endl;
        ans[st] = d[tid];
//        cout << "co\n" ;
//        lp(i,n+1)
//            cout << d[i] << " ";
    }
    int qq; cin >> qq;
 //   cout << "qu " << qq << endl;
    while(qq--){
        int tq; cin >> tq;
        tq = min(tq,n-2);
//cout << "tq " << tq << endl;
        if(ans[tq] >= inf) cout << "No satisfactory flights\n";
        else cout << "Total cost of flight(s) is $" << ans[tq] << "\n";
    }
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    fast_cin();
    int tc = 1;
    //sci(tc);
    cin >> tc;
    lp(tt,tc){
        if(tt) cout << "\n";
        cout << "Scenario #" << tt+1 << "\n";
  //      printf("Case #%d: ",tt+1);
        solve();
    }
}
