#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[1005][1005];
char st[1005];

int make_palindrom(int i,int j){
    if(j-i < 1)
        return 0;
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;
    if(st[i] == st[j])
        return ret = make_palindrom(i+1,j-1);
    ret = make_palindrom(i+1,j)+1; // remove i'th char ( or add one to last similar to i'th )
    ret = min(ret,make_palindrom(i,j-1)+1); // remove j'th char ( or add one to first similar to j'th )
    ret = min(ret,make_palindrom(i+1,j-1)+1); // replace i'th or j'th to replace the other
    return ret;
}

int main(){
    int tc;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){
        scanf("%s",st);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",t,make_palindrom(0,strlen(st)-1));
    }
}
