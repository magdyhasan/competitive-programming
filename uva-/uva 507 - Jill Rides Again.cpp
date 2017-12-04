#include<bits/stdc++.h>
using namespace std;


const int maxn = 300500;
int a[maxn];	

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		int n; scanf("%d", &n);
		for (int i = 0; i+1 < n; i++) scanf("%d", a + i);
		int mxs = 0, l = 0, r = 0, curs = 0, curl = 0;
		for (int i = 0; i+1 < n; i++){
			curs += a[i];
			if (curs < 0) curs = 0, curl = i+1;
			else{
				if (curs > mxs || (curs == mxs && i - curl > r - l))
					mxs = curs, r = i, l = curl;
			}
		}
		if (mxs == 0) printf("Route %d has no nice parts\n", tc);
		else printf("The nicest part of route %d is between stops %d and %d\n", tc, l + 1, r + 2);
	}
}
