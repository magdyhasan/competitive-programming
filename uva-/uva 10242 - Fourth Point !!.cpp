#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

int main(){
	double x1, y1, x2, y2, x3, y3, x4, y4, x, y;
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4) != EOF) {
		if (x1 == x3 && y1 == y3) { // if-else to deterimine which vertex is the common for the 2 sides.
			x = x2 + x4 - x3;
			y = y2 + y4 - y3;
		}
		else if (x1 == x4 && y1 == y4) {
			x = x2 + x3 - x4;
			y = y2 + y3 - y4;
		}
		else if (x2 == x3 && y2 == y3) {
			x = x1 + x4 - x3;
			y = y1 + y4 - y3;
		}
		else {
			x = x1 + x3 - x4;
			y = y1 + y3 - y4;
		}
		printf("%.3lf %.3lf\n", x, y);
	}
}
