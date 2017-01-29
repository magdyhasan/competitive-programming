#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;


typedef long long ll;
const ll inf = (ll)1e18;

ll row[15],col[15];
ll dp[15][15];
int n;

ll rec(int l,int r){
    if(r-l == 0)
        return 0;
    ll &ret = dp[l][r];
    if(ret != -1)
        return ret;
    ret = inf;
    for(int i=l;i<r;i++) // we choose the bes place to put the first parenthesis and recursively  choose for the left and right
        ret = min(ret,rec(l,i)+rec(i+1,r)+row[l]*col[i]*col[r]); // now we multiplied 2 matrices
    return ret;
}

void build(int l,int r){ // build the output
    if(l == r){ // if only 1 matrix print it
        printf("A%d",(l+1));
        return;
    }
    ll opt = rec(l,r);
    ll ret;
    int i;
    for(int j=l;j<r;j++){
        ret = rec(l,j)+rec(j+1,r)+row[l]*col[j]*col[r];
        if(opt == ret) // find what turned out to be the optimal solution
            i=j;
    }

    printf("("); // print the optimal solution recursively
    build(l,i);
    printf(" x ");
    build(i+1,r);
    printf(")");
    return;
}

int main(){
    int ca = 0;
    while(scanf("%d",&n)){
        if(n == 0)
            break;
        int i;
        for(i=0;i<n;i++)
            scanf("%d%d",row+i,col+i);
        memset(dp,-1,sizeof(dp));
        rec(0,n-1);
        printf("Case %d: ",++ca);
        build(0,n-1);
        puts("");
    }
}
