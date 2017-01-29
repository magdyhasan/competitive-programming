#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

char a[105],b[105];
int n,m,dp[105][105];

int match(int i,int j){
    if(i == n || j == m) // if we are at the end of one of the string there's no more match
        return 0;
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;
    if(a[i] == b[j]) // if they're equal then we have a match
        return ret = match(i+1,j+1)+1;
    ret = match(i+1,j); // we try ignore char from a
    ret = max(ret,match(i,j+1)); // we try ignore char from b
    return ret;
}

int main(){
    int tc = 0;
    while(gets(a)){
        if(a[0] == '#')
            break;
        gets(b);
        n = strlen(a);
        m = strlen(b);
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: you can visit at most %d cities.\n",++tc,match(0,0));
    }
}
