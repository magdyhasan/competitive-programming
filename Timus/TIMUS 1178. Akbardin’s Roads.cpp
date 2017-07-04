#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct po{
	ll x, y;
	int idx;
	bool operator < (const po &a) const { // this sort with > 
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
} pos[150500];

int main(){
    freopen("uva.txt","rt",stdin);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%lld%lld", &pos[i].x, &pos[i].y);
		pos[i].idx = i;
	}
	sort(pos, pos + n);
	for (int i = 0; i < n; i += 2){
		printf("%d %d\n", pos[i].idx+1, pos[i + 1].idx+1);
	}
}

