#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<string>
using namespace std;

#define isLetter(x) ( (x <= 'z' && x >= 'a') || (x <= 'Z' && x >= 'A') || (x <= '9' && x >= '0') )

string a[1005],b[1005];
int n,m,tc;
char msg1[1005],msg2[1005];
int dp[1005][1005];

int LCS(int i,int j){ // memoization
    if(i == n || j == m)
        return 0;
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;
    if(a[i] == b[j]) // if they equal then we have a match and we recurse on what is left
        return 1+LCS(i+1,j+1);
    return ret = max(LCS(i+1,j),LCS(i,j+1)); // we have 2 choice, to leave word from a or b
}

int LCS_FOR(){ // DP
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(i == 0 || j == 0) // // base case
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1]) // if they equal then we have a match
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    return dp[n][m];
}

int main(){
    while(gets(msg1)){
        gets(msg2);
        n = m = 0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;msg1[i];i++)
            if(!isLetter(msg1[i])) // if it's on-letter char consider it to be space
                msg1[i] = ' ';
        for(int i=0;msg2[i];i++)
            if(!isLetter(msg2[i]))
                msg2[i] = ' ';
        istringstream iss1(msg1),iss2(msg2);
        string temp;
        while(iss1 >> temp) a[n++] = temp;
        while(iss2 >> temp) b[m++] = temp;
        if(n == 0 || m == 0)
            printf("%2d. Blank!\n",++tc);
        else
            printf("%2d. Length of longest match: %d\n",++tc,LCS_FOR());
    }
}
