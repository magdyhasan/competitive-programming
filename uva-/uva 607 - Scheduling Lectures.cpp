#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int n,C,L,min_lectures;
int t[1005];
int mem[1005][502];
int dp[1005][502];

int DI(int free_time){ // calculate DI according to problem statement
    if(free_time == 0)
        return 0;
    if(free_time <= 10)
        return -C;
    return (free_time-10)*(free_time-10);
}

int get_min(int topic,int time){ // get minimum number of lectures we need ( if can't return inf )
    if(time < 0) // no time for all topics
        return 1<<26;
    if(topic == n) // we have taken all topics
        return 1; // we return 1 because we started with time = L ( so we have used a lecture in the beginning )
    int &ret = mem[topic][time];
    if(ret != -1)
        return ret;
    int c1 = get_min(topic+1,time-t[topic]); // we either take topic in the current lecture
    int c2 = get_min(topic+1,L-t[topic])+1; // or take it in the next lecture and add 1 because we have a new lecture
    return ret = min(c1,c2); // return the minimum of the 2 cases
}

int rec(int topic,int time){
    if(topic == n)
        return DI(time);
    int &ret = dp[topic][time];
    if(ret != -1)
        return ret;
    int c1 = get_min(topic+1,time-t[topic]); // we test if we take this topic in the current topic in this lecture ( if we don't have time c1 will be inf and we can't do that )
    int c2 = get_min(topic+1,L-t[topic])+1; // or we take it in the next lecture ( and if no more lectures available c2 will be inf and we can't select this option )
    if(c1 < c2) // if c1 is the best option
        ret = rec(topic+1,time-t[topic]); // then we take this topic in the current lecture
    else if(c2 < c1) // if c2 is the best option
        ret = rec(topic+1,L-t[topic])+DI(time); // we take this topic in the next lecture and add the DI of the free time of the current lecture
    else // if both option are equal take min
        ret = min(rec(topic+1,time-t[topic]),rec(topic+1,L-t[topic])+DI(time));
    return ret;
}


int main(){
    int cases = 0;
    while(scanf("%d",&n) && n != 0){
        scanf("%d%d",&L,&C);
        if(cases)
            puts("");

        memset(mem,-1,sizeof(mem));
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++)
            scanf("%d",&t[i]);

        min_lectures = get_min(0,L); // get minimum number of lectures

        printf("Case %d:\n",++cases);
        printf("Minimum number of lectures: %d\n",min_lectures);
        printf("Total dissatisfaction index: %d\n",rec(0,L));
    }
}
