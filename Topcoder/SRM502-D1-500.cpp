/*
  at first we need to know in which order we should take the problems regardless of which problems we will actually take
  this a standard problem, we can do it by sorting using compare function that consider taking i first then j vs j first then i and see which is better
  
  now after sorting, it's just standard dp to have specific time and try to take some courses in specific order
*/
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


class TheProgrammingContestDivOne {
public:
	int find(int T, vector <int> maxPoints, vector <int> pointsPerMinute, vector <int> requiredTime);
};

int n, T;
vector <int> id, mp, ppm, rt;
ll dp[52][100500];

ll po(int i, int ti){
    return (mp[i]-(ti+rt[i])*1LL*ppm[i]);
}

ll rec(int i,int ti){
 	if(i == n || ti > T) return 0;
    ll &ret = dp[i][ti];
    if(ret != -1) return ret;
    ret = rec(i+1,ti);
    cout << "in rec " << i << " " << rt[id[i]] << " " << ti << endl;
    if(rt[id[i]]+ti <= T)
    	ret = max(ret,rec(i+1,ti+rt[id[i]])+po(id[i],ti));
    return ret;
}

int TheProgrammingContestDivOne::find(int _T, vector <int> _mp, vector <int> _ppm, vector <int> _rt){
    mp = _mp, ppm = _ppm, rt = _rt;
    T = _T;
    n = mp.size();
    id.clear();
    for(int i=0;i<n;i++)
        id.push_back(i);
    sort(id.begin(),id.end(),[&](int i,int j){
        return ((po(i,0)+po(j,rt[i])) > (po(j,0)+po(i,rt[j])));
    });
    for(int i=0;i<52;i++) for(int j=0;j<100500;j++)
        dp[i][j] = -1;
    cout << n << " " << po(0,0) << endl;
    for(auto i:id)
        cout << "id " << i << endl;
    return rec(0,0);
}
