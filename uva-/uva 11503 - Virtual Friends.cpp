#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

int p[100005],nodes[100005];

int par(int x){ // find parent of the component
    if(x == p[x]) // if this the parent of itself
        return x;
    return p[x] = par(p[x]); // set parent of x to the parent of parent x
}

map<string,int> id;
int n,m;
char str1[25],str2[25];



int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        id.clear();
        n = 0;
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%s%s",str1,str2);
            if(id.count(str1) == 0) // give id to node if it has no id
                p[n] = n, nodes[n] = 1,id[str1] = n++; // pare of node is itself and it's component has 1 node
            if(id.count(str2) == 0)
                p[n] = n, nodes[n] = 1,id[str2] = n++;
            int s1 = id[str1];
            int s2 = id[str2];
            s1 = par(s1);
            s2 = par(s2);
            if(s1 != s2){ // if they're not in the same component
                p[s1] = s2;
                nodes[s2] += nodes[s1]; // add number of nodes of s1 to s2
            }
            printf("%d\n",nodes[s2]);
        }
    }
}
