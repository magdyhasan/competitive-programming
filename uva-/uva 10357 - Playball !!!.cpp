/*
	problems gives equations to z,x,y in respect to time(t)
	player can catch ball if he can reach it's  location when z<=0 before it
	and he can't catch it while z > 0

	use BS to find t where at^2 + bt + c <= 0
	if at t x(t) or y(t) < then output foul
	else 
	try to find player with speed*t>= distance(player,{x(t),y(t))
	if such output caught
	else safe
*/
#include<bits/stdc++.h>
using namespace std;

int x[128], y[128], v[128];
typedef long long ll;

int a[7];
ll sqr(ll x){
	return x*x;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int np, nb;
	scanf("PLAYERS=%d", &np);
	for (int i = 0; i < np; i++){
		scanf("%d%d%d", x + i, y + i, v + i);
	}
	scanf("\nBALLS=%d", &nb);
	for (int tb = 1; tb <= nb; tb++){
		for (int j = 0; j < 7; j++) scanf("%d", a + j);
		ll l = 1, r = 123456789, t = 0;
		while (l <= r){
			ll mi = (l + r) >> 1;
			if (a[0]*1LL * mi*mi + a[1] * mi + a[2] < 1) t = mi, r = mi - 1;
			else l = mi + 1;
		}
		int xt = a[3] * t + a[4], yt = a[5] * t + a[6];
		bool cat = 0;
		for (int i = 0; i < np && xt > 0 && yt > 0; i++){
			if (sqr(x[i] - xt) + sqr(y[i] - yt) <= v[i] * 1LL * v[i] * t*t){
				cat = 1;
				break;
			}
		}
		printf("Ball %d was %s at (%d,%d)\n", tb, 
			(cat ? "caught" : ((xt < 0 || yt < 0)?"foul":"safe")), xt, yt);
	}
}
