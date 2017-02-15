#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<unordered_map>
#include<queue>
using namespace std;


int encode(int a, int b, int c, int d){
	return a * 531441 + b * 6561 + c * 81 + d;
}

int po[4];

void decode(int x){
	for (int i = 0; i < 4; i++)
		po[i] = (x % 81), x /= 81;
}


int dx[] = { 1, -1, 0, 0 },
	dy[] = { 0, 0, 1, -1 };

inline bool isValid(int i, int j){
	return (i > 0 && j > 0 && i <= 8 && j <= 8);
}

int AddEncode(vector<int> ppo, unordered_map<int, int> &m,int cc, queue<int> &q){
	sort(ppo.begin(), ppo.end());
	int v = ppo[0] * 531441 + ppo[1] * 6561 + ppo[2] * 81 + ppo[3];
	if (m.find(v) == m.end() || m[v] > cc)
		m[v] = cc, q.push(v);
	return v;
}


unordered_map<int, int> di, di2;

int te[4][2];

void BFS1(){
	queue<int> q;
	int v = AddEncode({ te[0][0] * 9 + te[0][1], te[1][0] * 9 + te[1][1], te[2][0] * 9 + te[2][1], te[3][0] * 9 + te[0][1] },
		di, 0, q);
	while (!q.empty()){
		int u = q.front();	 q.pop();
		int co = di[u];
		if (di[u] == 4) continue;
		decode(u);
		for (int c = 0; c < 4; c++){
			int i = po[c] / 9, j = po[c] % 9, tpoc = po[c];
			for (int k = 0; k < 4; k++){
				int ni = i + dx[k], nj = j + dy[k];
				if (!isValid(ni, nj)) continue;
				bool emp = true;
				for (int s = 0; s < 4; s++) if (ni * 9 + nj == po[s]) emp = false;
				if (emp){
					po[c] = ni * 9 + nj;
					AddEncode({ po[0], po[1], po[2], po[3] },di,co+1, q);
					po[c] = tpoc;
				}
				else{
					int ni2 = i + dx[k] * 2, nj2 = j + dy[k] * 2;
					if (!isValid(ni2, nj2)) continue;
					bool emp2 = true;
					for (int s = 0; s < 4; s++) if (ni2 * 9 + nj2 == po[s]) emp2 = false;
					if (emp2){
						po[c] = ni2 * 9 + nj2;
						AddEncode({ po[0], po[1], po[2], po[3] }, di, co + 1, q);
						po[c] = tpoc;
					}
				}
			}
		}
	}
}


bool BFS2(){
	queue<int> q;
	int v = AddEncode({ te[0][0] * 9 + te[0][1], te[1][0] * 9 + te[1][1], te[2][0] * 9 + te[2][1], te[3][0] * 9 + te[0][1] }, di2, 0, q);
	while (!q.empty()){
		int u = q.front();	 q.pop();
		int co = di2[u];
		if (di.find(u) != di.end())return true;
		if (di2[u] == 4) continue;
		decode(u);
		for (int c = 0; c < 4; c++){
			int i = po[c] / 9, j = po[c] % 9, tpoc = po[c];
			for (int k = 0; k < 4; k++){
				int ni = i + dx[k], nj = j + dy[k];
				if (!isValid(ni, nj)) continue;
				bool emp = true;
				for (int s = 0; s < 4; s++) if (ni * 9 + nj == po[s]) emp = false;
				if (emp){
					po[c] = ni * 9 + nj;
					AddEncode({ po[0], po[1], po[2], po[3] }, di2, co + 1, q);
					po[c] = tpoc;
				}
				else{
					int ni2 = i + dx[k] * 2, nj2 = j + dy[k] * 2;
					if (!isValid(ni2, nj2)) continue;
					bool emp2 = true;
					for (int s = 0; s < 4; s++) if (ni2 * 9 + nj2 == po[s]) emp2 = false;
					if (emp2){
						po[c] = ni2 * 9 + nj2;
						AddEncode({ po[0], po[1], po[2], po[3] }, di2, co + 1, q);
						po[c] = tpoc;
					}
				}
			}
		}
	}
	return false;
}



int main(){
    freopen("uva.txt","rt",stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		for (int i = 0; i < 4; i++) scanf("%d%d", &te[i][0], &te[i][1]);
		di.clear();
		di2.clear();
		//di.reserve(100600);
		//di2.reserve(100600);
		BFS1();
		for (int i = 0; i < 4; i++) scanf("%d%d", &te[i][0], &te[i][1]);
		if (BFS2()) puts("YES");
		else puts("NO");
	}
}
