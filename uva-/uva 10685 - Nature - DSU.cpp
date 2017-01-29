#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<string,int> id;

struct UnionFind{ // disjoint-set
    vector<int> rank,par,nodes;
    int mxComponent;

    UnionFind(int n){ // initialize
        rank = vector<int> (n+1);
        par = vector<int> (n+1);
        nodes = vector<int> (n+1); // number of nodes for each component
        for(int i=0;i<n;i++)
            rank[i] = 0, par[i] = i, nodes[i] = 1;
        mxComponent = 1;
    }

    int find_set(int x){ // return par of this component
        if(par[x] != x) // if we didn't reach par of this component yet
            return par[x] = find_set(par[x]);
        return x;
    }

    void link(int x,int y){
        x = find_set(x);
        y = find_set(y);
        if(x != y){ // if they're not in the same set
            if(rank[x] > rank[y]) // make y has the highest length
                swap(x,y);
            par[x] = y; // make y parent of x
            nodes[y] += nodes[x]; // add x nodes to y component nodes
            if(rank[x] == rank[y]) // if they were the same height then we must added a new node
                rank[y]++;
            mxComponent = max(mxComponent,nodes[y]); // maximize on number of nodes on y component
        }
        return;
    }
};

int n,m;


int main(){
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0)
            break;
        char st[35],str[35];
        id.clear();
        UnionFind UF(n); // create a disjoint-set
        for(int i=0;i<n;i++)
            scanf("%s",st),id[st] = i; // give id to each node
        for(int i=0;i<m;i++)
            scanf("%s%s",st,str), UF.link(id[st],id[str]); // add links between connected nodes
        printf("%d\n",UF.mxComponent);
    }
}
