/*
	imagine the sun at (0,0)
	to find first position of first planet
	we first find the angle(theta) this planet makes with sun after T time
	given angle and planet is rotating in circluar manner, we easily find planet (x,y)
	x = r * cos(theta), y = r * sin(theta), where r is the radius of sun

	now repeat this process for each new planet, but with previous center as our last (x,y)
*/
#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)

int main(){
    freopen("uva.txt","rt",stdin);
	int n, T; 
	while (scanf("%d%d", &n, &T) == 2){
		int r, t;
		double x = 0, y = 0;
		while (n--){
			scanf("%d%d", &r, &t);
			double theta = 2.*PI*T / double(t);
			x += double(r)*cos(theta);
			y += double(r)*sin(theta);
			printf("%.4lf%s", sqrt(x*x + y*y),(n == 0) ?"\n":" ");
		}
	}
}
