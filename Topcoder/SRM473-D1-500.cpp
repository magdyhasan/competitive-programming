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

typedef long long ll;

int po[1000500];

class RightTriangle {
public:
	long long triangleCount(int places, int points, int _a, int _b, int _c) {
		if (places & 1) return 0;
		for (int i = 0; i < 1000500; i++) po[i] = 0;
		ll a = _a, b = _b, c = _c;
		for (ll i = 0; i < points; i++){
			ll t = a*i*i + b*i + c;
			t %= places;
			po[t]++;
		}
		int carry = 0, steps = 5000500, i = 0;
		while (steps--){
			if (po[i] > 1)
				carry += po[i] - 1, po[i] = 1;
			else if (po[i] == 0 && carry > 0)
				po[i] = 1, carry--;
			i = (i + 1) % places;
		}
		ll ret = 0;
		for (int i = 0; i <= places / 2; i++)
			if (po[i] && po[i + places / 2])
				ret += points - 2;
		return ret;
	}
};



// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, long long p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	RightTriangle *obj;
	long long answer;
	obj = new RightTriangle();
	clock_t startTime = clock();
	answer = obj->triangleCount(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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

	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	long long p5;

	{
		// ----- test 0 -----
		p0 = 9;
		p1 = 3;
		p2 = 0;
		p3 = 3;
		p4 = 0;
		p5 = 0ll;
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 40;
		p1 = 3;
		p2 = 5;
		p3 = 0;
		p4 = 0;
		p5 = 1ll;
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 4;
		p1 = 4;
		p2 = 16;
		p3 = 24;
		p4 = 17;
		p5 = 4ll;
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 1000000;
		p1 = 47000;
		p2 = 0;
		p3 = 2;
		p4 = 5;
		p5 = 0ll;
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = 200000;
		p1 = 700;
		p2 = 123456;
		p3 = 789012;
		p4 = 345678;
		p5 = 6980ll;
		all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
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