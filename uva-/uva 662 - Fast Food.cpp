#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int cost[210][210],road[210],dp[210][35],p[210][210];
int tc,n,K;

int comp(int l,int r,int pos){ // if a depot was in pos and supply to (l,r)
    int ret = 0;
    for(int i=l;i<=r;i++){ // calc all distance form pos to all other's shops
        if(i == pos)
            continue;
        ret += abs(road[pos]-road[i]);
    }
    return ret;
}

int rec(int idx,int k){
    if(idx == n)
        return 0;
    if(k == 0)
        return (1<<30);
    int &ret = dp[idx][k];
    if(ret != -1)
        return ret;
    ret = (1<<30);
    for(int i=idx;i<n;i++) // try to make the k supply to (l,r)
        ret = min(ret,rec(i+1,k-1)+cost[idx][i]);
    return ret;
}

void build_output(int idx,int k){
    if(idx == n)
        return;
    if(k == 0)
        return;
    int opt = dp[idx][k]; // what was the optimal solution
    int choice;
    for(int i=idx;i<n;i++){
        choice = rec(i+1,k-1)+cost[idx][i];
        if(opt == choice){ // if choice was the optimal soution
            //printf("%d %d\n",i,idx);
            if(i == idx)
                printf("Depot %d at restaurant %d serves restaurant %d\n",(K-k+1),i+1,i+1);
            else
                printf("Depot %d at restaurant %d serves restaurants %d to %d\n",(K-k+1),p[idx][i],idx+1,i+1);
            build_output(i+1,k-1);
            break;
        }
    }
    return ;
}

int main(){
    //freopen("ci.in","rt",stdin);
    while(scanf("%d%d",&n,&K)){
        if(n == 0 && K == 0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d",road+i);
        for(int i=0;i<n;i++) // preprocess all cost for depot to supply (l,r)
            for(int j=i;j<n;j++){
                if(j == i) // if it spply only itself
                    cost[i][j] = 0,p[i][j] = i+1; // p is what shop supply range (l,r)
                else if((j-i+1)%2 != 0) // if it in the middle (e.g 12345 3 will be the middle )
                    cost[i][j] = comp(i,j,((i+j)/2)) , p[i][j] = (i+j)/2+1;
                else{ // here we have 2 choice
                    int t1 = comp(i,j,((i+j)/2));
                    int t2 = comp(i,j,((i+j+1)/2));
                    if(t1 < t2)
                        cost[i][j] = t1, p[i][j] = (i+j)/2+1;
                    else
                        cost[i][j] = t2,p[i][j] = ((i+j+1)/2)+1;
                }
            }
        memset(dp,-1,sizeof(dp));
        printf("Chain %d\n",++tc);
        rec(0,K);
        build_output(0,K);
        printf("Total distance sum = %d\n\n",rec(0,K));
    }
}
