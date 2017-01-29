#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n,m,S,E,C;

struct edge{
    int to,from,cost;
    bool operator < (const edge &a) const{
        return cost < a.cost;
    }
};

struct disjointSet{ // DSU
    vector<int> p;
    disjointSet (int ta) : p(ta,-1) {} // constructor

    int par(int x){ // find par of x
        return (p[x] < 0) ? x:p[x] = par(p[x]);
    }

    bool Union(int x,int y){
        x = par(x);
        y = par(y);
        if(x != y){ // if the're not in the same component
            if(x > y)
                swap(x,y);
            p[y] += p[x];
            p[x] = y;
        }
        return x != y;
    }
};

vector< edge > edges(205);
vector< int > used;

int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        printf("Case #%d : ",t);
        scanf("%d%d",&n,&m);
        // initialize
        edges = vector<edge>(m);
        used = vector<int> ();
        int sum1 = 0, sum2 = (1<<30);
        disjointSet un1(n+1);

        // read all edges
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&S,&E,&C);
            edges[i] = {S,E,C};
        }

        sort(edges.begin(),edges.end());

        for(int i=0;i<m;i++) // create the first MST
            if(un1.Union(edges[i].from,edges[i].to))
                    sum1 += edges[i].cost, used.push_back(i);

        if(used.size() != n-1){ // if it's node doesn't equal to n-1 then we couldn't make a MST
            puts("No way");
            continue;
        }
        for(auto out:used){ // try to remove one each of each of the used edges in the first MST
            int cur_s = 0, Nodes = 0;
            disjointSet un2(n+1); // now construct another MST without using (out) edge that we removed
            for(int i=0;i<m;i++){
                if(i == out)    continue; // we've removed this edge
                if(un2.Union(edges[i].from,edges[i].to))
                    cur_s += edges[i].cost, Nodes++;
            }
            if(Nodes == n-1 && cur_s < sum2) // if we made a MST ( hence Nodes == n-1 ) and it's cost < sum2
                sum2 = cur_s;
        }
        if(sum2 == (1<<30)) // if we didn't find any second MST
            puts("No second way");
        else // we found second MST and we minimized on it with sum2
            printf("%d\n",sum2);
    }
}
