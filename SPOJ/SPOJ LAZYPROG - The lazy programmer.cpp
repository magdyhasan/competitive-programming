#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
	int deadLine, time, cost;
	bool operator < (Node &a) {
		return deadLine < a.deadLine;
	}
} job[100500];

int main(){
    freopen("uva.txt","rt",stdin);
	int T;	 scanf("%d", &T);
	while (T--){
		int n;	scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d%d%d", &job[i].cost, &job[i].time, &job[i].deadLine);
		sort(job, job + n);
		priority_queue<pair<int, int>> lowC;
		int curTime = 0;
		double ret = 0;
		for (int i = 0; i < n; i++){
			curTime += job[i].time;
			lowC.push({ job[i].cost, job[i].time });
			if (curTime > job[i].deadLine){
				while (true){
					pair<int, int> lowest = lowC.top();	 lowC.pop();
					if (curTime - lowest.second <= job[i].deadLine){
						int need = curTime - job[i].deadLine;
						double needC = need / double(lowest.first);
						ret += needC;
						lowest.second -= need;
						curTime -= need;
						lowC.push(lowest);
						break;
					}
					else{
						curTime -= lowest.second;
						ret += lowest.second / double(lowest.first);
					}
				}
			}
		}
		printf("%.2lf\n", ret);
	}
}
