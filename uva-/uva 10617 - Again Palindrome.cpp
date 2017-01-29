#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;

char a[65];
ll dp[65][65];

// memoization
ll rec(int i,int j){
    if(i == j) // if there is only one character
        return 1;
    if(i+1 == j) // if there is 2 character
        return 2+(a[i] == a[j]); // if they're equal we have 3 palindrome (e.g aa {aa,a,a} ) else we have 2 (e.g ab {a,b} )
    ll &ret = dp[i][j];
    if(ret != -1)
        return ret;
    ret = 0;
    if(a[i] == a[j]) // if the leftmost character and rightmost character are equal
        ret += rec(i+1,j-1)+1;
    ret += rec(i+1,j); // we can erase the first character
    ret += rec(i,j-1); // we can erase the last character
    ret -= rec(i+1,j-1); // from this 2 last cases we have the string twice so we subtract it
                         // e.g abc left (b,c) ,right (a,b) now we took the b twice so we subtract one time
    return ret;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",a);
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",rec(0,strlen(a)-1));

        /*
        // dp style
        //initialize
        int n = strlen(a),j;
        for(int i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                dp[i][j] = 1;
        for(int i=0;i<n-1;i++)
            dp[i][i+1] = (a[i] == a[i+1] ? 3:2);
        for(int len=2;len<n;len++)
            for(int i=0;i+len<n;i++){
                j = i+len;
                if(a[i] == a[j])
                    dp[i][j] = 1 + dp[i][j-1] + dp[i+1][j];
                else
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
            }
        printf("%lld\n",dp[0][n-1]);
        */
    }
}
