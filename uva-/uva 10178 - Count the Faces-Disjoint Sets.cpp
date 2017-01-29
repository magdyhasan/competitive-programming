#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;


struct disjoint_set{
    vector<int> parent;
    int faces;
    // initialize
    disjoint_set(int n){
        parent = vector<int>(n);
        for(int i=0;i<n;i++)
            parent[i] = i;
        faces = 1;
    }
    // check parent
    int find_set(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x]);
    }
    // check union of two sets and add them to same set
    void union_sets(int x,int y){
        x = find_set(x);
        y = find_set(y);
        if(x == y) // if they are in the same set then we now made a new face
            faces++;
        else // we add them to the same set
            parent[x] = y;
    }
};


int main(){
    int n,m;
    while(cin >> n >> m){
        disjoint_set se(n);
        map<string,int> ma; // map every character(string) to a number
        ma.clear();
        int idx = 0; // start indexing from 0
        string u,v;
        int p,q;
        for(int i=0;i<m;i++){
            cin >> u >> v;
            if(ma.count(u) == 0) // if the character doesn't have index make one for them
                ma[u] = idx++;
            if(ma.count(v) == 0) // if the character doesn't have index make one for them
                ma[v] = idx++;
            p = ma[u];
            q = ma[v];
            se.union_sets(p,q); // add them to the same set
        }
        cout << se.faces << '\n';
    }

}
