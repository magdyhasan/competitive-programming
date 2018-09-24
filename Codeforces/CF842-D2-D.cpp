/*
	
	hint: think about trie of bits

	hint2: notice that we don't need to change array after each query,
	we can just make query = x1^x2^...^xi
	because querying xor of all previous queries is like we made changes of previous querires

	now we can build all numbers in trie of bits

	now for querying, we want to make result as small as possible
	so iterating from maxbit to 0 bit
	to make result small we want to go in the direction of the opposite bit of our current bit
	but we can't go in direction that already have all numbers
	so before going into subtree we need to check if current subtree has all numbers on it,
	if so go on other direction.

*/
#include <bits/stdc++.h>
using namespace std;


struct node{
	int nxt[2];
	int cnt;
	node(){
		nxt[0] = nxt[1] = -1;
		cnt = 0;
	}
} tr[6010000];

int len;

void add(int id, int nu, int pos){
	if (pos < 0){
		tr[id].cnt = 1;
		return;
	}
	int nxt = (nu >> pos) & 1;
	if (tr[id].nxt[nxt] == -1)
		tr[id].nxt[nxt] = ++len;
	add(tr[id].nxt[nxt], nu, pos - 1);
	tr[id].cnt = 0;
	for (int i = 0; i < 2; i++){
		if (tr[id].nxt[i] != -1)
			tr[id].cnt += tr[tr[id].nxt[i]].cnt;
	}
}


int get(int id, int nu, int pos){
	if (pos < 0) return 0;
	int nxt = (nu >> pos) & 1;
	if (tr[tr[id].nxt[nxt]].cnt == (1 << pos))
		nxt = 1 - nxt;
	return (((nxt ^ ((nu >> pos) & 1)) << pos) | get(tr[id].nxt[nxt], nu, pos-1));
}

int main(){
	freopen("uva.txt", "rt", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	len = 0;
	for (int i = 0; i < n; i++){
		int t; scanf("%d", &t);
		add(0, t, 20);
	}
	int x = 0;
	while (m--){
		int t; scanf("%d", &t);
		x ^= t;
		printf("%d\n", get(0, x, 20));
	}
}

