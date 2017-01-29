/*
    idea:
    we consider the problem as matching problem
    from 0 to each problem we put edge with cost 1 ( because we can only take it once for specific category )
    from each category we put edge to sink with number of this category needed
    then run simple max_flow
*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int inf = (int)1e9;

int cap[1100][1100];
int residual[1100][1100];

bool vis[1100];
int category,problems;
int sink;
int nu_category[25]; // number needed for each category

bool check(){ // check if i got all the categories required
    for(int i=1;i<=category;i++) // for each category
        if(residual[problems+i][sink] > 0) // if there's a path from it to the sink it mean no problems are enough for this category
            return 0;
    return 1;
}

int augmentation_path(int s,int t,int mxflow){ // find the augmentation path ( problem i can match for one category)
    vis[s] = 1;
    if(s == t)
        return mxflow;
    int ret =0;
    for(int i=0;i<=sink;i++)
        if(residual[s][i] > 0 && !vis[i]){ // if there's an edge with cap > 0
            ret = augmentation_path(i,t,min(mxflow,residual[s][i]));
            if(ret > 0){
                residual[s][i] -= ret;
                residual[i][s] += ret;
                return ret;
            }
        }
    return ret;
}

void match(){
    do{ // try all matching
        memset(vis,0,sizeof(vis));
    }while(augmentation_path(0,sink,inf));
    if(check()){ // if all categories are done
        puts("1");
        for(int i=1;i<=category;i++) // each category
            for(int j=1;j<=problems;j++)
                if(residual[j][problems+i] == 0 && cap[j][problems+i]){ // this mean that problem j could go to i ( and it did because in the residual it's path is 0 )
                    if(nu_category[i] == 1) // if this the last one needed for this category
                        printf("%d\n",j);
                    else
                        printf("%d ",j);
                    nu_category[i]--;
                }
    }else // if there's some categories not done
        puts("0");
    return;
}

void read(){
    int i,nu,j,to;
    for(i=1;i<=problems;i++)
        residual[0][i] = 1; // this edge mean i can take each problem once only on our matching
    for(i=1;i<=category;i++){
        scanf("%d",&nu);
        nu_category[i] = nu;
        residual[problems+i][sink] = nu; // this the required number for each category
    }
    for(i=1;i<=problems;i++){
        scanf("%d",&nu);
        for(j=0;j<nu;j++){
            scanf("%d",&to);
            cap[i][problems+to] = 1; // this the problem that can to specific category
            residual[i][problems+to] = 1;
        }
    }
}

int main(){
    while(scanf("%d%d",&category,&problems)){
        if(category == 0 && problems == 0)
            break;
        sink = category+problems+1;
        memset(cap,0,sizeof(cap));
        memset(residual,0,sizeof(residual));
        read();
        match();
    }
}
