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
const ll mod = 1000000009;


class YetAnotherIncredibleMachine {
public:
	int countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls);
};

int YetAnotherIncredibleMachine::countWays(vector <int> platformMount, vector <int> platformLength, vector <int> balls) {
	ll ret = 1;
	for (int i = 0; i < platformLength.size(); i++) {
		int lx = platformMount[i] - platformLength[i], rx = platformMount[i] + platformLength[i];
		bool f = 0;
		for (int bal : balls)
			if (platformMount[i] < bal) rx = min(rx, bal - 1);
			else if (platformMount[i] > bal) lx = max(bal + 1, lx);
			else f = 1;
			if (f || rx - lx - platformLength[i] + 1 < 1) return 0;
			ret = (ret*ll(rx - lx - platformLength[i] + 1)) % mod;
	}
	return ret;
}



<%:testing - code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!