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


class ActivateGame {
public:
	int findMaxScore(vector <string> grid);
};

int cost(char a){
	if (isdigit(a)) return a - '0';
	if (!isupper(a)) return a - 'a' + 10;
	return a - 'A' + 36;
}

int n, m;
bool vis[64][64];
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, -1, 1 };
bool isValid(int i, int j){
	return (i >= 0 && j >= 0 && i < n && j < m);
}


int ActivateGame::findMaxScore(vector <string> grid) {
	n = grid.size(), m = grid[0].size();
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) vis[i][j] = 0;
	int cnt = 0, s = 0;
	vis[0][0] = 1;
	while (cnt + 1 < n*m){
		int cur = -1, ti, tj;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (vis[i][j]) {
			for (int k = 0; k < 4; k++){
				int ni = i + di[k];
				int nj = j + dj[k];
				if (!isValid(ni, nj) || vis[ni][nj]) continue;
				int va = abs(cost(grid[i][j]) - cost(grid[ni][nj]));
				if (va > cur){
					cur = va;
					ti = ni, tj = nj;
				}
			}
		}
		cnt++;
		if (cur != -1){
			s += cur;
			vis[ti][tj] = 1;
		}
	}
	return s;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ActivateGame *obj;
	int answer;
	obj = new ActivateGame();
	clock_t startTime = clock();
	answer = obj->findMaxScore(p0);
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
		res = answer == p1;
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
	int p1;

	{
		// ----- test 0 -----
		string t0[] = { "05", "aB" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 69;
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		string t0[] = { "03", "21" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 7;
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		string t0[] = { "John", "Brus", "Gogo" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 118;
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		string t0[] = { "AAA", "AAA", "AAA" };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 0;
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
