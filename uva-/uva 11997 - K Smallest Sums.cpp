#include<bits/stdc++.h>
using namespace std;

int k;
int a[751][751];
int cur[751];



int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d", &k) == 1){
		for (int i = 0; i < k; i++){
			for (int j = 0; j < k; j++)
				scanf("%d", a[i] + j);
			sort(a[i], a[i] + k);
		}
		for (int i = 0; i < k; i++) cur[i] = a[0][i];
		for (int i = 1; i < k; i++){
			priority_queue<int> pq;
			for (int j = 0; j < k; j++) pq.push(cur[j] + a[i][0]);
			for (int j = 0; j < k; j++){
				for (int p = 1; p < k; p++)
					if (cur[j] + a[i][p] < pq.top()){
						pq.pop();
						pq.push(cur[j] + a[i][p]);
					}
					else
						break;
			}
			for (int j = k - 1; j >= 0; j--){
				cur[j] = pq.top();
				pq.pop();
			}
		}
		for (int i = 0; i < k; i++) 
			printf("%d%s", cur[i], (i + 1 == k) ? "\n" : " ");
	}
}
