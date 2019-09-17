/*
  let's consider two strings in the middle of the string
  a[i], a[i+1], we can see that we always need to put them in such a way that,
  a[i]+a[i+1] <= a[i+1]+a[i]
  so we can make a dp, that for a given length, remeber last word we took
  dp[i][j], we last took part s[i,i+1,..j]
  now we can add s[j+1...] only if we meet our condition
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
#include <string.h>
using namespace std;

typedef long long ll;

class MagicNaming {
public:
	int maxReindeers(string magicName);
};


int dp[55][55];

int MagicNaming::maxReindeers(string s) {
	int n = s.size();
    for(int i=0;i<n;i++){
    	for(int j=i;j<n;j++){
         	if(i==0) dp[i][j] = 1;
            else{
             	dp[i][j] = -123456789;
                for(int k=0;k<i;k++){
                	string a = s.substr(k,i-k);
                    string b = s.substr(i,j-i+1);
                    if(a+b<=b+a){
                    	dp[i][j] = max(dp[i][j],dp[k][i-1]+1);
                    }
                }
            }
        }
    }
    int ret = 1;
    for(int i=0;i<n;i++) 
        ret = max(ret,dp[i][n-1]);
    return ret;
}
