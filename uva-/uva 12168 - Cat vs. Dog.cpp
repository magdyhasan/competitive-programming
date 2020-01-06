/*
  this problem looks a lot like matching
  but we can't just do matching on cats and dogs because they might be some persons that vote the same vote (multiple edge between two nodes)
  so instead we find maximum independent set on persons who loves cats and persons who loves dogs
  and maximum independent set on bipartite graph is just complement of vertex cover or maximum matching which is standard problem
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
const int maxn = 1000500;//2e5+5;
const double EPS = 1e-7;


vector<int> adj[512];
vector<int> vis, colAssign, rowAssign;

bool canMatch(int i){ // O(E)
    for (int j = 0; j<adj[i].size(); ++j) if (!vis[adj[i][j]]) {
            vis[adj[i][j]] = 1;
            if (colAssign[adj[i][j]] < 0 || canMatch(colAssign[adj[i][j]])) {
                colAssign[adj[i][j]] = i, rowAssign[i] = j;
                return true;
            }
        }
    return false;
}


int bipartiteMatching(int rows, int cols){	// O(EV)
    // In case spares graph, use adjList
    int maxFlow = 0;
    colAssign = vector<int>(cols, -1), rowAssign = vector<int>(rows, -1);
    for (int i = 0; i<rows; ++i) {
        vis = vector<int>(cols, 0);
        if (canMatch(i))
            maxFlow++;
    }
    return maxFlow;
}

char s1[12], s2[12];

void solve() {
    int n,m,e; scii(n,m) ; sci(e);
    vector<pair<string,string>> catl,dogl;
    lp(i,e){
        scanf("%s%s",s1,s2);
        if(s1[0]=='C') catl.push_back({s1,s2});
        else dogl.push_back({s1,s2});
    }
    lp(i,512) adj[i].clear();
    lp(i,catl.size()){
        lp(j,dogl.size()){
            if((catl[i].first == dogl[j].second)||(dogl[j].first == catl[i].second))
                adj[i].push_back(j);
        }
    }
    //puts("ANS");
    //printf("dim %d %d\n",catl.size(),dogl.size());
    pri(e-bipartiteMatching(catl.size(),dogl.size()));
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
