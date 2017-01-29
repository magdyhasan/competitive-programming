#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<utility>
#include<algorithm>
#include<functional>
using namespace std;

int n, m;
pair<int, bool> cut[2005];

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &n, &m);
		int cut_count = 0; // all cuts (x,y)
		for (int i = 0; i < n - 1; i++) // get all x's cuts
			scanf("%d", &cut[cut_count].first), cut[cut_count++].second = 0; 

		for (int i = 0; i < m - 1; i++) // get all y's cuts
			scanf("%d", &cut[cut_count].first), cut[cut_count++].second = 1;

		sort(cut, cut + cut_count, greater< pair<int, int> >()); // sort all cuts  decending

		int hor_cuts = 1, ver_cuts = 1, total = 0;
		for (int i = 0; i < cut_count; i++)
			if (cut[i].second == 0) // if this x cut
				total += cut[i].first * ver_cuts, hor_cuts++; // get cost of cutting all y's edges and increase number of horizntal cuts
			else // if this y cut
				total += cut[i].first * hor_cuts, ver_cuts++; // get cost of cutting all x's edges and increase number of vertical cuts
		printf("%d\n", total);
	}
}
