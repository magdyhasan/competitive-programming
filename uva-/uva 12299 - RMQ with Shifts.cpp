#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<sstream>
using namespace std;

const int maxn = 300500;

int segT[maxn * 8], a[maxn];
int n, q;
	
int query(int x, int y, int idx = 1, int l = 1, int r = n){
	if (r < x || l > y) return 123456789;
	if (x <= l && r <= y) return segT[idx];
	int mid = (l + r) / 2, lidx = idx << 1;
	return min(query(x, y, lidx, l, mid), query(x, y, lidx | 1, mid + 1, r));
}

void update(int x, int y, int idx = 1, int l = 1, int r = n){
	if (l == r){
		a[l] = y;
		segT[idx] = y;
		return;
	}
	int mid = (l + r) / 2, lidx = idx << 1;
	if (x <= mid) update(x, y, lidx, l, mid);
	else update(x, y, lidx | 1, mid + 1, r);
	segT[idx] = min(segT[lidx], segT[lidx | 1]);
}

char li[1005];

int main(){
    freopen("uva.txt","rt",stdin);
	scanf("%d%d", &n, &q);
	for (int i = 0; i < 8 * n; i++) segT[i] = 123456789;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for(int i=1;i<=n;i++) 
		update(i, a[i]);
	gets(li);
	while (q--){
		gets(li);
		if (li[0] == 'q'){
			int l, r;
			sscanf(li, "query(%d,%d)", &l, &r);
			printf("%d\n", query(l, r));
		}
		else{
			int  t = 0, g = 0, cnt = 0, arr[100];
			for (int i = 6; li[i]; i++){
				if (isdigit(li[i])) t = t * 10 + (li[i] - '0'), g = 1;
				else{
					if (g) arr[cnt++] = t;
					g = 0, t = 0;
				}
			}
			if (cnt < 2) continue;
			t = a[arr[0]];
			for (int i = 0; i + 1 < cnt; i++) update(arr[i], a[arr[i + 1]]);
			update(arr[cnt - 1], t);
		}
	}
}
