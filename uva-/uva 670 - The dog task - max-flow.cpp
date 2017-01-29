/*
maximum bipartite matching with max-flow
*/

#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;

int cap[215][215],d[215],prv[215];
int x[215], y[215], ans_x[215], ans_y[215], ans;
bool vis[215];
int  n, m, sink;

void max_matching(){
	while (true) { // dijsktra O(n^2) to find a path
		for (int i = 0; i <= sink; i++)
			d[i] = cap[0][i], prv[i] = 0, vis[i] = 0;
		vis[0] = 1;
		while (true) {
			int mx = 0, mxi;	
			for (int i = 0; i <= sink; i++)
				if (d[i] > mx && !vis[i])
					mx = d[mxi = i];
			if (mx == 0 || mxi == sink)
				break;
			vis[mxi] = 1;
			for (int i = 0; i <= sink; i++)
				if (min(cap[mxi][i], d[mxi]) > d[i])
					d[i] = min(cap[mxi][i], d[mxi]), prv[i] = mxi;
		}
		if (d[sink] == 0)
			break;
		int tsink = sink;
		while (tsink) {
			cap[prv[tsink]][tsink] -= d[sink];
			cap[tsink][prv[tsink]] += d[sink];
			tsink = prv[tsink];
		}
	}
	return;
}


int dist(int x1, int y1, int x2, int y2){ // ditance between 2 points
	int dx = x2 - x1;
	int dy = y2 - y1;
	return (dx*dx + dy*dy);
}



int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		memset(cap, 0, sizeof(cap));
		scanf("%d%d", &n, &m);
		sink = n + m; // add a sink
		for (int i = 0; i < n; i++) {
			scanf("%d%d", x + i, y + i);
			cap[0][i] = 1; // we can have only atmost one intersting point between 2 master points
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d", x + i + n, y + i + n);
			cap[i + n][sink] = 1; // we can have only atmost one intersting point between 2 master points

			for (int j = 1; j < n; j++) { // try the new intersting points between each 2 master points
				int master = dist(x[j], y[j], x[j - 1], y[j - 1]); // this the distance between two master points
				int dog = dist(x[j], y[j], x[i + n], y[i + n]) + dist(x[i + n], y[i + n], x[j - 1], y[j - 1]); // ditance of dog while visiting the i+n intersting point
				if (master*2 >= dog) // if dog can finish his distance in less than 2*distance of master
					cap[j][i+n] = 1; // then we can to point i+n between point j and j-1
			}
		}
		max_matching(); // find max matching
		ans = 0;
		for (int i = 0; i < n; i++) {
			ans_x[ans] = x[i]; // master point
			ans_y[ans++] = y[i];
			for (int j = 0; j < m && i != n - 1; j++)
				if (cap[j + n][i + 1]) // if dog can go to the j intersting point betwwen i,i-1 master point
					ans_x[ans] = x[j + n], ans_y[ans++] = y[j + n];
		}
		printf("%d\n", ans);
		for (int i = 0; i < ans - 1; i++)
			printf("%d %d ", ans_x[i], ans_y[i]);
		printf("%d %d\n", ans_x[ans - 1], ans_y[ans - 1]);
		if (tc)
			puts("");
	}
}
