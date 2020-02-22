/*
  let mxsz = sz(clubs-1)/2
  then make a flow network 
          1           1          1          mxsz
  souces ----> club -----> per ----> party -----> sink
    
  and this means we only taking one person from each club ( first edge from source to club == 1 )
  and from each party we only take <= mxsz, this restriction by last edge to sink
  
  now to restore answer, just with a simple for loop, 
  because edges have capcity 1, so it's 0, it's means we are using it
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




int head[maxn], d[maxn], prv[maxn], record[maxn];

struct Node{
    int u, v, c;
    int nxt;
} edge[maxn];
int e;

void addEdge(int u, int v, int c){
    //cout << rid[u] << " " << rid[v] <<  " " << u << " " << v <<  " " << c << endl;
    //forward edge
    edge[e].u = u, edge[e].v = v, edge[e].c = c;
    edge[e].nxt = head[u], head[u] = e++;
    //backward edge
    edge[e].u = v, edge[e].v = u, edge[e].c = 0;
    edge[e].nxt = head[v], head[v] = e++;
}

int maxflow(int s, int t){
    int flow = 0;
    while (true){
        memset(d, 0, sizeof(d));
        d[s] = 123456789;
        queue<int> q;
        q.push(s);
        while (!q.empty()){
            int u = q.front();	 q.pop();
            if (u == t) break;
            for (int i = head[u]; i != -1; i = edge[i].nxt)
                if (d[edge[i].v] == 0 && edge[i].c > 0){
                    q.push(edge[i].v);
                    d[edge[i].v] = min(d[u], edge[i].c);
                    prv[edge[i].v] = u, record[edge[i].v] = i;
                }
        }
        if (d[t] == 0) break;
        flow += d[t];
        for (int u = t; u != s; u = prv[u]){
            int ed = record[u];
            edge[ed].c -= d[t];
            edge[ed ^ 1].c += d[t];
        }
    }
    return flow;
}

map<string,set<string>> clMe;
set<string> pt;
map<string,string> topt;
int node;

map<string,int> clIdx, peIdx, paIdx;
map<int,string> rid;

string te;
void init(){
    clMe.clear(); pt.clear(); topt.clear(); clIdx.clear(); peIdx.clear(); paIdx.clear(); rid.clear();
    memset(head,-1,sizeof head);
    e = 0;
    node = 1;
}
int ttc;
string li;
void solve() {
    init();
    while (getline(cin, li) && li != "") {
        //cout << ttc << " "  << li << endl;
        istringstream ss(li);
        string name, party, club;
        ss >> name >> party;
        pt.insert(party);
        topt[name] = party;
        while (ss >> club) {
            clMe[club].insert(name);
        }
    }
    ++ttc;
    vector<int> clIds;
    //giving id's to nodes in graph
    for(auto i:clMe){
        clIdx[i.first] = ++ node;
        clIds.push_back(node);
        rid[node] = i.first;
    }
    for(auto i:topt){
        peIdx[i.first] = ++ node;
        rid[node] = i.first;
    }
    for(auto i:pt){
        paIdx[i] = ++ node;
        rid[node] = i;
    }
    int source = 0, sink = ++node;
    rid[0] = "soucre"; rid[sink] = "sink";
    memset(head,-1,sizeof head);
    for(auto i:clMe){
        //souce -> club
        addEdge(source,clIdx[i.first],1);
        for(auto pe:i.second){
            // club -> person
            //cout << "add cl pe " << i.first << " " << pe << " "<< idx[i.first] << " " << idx[pe] << endl;
            addEdge(clIdx[i.first],peIdx[pe],1);
        }
    }
    // person -> party
    for(auto i:topt){
        addEdge(peIdx[i.first],paIdx[i.second],1);
    }
    int mxsz = (clIds.size()-1)/2;
    for(auto i:pt){
        addEdge(paIdx[i],sink,mxsz);
    }
    //cout << clIds.size() << " " << mxsz <<  endl;
    int flow = maxflow(source,sink);
    if(flow != clIds.size()){
        cout << "Impossible.\n";
    }else{
        for(auto cl:clIds){
            for(int j = head[cl]; j != -1; j = edge[j].nxt) if(edge[j].c == 0){
                cout << rid[edge[j].v] << " " << rid[edge[j].u] << "\n";
                break;
            }
        }
    }
  //  cout << "==========================\n" ;
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    fast_cin();
    cin >> tc;
    getline(cin,li);
    getline(cin,li);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        if(tt) cout << "\n";
        solve();
    }
}
