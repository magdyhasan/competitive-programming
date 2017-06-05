#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


char st[100];

int main(){
    freopen("uva.txt","rt",stdin);
	int n, w, t1, t2;
	double u, v;
	while (scanf("%d%d%lf%lf%d%d", &n, &w, &u, &v, &t1, &t2) == 6){
		vector<pair<double, int>> e;
		e.push_back({ t1, 0 });
		e.push_back({ t2, 0 });
		for (int i = 0; i < n; i++){
			int nu, ln, di;
			scanf("%s%d", st, &nu);
			for (int j = 0; j < nu; j++){
				scanf("%d%d", &ln, &di);
				if (st[0] == 'E') di = -di;
				e.push_back({di/u-(i+1)*w/v , 1 });
				e.push_back({(di+ln)/u-i*w/v , -1 });
			}
		}
		double ret = .0;
		sort(e.begin(), e.end());
		int in = 0;
		for(int i=0;i<e.size();i++){
			in += e[i].second;
			if (in == 0 && e[i].first >= t1 && e[i].first < t2)
				ret = max(ret, e[i + 1].first - e[i].first);	
		}
		printf("%.3lf\n", ret);
	}
}
