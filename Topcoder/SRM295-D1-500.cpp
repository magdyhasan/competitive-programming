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
#include<bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class JimmyLightning {
public:
	int robTheBank(vector <int> doors, vector <string> diamonds);
};

int n;
vector<int> cl;
vector<pair<int, int>> r[55];

int dp[55][55][1005];

int rec(int idx, int cur, int ti){
	if (idx < 0) return 0;
	int &ret = dp[idx][cur][ti];
	if (ret != -1) return ret;
	ret = -123456789;
	if (cur == r[idx].size()){
		if (ti >= cl[idx]){
			return ret;
		}
		return ret = rec(idx - 1, 0, ti);
	}
	for (int i = 0; (ti + i*r[idx][cur].second) < cl[idx]; i++)
		ret = max(ret, rec(idx, cur + 1, ti + i*r[idx][cur].second) + i*r[idx][cur].first);
	return ret;
}

int JimmyLightning::robTheBank(vector <int> doors, vector <string> diamonds) {
	n = doors.size();
	cl = doors;
	for (int i = 0; i < 55; i++)	r[i].clear();
	memset(dp, -1, sizeof(dp));
	for (string st : diamonds){
		int a, b, c;
		istringstream(st) >> a >> b >> c;
		r[c - 1].push_back(make_pair(a, b));
	}
	return rec(n - 1, 0, 0);
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <string> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p1[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	JimmyLightning *obj;
	int answer;
	obj = new JimmyLightning();
	clock_t startTime = clock();
	answer = obj->robTheBank(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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

	vector <int> p0;
	vector <string> p1;
	int p2;

	{
		// ----- test 0 -----
		int t0[] = { 6 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		string t1[] = { "2 1 1" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 10;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = { 1 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		string t1[] = { "999 1 1" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 0;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = { 10, 5, 2 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		string t1[] = { "1 1 1", "2 1 2", "3 1 3" };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 14;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
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