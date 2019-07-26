/*
 * if for each row/column we know which type it has now and when it was updatedwe can solve this easily
 * if we have query for row, then we check it's type
 * and find all others cols that has been updated after this row update and this are the columns that will affect our answer
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 600500;


int bi[4][600500];

void update(int bit[], int idx, int val){
	for (int x = idx; x < maxn; x = (x | (x + 1)))
		bit[x] += val;
}

int query(int bit[], int idx){
	int ret = 0;
	for (int x = idx; x >= 0; x = ((x&(x + 1)) - 1))
		ret += bit[x];
	return ret;
}

struct no{
	int ty,st;
} rc[2][maxn];

char s[30050];


int main() {
	int n; scanf("%d",&n);
	int st = 2;
	update(bi[0],st,n);
	update(bi[2],st,n);
	for(int i=1;i<=n;i++)
		rc[0][i].st = rc[1][i].st = st, rc[0][i].ty = rc[1][i].ty = 0;
	int q; scanf("%d",&q);;
	while(q--){
		++st;
		scanf("%s",s);
		if(s[3] == 'Q'){ // == "RowQuery" || s == "ColQuery"){
			int ir = (s[0] == 'C'), id;
			scanf("%d",&id);
			if(rc[ir][id].ty == 0){
				int tos = (ir == 0) ? 3:1;
				printf("%d\n",n - (query(bi[tos], maxn-5)-query(bi[tos], rc[ir][id].st-1)));
			}else{
				int tos = (ir == 0) ? 2:0;
				printf("%d\n", (query(bi[tos], maxn-5)-query(bi[tos], rc[ir][id].st-1)));
			}
		}else{
			int x,id;
			scanf("%d%d",&id,&x);
			int ir = (s[0] == 'C');
			int tos = (ir == 0) ? (rc[ir][id].ty == 0 ? 0:1):(rc[ir][id].ty == 0 ? 2:3);
			update(bi[tos], rc[ir][id].st, -1);
			rc[ir][id].st = st;
			rc[ir][id].ty = x;
			tos = (ir == 0) ? (x == 0 ? 0:1):(x == 0 ? 2:3);
			update(bi[tos], rc[ir][id].st, 1);
		}
	}
	return 0;
}
