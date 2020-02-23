/*
    read editorial to turn problem into finding: z1 + 2*z2 + ... + 6*z6 ≤ 6*M-21, using math manipulation
    
    now we can this easily with dp[i][sum] = dp[i-1][sum] + dp[i][sum-i]
    but memory limit is tight, so we need to get rid of first dimension 
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


class CustomDice {
public:
	 int countDice(int M);
};

const int mod = 1e9+7;
const int maxn = 6000500;

int dp[2][maxn];

int rec(int i,int su){
 	if(su < 0) return 0;
    if(i == 0) return 1;
    int &ret = dp[i][su];
    if(ret != -1) return ret;
    return ret = (rec(i,su-i)+rec(i-1,su)) % mod;
}

int CustomDice::countDice(int M){
    M = M*6 - 21;
    if(M<0) return 0;
    for(int j=0;j<maxn;j++)
        dp[0][j] = 1;
    for(int i=1;i<=6;i++){
     	   for(int s=0;s<=M;s++){
               dp[i%2][s] = dp[1-i%2][s];
               if(s>=i)
                    dp[i%2][s] = (dp[i%2][s] + dp[i%2][s-i])% mod;
           }
    }
    return (dp[0][M]*30LL)%mod;
}

