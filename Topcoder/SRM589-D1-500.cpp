/*
  main idea is that we will always have 2 colors of gears running in same direction(same side) and other one in opposite 
  because we don't have to remove any gears from the third color whether it meshing with the other 2 colors or not
  
  so now we can try all possible ways to put 2 colors in one side
  
  now when 2 colors runs in the same directions, it's possible some of the them mesh together
  and we want to choose maximum number of gears from this 2 colors such that no gear from them mesh with another one
  this just maximum independent set
  
  so now we have one color on each side, and each color can't have gears meshing 
  so it's a bipartite graph
  so to find minimum number of gears to remove we need min vertex cover which is just maximum matching 
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


class GearsDiv1 {
public:
	int getmin(string c, vector <string> g);
};

vector<vector<int>> adj;
vector<int> vis, colAssign;

bool canMatch(int i){ // O(E)
	for (int j = 0; j<adj[i].size(); ++j) if (adj[i][j] && !vis[j]) {
		vis[j] = 1;
		if (colAssign[j] < 0 || canMatch(colAssign[j])) {
			colAssign[j] = i;
			return true;
		}
	}
	return false;
}

int n;
string c;
vector <string> g;

int solve(char a, char b){
    adj = vector<vector<int>>(n,vector<int>(n,0));
    colAssign = vector<int>(n, -1);
    for(int i=0;i<n;i++) if(c[i] == a){
        for(int j=0;j<n;j++) if(c[j] == b){
         	if(g[i][j] == 'Y')
                adj[i][j] = 1;
        }
    }
    int maxFlow = 0;
    for (int i = 0; i<n; ++i) {
        vis = vector<int>(n, 0);
        if (canMatch(i))
            maxFlow++;
	}
    return maxFlow;
}

int GearsDiv1::getmin(string _c, vector <string> _g) {
    g = _g;
    c = _c;
    n = c.size();
    return min(solve('R','G'), min(solve('R','B'),solve('G','B')));
}



