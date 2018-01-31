/*
	draw the 3 circles and make triangle of 3 centers of the circles

	we can see lengths of this triangles is (r1+r2,r2+r3,r3+r1)
	
	given triangle sides we can find it's angles from by cosine rule
	where c = acos((a*a + c*c - b*b) / (2.*a*c))

	now notice area of triangle is required area plus area of sector of each circle with one of the triangle area

	we can find area of sector of circle from .5*r*r*thetha

	so just subtract area of sector of all 3 circles
*/
#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	while (T--){
		double r1, r2, r3;
		scanf("%lf%lf%lf", &r1, &r2, &r3);
		double a = r1 + r2, b = r2 + r3, c = r3 + r1;
		double S = (a + b + c) / 2.;
		double area = sqrt(S*(S - a)*(S - b)*(S - c));
		area -= .5 * r1 * r1 * acos((a*a + c*c - b*b) / (2.*a*c));
		area -= .5 * r2 * r2 * acos((a*a + b*b - c*c) / (2.*a*b));
		area -= .5 * r3 * r3 * acos((b*b + c*c - a*a) / (2.*b*c));
		printf("%.6lf\n", round(area * 1000000) / 1000000.);
	}
}
