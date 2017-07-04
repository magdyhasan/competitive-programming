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


class PascalCount {
public:
	int howMany(int i, int d);
};

typedef long long ll;
int get_powers(int n, int p){
	int res = 0;
	for (int power = p; power <= n; power *= p){
		res += n / power;
		if (power > n / p) break;
	}
	return res;
}


int PascalCount::howMany(int ir, int d) {
	vector<pair<int, int>> pr;
	for (int i = 2; i*i <= d; i++)if (d%i == 0){
		int cnt = 0;
		while (d%i == 0) d /= i, cnt++;
		pr.push_back({ i, cnt });
	}
	if (d > 1) pr.push_back({ d, 1 });
	int cnt = 0;
	for (int j = 0; j <= ir; j++){
		bool f = 1;
		for (auto p : pr)
			if (p.second > get_powers(ir, p.first) - get_powers(j, p.first) - get_powers(ir - j, p.first))
				f = 0;
		cnt += f;
	}
	return cnt;
}



<%:testing - code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!