#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

char st[105];
int pos[105];

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		ll idx;
		scanf("%s%lld", st, &idx);
		int n = strlen(st);
		idx--;
		pos[1] = 1;
		for (int i = 2; i <= n; i++){
			ll numberOfWays = 1LL;
			pos[i] = -1;
			for (ll j = i + 1; j <= n; j++) {
				numberOfWays *= j;
				if (numberOfWays > idx){
					pos[i] = 1;
					break;
				}
			}
			if (pos[i] == -1){
				pos[i] = idx / numberOfWays + 1;
				idx -= (pos[i] - 1)*numberOfWays;
			}
		}
		string ret = "";
		ret += st[0];
		for (int i = 2; i <= n; i++)
			ret.insert(pos[i] - 1, 1, st[i - 1]);
		printf("%s\n", ret.c_str());
	}
}
