#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int dp[1005][1005];
int cut[55],cuts;


int rec(int l,int r){
    int &ret = dp[l][r];
    if(ret != -1)
        return ret;
    ret = (1<<27);
    for(int i=0;i<cuts;i++)
        if(cut[i] < r && cut[i] > l) // find all the cut that can be made in this range l,r
            ret = min(ret,r-l+rec(l,cut[i])+rec(cut[i],r));
    if(ret == (1<<27)) // there was no cut needed here
        ret = 0;
    return ret;
}
/*

int rec(int l,int r){
    if(r-l <= 1)
        return 0;
    int &ret = dp[l][r];
    if(ret != -1)
        return ret;
    ret = (1<<27);
    for(int i=l+1;i<r;i++)
        ret = min(ret,rec(l,i)+rec(i,r)+cut[r]-cut[l]);
    return ret;
}
*/

int main(){
    //freopen("ci.in","rt",stdin);
    int len;
    while(scanf("%d",&len)){
        if(len == 0)
            break;
        memset(dp,-1,sizeof(dp));
        scanf("%d",&cuts);
        for(int i=0;i<cuts;i++)
            scanf("%d",cut+i);
        printf("The minimum cutting is %d.\n",rec(0,len));
        /*
        for(int i=1;i<=cuts;i++)
            scanf("%d",cut+i);
        cut[0] = 0;
        cut[cuts+1] = len;
        printf("The minimum cutting is %d.\n",rec(0,cuts+1));
        */
    }
}
