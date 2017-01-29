#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int dp[10005][105],nu[10005];
int n,k;

int mod(int x,int add){ // we care only about the mod after +/- because (a+b)%k == a%k+b%k
    return (((x+add)%k)+k)%k;
}

int solve(int i,int sum){
    if(i == n)
        return (sum%k ? 0:1); // check our reminder
    int &ret = dp[i][sum];
    if(ret != -1)
        return ret;
    return ret = ( solve(i+1,mod(sum,nu[i])) || solve(i+1,mod(sum,-1*nu[i])) ); // we either add it or subtract it ( by making it negative )
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&n,&k);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            scanf("%d",nu+i);
        if(solve(0,0))
            puts("Divisible");
        else
            puts("Not divisible");
    }
}
