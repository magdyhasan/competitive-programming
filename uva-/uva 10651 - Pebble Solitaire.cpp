#include<bits/stdc++.h>
using namespace std;

bool vis[1 << 12];

inline int countbit(int n){ 
	return (n == 0) ? 0 : (1 + countbit(n&(n - 1))); 
}


char st[128];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		scanf("%s", st);
		int msk = 0, ret = 12345678;
		for (int i = 11; i >= 0; i--) if (st[i] == 'o')
			msk |= (1 << i);
		memset(vis, 0, sizeof(vis));
		queue<int> q; q.push(msk);
		while (!q.empty()){
			msk = q.front(); q.pop();
			ret = min(ret, countbit(msk));
			for (int i = 11; i > 1; i--){
				int a = i, b = i - 1, c = i - 2, nmsk;
				if (!(msk&(1 << a)) && (msk&(1 << b)) && (msk&(1 << c))){
					nmsk = msk;
					nmsk |= (1 << a);
					nmsk &= ~(1 << b);
					nmsk &= ~(1 << c);
					if (!vis[nmsk])
						vis[nmsk] = 1, q.push(nmsk);
				}
				if ((msk&(1 << a)) && (msk&(1 << b)) && !(msk&(1 << c))){
					nmsk = msk;
					nmsk |= (1 << c);
					nmsk &= ~(1 << a);
					nmsk &= ~(1 << b);
					if (!vis[nmsk])
						vis[nmsk] = 1, q.push(nmsk);
				}
			}
		}
		printf("%d\n", ret);
	}
}
