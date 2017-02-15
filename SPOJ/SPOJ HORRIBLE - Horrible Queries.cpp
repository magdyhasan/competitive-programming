#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

typedef long long ll;

ll T1[100500], T2[100500];

void update(ll T[], int idx, ll val){
	for (; idx<100500; idx += (idx & -idx)) T[idx] += val;
}

void updateR(int a, int b, int v){
	update(T1, a, v);
	update(T1, b + 1, -v);
	update(T2, a, ll(v)*ll(a - 1));
	update(T2, b + 1, -ll(v)*ll(b));
}

ll query(ll T[], int idx){
	ll sum = 0;
	for (; idx>0; idx -= (idx & -idx)) sum += T[idx];
	return sum;
}

ll query(int p){
	return query(T1, p) * p - query(T2, p);
}

ll queryR(int a, int b){
	return query(b) - query(a - 1);
}


int main(){
	freopen("uva.txt", "rt", stdin);
	int T;
	scanf("%d", &T);
	while (T--){
		memset(T1, 0, sizeof(T1));
		memset(T2, 0, sizeof(T2));
		int n, c;
		scanf("%d%d", &n, &c);
		while (c--){
			int t, q, p, v;	
			scanf("%d", &t);
			if (t == 0) {
				scanf("%d%d%d", &p, &q, &v);
				updateR(p, q, v);
			}
			else{
				scanf("%d%d", &p, &q);
				printf("%lld\n", queryR(p, q));
			}

		}
	}
}
