#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<set>
#include<vector>
using namespace std;

double x[4], y[4];
set < pair<double,double> > st;
set < pair<double, double> >::iterator stit;

int main(){
	freopen("uva.txt", "r", stdin);
	double ax, ay, bx, by, cx, cy;
	while (scanf("%lf%lf", &x[0], &y[0]) != EOF){
		for (int i = 1; i < 4; i++) scanf("%lf%lf", &x[i], &y[i]);
		st.clear();
		for (int i = 0; i < 4; i++){
			if (st.find({ x[i], y[i] }) != st.end()){
				st.erase({ x[i], y[i] });
				cx = x[i], cy = y[i];
			}
			else
				st.insert({ x[i], y[i] });
		}
		stit = st.begin();
		ax = stit->first, ay = stit->second; 
		stit++;
		bx = stit->first, by = stit->second;
		printf("%.3lf %.3lf\n", ax + bx - cx, ay + by - cy);
	}
}
