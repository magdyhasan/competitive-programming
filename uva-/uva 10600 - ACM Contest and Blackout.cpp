#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
    int from,to,cost;
    edge (int a,int b,int c): from(a),to(b),cost(c) {}
    bool operator < (const edge &a){
        return cost < a.cost;
    }
};


struct UnionFind{ // disjoint-set
    vector<int> p,rank;
    UnionFind (int n): p(n,-1),rank(n,1) {}

    int par(int x){
        return (p[x] < 0) ? x:p[x] = par(p[x]);
    }

    bool link(int x,int y){
        x = par(x);
        y = par(y);
        if(x != y){
            if(rank[x] > rank[y])
                swap(x,y);
            p[x] = y;
            if(rank[x] == rank[y])
                rank[y]++;
        }
        return x != y;
    }
};

vector<edge> edges;
vector<int> used;
int n,m;
int A,B,C;

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        // initialize
        edges.clear();
        used.clear();

        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&A,&B,&C);
            edges.push_back({A,B,C});
        }
        sort(edges.begin(),edges.end());
        // create first minimum spanning tree with prim
        UnionFind un1(n+1);
        int c1 = 0, c2 = (1<<30);
        for(int i=0;i<m;i++)
            if(un1.link(edges[i].from,edges[i].to))
                c1 += edges[i].cost,used.push_back(i);
        // create second minimum spanning tree with prim ( by trying to remove one edge from the first MST )
        for(auto out:used){
            UnionFind un2(n+1);
            int cur_2 = 0, nodes = 0;
            for(int i=0;i<m;i++)
                if(i == out)    continue;
                else if(un2.link(edges[i].from,edges[i].to))
                    cur_2 += edges[i].cost,nodes++;
            if(nodes == n-1 && cur_2 < c2) // we got a second MST
                c2 = cur_2;
        }
        printf("%d %d\n",c1,c2);
    }
}
