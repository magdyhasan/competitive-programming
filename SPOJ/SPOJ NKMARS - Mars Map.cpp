/*
	standard sweep line to computer area of union of rectangles
*/
#include <bits/stdc++.h>
using namespace std;
 
#define all(v)        ((v).begin()), ((v).end())
#define sz(v)       ((int)((v).size()))
#define clr(v, d)     memset(v, d, sizeof(v))
#define repi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define repd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define repa(v)       repi(i, 0, sz(v)) repi(j, 0, sz(v[i]))
#define rep(i, v)     repi(i, 0, sz(v))
#define lp(i, cnt)      repi(i, 0, cnt)
#define lpi(i, s, cnt)    repi(i, s, cnt)
#define P(x)        cout<<#x<<" = { "<<x<<" }\n"
#define pb          push_back
#define MP          make_pair
 
const double EPS = 1e-7;
 
// Original code source: https://olympiad.cs.uct.ac.za/presentations/camp1_2009/linesweep_handout.pdf
 
struct event {
	int ind, type;
	event() {}
	event(int ind, int type) : ind(ind), type(type) {}
};
struct point { double x, y; };
 
const int RECT_MAX = 10000 + 9;
const int ENTRY = 0, EXIT = 1;
point rects[RECT_MAX][2];
bool inActiveSet[RECT_MAX];
event events_v[2 * RECT_MAX], events_h[2 * RECT_MAX];
 
bool cmpX(event a, event b) {
	return rects[a.ind][a.type].x < rects[b.ind][b.type].x;
}
bool cmpY(event a, event b) {
	return rects[a.ind][a.type].y < rects[b.ind][b.type].y;
}
 
 
 
int main() {
	int n, tc = 0;
	while (scanf("%d", &n) == 1){
		if (!n) break;
		double area = 0;
		memset(inActiveSet, 0, sizeof(inActiveSet));
		int eventsCnt = 0;  // # rectangles, edges
		for (int i = 0; i < n; ++i) {  // assume rectangle 2 points are ordered
			double cx, cy, cr, cc;
			scanf("%lf%lf%lf%lf", &cx, &cy, &cr, &cc);
			rects[i][0].x = cx; rects[i][0].y = cy;
			rects[i][1].x = cr; rects[i][1].y = cc;
			events_v[eventsCnt] = event(i, ENTRY), events_v[eventsCnt + 1] = event(i, EXIT);
			events_h[eventsCnt] = event(i, ENTRY), events_h[eventsCnt + 1] = event(i, EXIT);
			eventsCnt += 2;
		}
		sort(events_v, events_v + eventsCnt, cmpX);
		sort(events_h, events_h + eventsCnt, cmpY);
 
		inActiveSet[events_v[0].ind] = 1;
		for (int v = 1; v < eventsCnt; ++v) {  // Vertical sweep
			event c = events_v[v], p = events_v[v - 1];
			int cnt = 0, first_rect;
			double delta_x, delta_y;
 
			if ((delta_x = rects[c.ind][c.type].x - rects[p.ind][p.type].x) < 0)
				continue;
 
			for (int h = 0; h < eventsCnt; ++h)
				if (inActiveSet[events_h[h].ind]) {  // Horizontal sweep
				if (events_h[h].type == ENTRY) {
					if (cnt++ == 0)
						first_rect = h;
				}
				else if (--cnt == 0) {
					delta_y = rects[events_h[h].ind][EXIT].y - rects[events_h[first_rect].ind][ENTRY].y;
					area += delta_x * delta_y;
				}
				}
			inActiveSet[c.ind] = (c.type == ENTRY);
		}
		printf("%d\n", int(area));
	}
	return 0;
} 
