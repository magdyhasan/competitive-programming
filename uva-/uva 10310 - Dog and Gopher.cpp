#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<math.h>
using namespace std;

double dist(double x1, double y1, double x2, double y2){
	double dx = x2 - x1;
	double dy = y2 - y1;
	dx = dx*dx + dy*dy;
	return sqrt(dx);
}

int main(){
    freopen("uva.txt","rt",stdin);
	double gx, gy, dx, dy, x, y;
	int n;
	while (scanf("%d", &n) != EOF) {
		scanf("%lf%lf%lf%lf", &gx, &gy, &dx, &dy);
		bool out = false;
		while (n--) {
			scanf("%lf%lf", &x, &y);
			if (!out && dist(gx, gy, x, y) * 2 <= dist(dx, dy, x, y))
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", x, y), out = 1;
		}
		if (!out)
			printf("The gopher cannot escape.\n");
	}
}
