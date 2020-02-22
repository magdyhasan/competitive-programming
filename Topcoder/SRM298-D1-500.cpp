/*
  notice that the dim of the final matrix, have to be dim from one of the matrices we have
  so if we fixed one as the final matrix, it's first dim can never change, but second one can't
  
  we can think of terms of graph, repesent each dim as node, now we have directed edge from node  to node to repesenet matrix
  
  now if we can have euler tour or cycle, we can multiply all of them, else no
  
  to find maximum one, if we have tour cycle, we choose maximum dim as final matrix
  else we find dim that have 1 degree and -1 degree as start/end of our tour
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;


class OrderDoesMatter {
public:
	int getOrder(vector <int> N, vector <int> M);
};

const int maxn = 1005;

int p[maxn];
int par(int x){
    return (x == p[x] ? x:p[x] = par(p[x]));
}

bool occ[maxn];
int deg[maxn];

inline void merg(int a,int b){
 	a = par(a), b = par(b);
    if(a!=b){
     	p[b] = a;   
    }
}

int OrderDoesMatter::getOrder(vector <int> N, vector <int> M){
    for(int i=0;i<maxn;i++){
        p[i] = i;
        occ[i] = 0;
        deg[i] = 0;
    }
    int n = N.size();
    for(int i=0;i<n;i++){
        deg[N[i]]++;
        deg[M[i]]--;
        occ[N[i]] = occ[M[i]] = 1;
        merg(N[i],M[i]);
    }
    int cc = 0, odd = 0;
    for(int i=0;i<maxn;i++){
        cc += (occ[i] && par(i) == i);
        odd += (deg[i] > 0);
        if(abs(deg[i]) > 1)
            return -1;
    }
    if(cc > 1 || odd > 1)
        return -1;
    int s=0,e=0;
    if(odd){
        for(int i=0;i<maxn;i++) if(occ[i]){
         	if(deg[i] == 1) s = i;
            if(deg[i] == -1) e = i;
        }
        return s*e;
    }else{
        for(int i=0;i<maxn;i++)
            if(occ[i])
            	s = i;
        return s*s;
    }	
}





