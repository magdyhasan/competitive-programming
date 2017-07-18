#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int n; 
	while (scanf("%d", &n)){
		if (!n) break;
		int mx = -1, mxi;
		for (int i = 0; i < n; i++){
			int tw, th; scanf("%d%d", &tw, &th);
			double w = tw, h = th;
			vector<double> t;
			t.push_back(min(w / 4., h));
			t.push_back(min(w, h / 4.));
			t.push_back(min(w, h) / 2.);
			for (int j = 0; j < 3; j++) if (t[j] > mx)
				mx = t[j], mxi = i + 1;
		}
		printf("%d\n", mxi);
	}
}
