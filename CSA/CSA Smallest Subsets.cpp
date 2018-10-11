/*
first, let's consider the problem is only on positive integers
this problem can be solved by keeping a heap of current minimum 2 values as follow:
we keep the current index we took last, now we have 2 options:
- we add the next elment and keep the current element
- we add the next element and remove the current elemnt
one can see that this 2-choices consider all minimumm values,
and heap size is around 2*k elments to get the k elments
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 300500;

int n, m;

int a[maxn];

int main(){
	ll sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		if (a[i] < 0){
			sum += a[i];
			a[i] *= -1;
		}
	}
	sort(a + 1, a + n + 1);
	priority_queue < pair<ll, int> > pq;
	pq.push({ 0, 0 });
	while (m--){
		ll x = -pq.top().first, i = pq.top().second;
		pq.pop();
		printf("%lld\n", sum + x);
		if (i > 0 && i < n)
			pq.push({ -x - a[i + 1] + a[i], i + 1 });
		if (i < n)
			pq.push({ -x - a[i + 1], i + 1 });
	}
	return 0;
}