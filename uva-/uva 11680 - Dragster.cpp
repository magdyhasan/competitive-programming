/*
	find match that doesn't affect any other
	computer probabilty as described in problem
	find probability of 1 winning
*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, double> pid;

double pr[305][305];
int fc[1024], sc[1024];
int in[1024];
int n;

vector<pid> rec(int idx){
	if (idx <= n) return{ { idx, 1. } };
	vector<pid> l = rec(fc[idx]);
	vector<pid> r = rec(sc[idx]);
	vector<pid> ret;
	for (int i = 0; i < l.size(); i++) {
		double pi = 0.;
		for (int j = 0; j < r.size(); j++){
			pi += l[i].second * r[j].second * pr[l[i].first][r[j].first];
		}
		ret.push_back({ l[i].first, pi });
	}
	for (int i = 0; i < r.size(); i++) {
		double pi = 0.;
		for (int j = 0; j < l.size(); j++){
			pi += r[i].second * l[j].second * pr[r[i].first][l[j].first];
		}
		ret.push_back({ r[i].first, pi });
	}
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d", &n), n){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				scanf("%lf", pr[i] + j);
			}
		}
		memset(in, 0, sizeof in);
		for (int i = n+1; i < n*2; i++){
			scanf("%d %d", fc + i, sc + i);
			in[fc[i]] ++;
			in[sc[i]] ++;
		}
		vector<pid> ret;
		for (int i = 1; i < 2 * n; i++)if (in[i] == 0){
			ret = rec(i);
			break;
		}
		for (auto i : ret) if (i.first == 1)
			printf("%.6lf\n", i.second);
	}
}
