#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 500500;

bool in[maxn];
int a[maxn], lastIdx[maxn], nxt[maxn];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		int n, k, p;
		scanf("%d%d%d", &n, &k, &p);
		priority_queue<pair<int, int>> pq; 
		pair<int, int> u;
		for (int i = 0; i <= n; i++) lastIdx[i] = p + 2, in[i] = 0;
		for (int i = 0; i < p; i++) scanf("%d", a + i);
		for (int i = p - 1; i >= 0; i--)
			nxt[i] = lastIdx[a[i]], lastIdx[a[i]] = i;
		int mov = 0, cur = 0;
		for (int i = 0; i < p; i++){
			if (in[a[i]]);
			else if (cur < k)
				cur++, mov++;
			else{
				u = pq.top(); pq.pop();
				in[u.second] = 0;
				mov++;
			}
			in[a[i]] = 1;
			pq.push({ nxt[i], a[i] });
		}
		printf("%d\n", mov);
	}
}
