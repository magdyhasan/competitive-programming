/*
Just test if two trees are Isomorphism
We just need to find center of tree and then find CanoincalForm of the tree
Now we can just compare if the two trees equal
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 300500;



#define all(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)



string getNodeCanoincalForm(int v, vector< vector<string> > &subCan)	// we could use hashing for a better performance
{
	string nodeRep = "(";
	sort(all(subCan[v]));
	rep(i, subCan[v])
		nodeRep += subCan[v][i];
	nodeRep += ")";

	return nodeRep;
}


string treeCanoincalForm(vector< vector<int> > &adjLst)	// assumes tree not forest
{
	int n = adjLst.size();

	// Prepare level one nodes: the leaves
	queue<int> LeafNodes;
	vector<int> deg(n, -1);
	int remNodes = n;

	rep(i, adjLst) {
		if (sz(adjLst[i]) <= 1)
			LeafNodes.push(i);
		else
			deg[i] = sz(adjLst[i]);
	}

	vector< vector<string> > subCan(n);

	while (remNodes > 2)	// bfs-like
	{
		int sz = sz(LeafNodes);
		while (sz--)	// level by level
		{
			int v = LeafNodes.front();			LeafNodes.pop();

			string nodeRep = getNodeCanoincalForm(v, subCan);

			rep(j, adjLst[v]) {
				int to = adjLst[v][j];
				subCan[to].push_back(nodeRep);
				if (--deg[to] == 1)
					LeafNodes.push(to);
			}
			--remNodes;
		}
	}

	// what remains are tree centers
	int v1 = LeafNodes.front();			LeafNodes.pop();
	int v2 = LeafNodes.empty() ? -1 : LeafNodes.front();

	string str1 = getNodeCanoincalForm(v1, subCan);
	string str2 = v2 == -1 ? "" : getNodeCanoincalForm(v2, subCan);

	if (v2 == -1)	// only 1 node
		return str1;

	// 2 nodes. try 2nd as child of first and reverse
	subCan[v1].push_back(str2);
	subCan[v2].push_back(str1);

	return min(getNodeCanoincalForm(v1, subCan), getNodeCanoincalForm(v2, subCan));
}






int main(){
	freopen("test.in", "r", stdin);
	int tc; scanf("%d", &tc);
	while (tc--){
		int n; scanf("%d", &n);
		vector<vector<int>> adj(n), adj2(n);
		for (int i = 0; i < n - 1; i++) {
			int u, v; scanf("%d%d", &u, &v);
			u--;	v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v; scanf("%d%d", &u, &v);
			u--;	v--;
			adj2[u].push_back(v);
			adj2[v].push_back(u);
		}
		string t1 = treeCanoincalForm(adj), t2 = treeCanoincalForm(adj2);
		puts(t1 == t2 ? "YES" : "NO");
	}
}