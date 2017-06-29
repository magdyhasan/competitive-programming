#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



#include<complex>
const double PI = acos(-1.0);

typedef complex<double> point;

const double EPS = 1e-8;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define same(p1,p2)             (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define dp(a,b)                 ( (conj(a)*(b)).real() )	// a*b cos(T), if zero -> prep
#define cp(a,b)                 ( (conj(a)*(b)).imag() )	// a*b sin(T), if zero -> parllel
#define length(a)               (hypot((a).imag(), (a).real()))
#define normalize(a)            (a)/length(a)
//#define polar(r,ang)            ((r)*exp(point(0,ang)))  ==> Already added in c++11
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)  (rotateO(vec(about,p),ang)+about)
#define reflectO(v,m)  (conj((v)/(m))*(m))


double polygonArea(vector<point>& points) {
	long double a = 0;
	for (int i = 0; i<points.size(); i++)  a += cp(points[i], points[(i + 1) % points.size()]);
	return fabs(a / 2.0);    // If area > 0 then points ordered ccw
}

class BestTriangulation {
public:
	double maxArea(vector <string> vertices);
};

double BestTriangulation::maxArea(vector <string> vertices) {
	double ret;
	vector<point> poi;
	for (auto st : vertices){
		int a, b;
		istringstream(st) >> a >> b;
		poi.push_back({ 1.*a, 1.*b });
	}
	int n = poi.size();
	ret = 0.;
	for (int i = 0; i<n; i++) for (int j = 0; j<n; j++) for (int k = 0; k<n; k++) if (i != j && j != k){
		vector<int> tt = { i, j, k };
		sort(tt.begin(), tt.end());
		vector<point> t = { poi[tt[0]], poi[tt[1]], poi[tt[2]] };
		ret = max(ret, polygonArea(t));
	}
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	BestTriangulation *obj;
	double answer;
	obj = new BestTriangulation();
	clock_t startTime = clock();
	answer = obj->maxArea(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	}
	else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	}
	else if (hasAnswer) {
		cout << "Match :-)" << endl;
	}
	else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <string> p0;
	double p1;

	{
		// ----- test 0 -----
		string t0[] = { "1 1", "2 3", "3 2" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1.5;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = { "1 1", "1 2", "3 3", "2 1" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 1.5;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = { "1 2", "1 3", "2 4", "3 4", "4 3", "4 2", "3 1", "2 1" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 3.0;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = { "6 2", "2 1", "1 2", "1 4", "2 6", "5 6", "6 5" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 10.0;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		string t0[] = { "10000 3469", "9963 712", "9957 634", "9834 271", "9700 165", "9516 46", "8836 4", "1332 57", "229 628", "171 749", "52 1269", "30 1412", "7 4937", "35 8676", "121 9917", "2247 9960", "3581 9986", "6759 9995", "9486 9998", "9888 9890", "9914 9318", "9957 8206", "9998 6402" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 4.8292483E7;
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	}
	else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
