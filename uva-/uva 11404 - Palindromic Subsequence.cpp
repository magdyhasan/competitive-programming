/**
with function build_output separate from the maximizing function
*/


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

int dp[1005][1005];
char st[1005];
map<int,map<int,string> > dpout;

int rec(int i,int j){ // calculate max length
    if(j-i < 1)
        return (j == i ? 1:0);
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;
    ret = 0;
    if(st[i] == st[j]) // if they equal we have two chars
        return ret = rec(i+1,j-1)+2;
    ret = rec(i+1,j); // else we try to remove one the 2
    ret = max(ret,rec(i,j-1));
    return ret;
}

string build(int i,int j){ // function to build the output
    if(dpout[i][j].size() > 0) // we have to memorize it as a knapsack we have 2 options to choose that come first lexicographically
        return dpout[i][j];

    string &ret = dpout[i][j] = "";
    if(j-i < 1){
        if(j == i) // if only have 1 char return it
            ret += st[i];
        return ret;
    }
    if(st[i] == st[j]){ // if two char return them
        ret += st[i];
        ret += build(i+1,j-1); // what's between them
        ret += st[j];
        return ret;
    }
    if(i+1 == j){ // if two not equal char we choose the minimum
        if(st[i] < st[j])
            ret += st[i];
        else
            ret += st[j];
        return ret;
    }
    int opt = rec(i,j);  // we find what was optimal for(i,j)
    int c1 = rec(i+1,j);
    int c2 = rec(i,j-1);

    if(opt == c1 && opt != c2) // if the optimal was the first one
        ret = build(i+1,j);
    else if(opt == c2 && opt != c1)// if the optimal was the second one
        ret = build(i,j-1);
    else // if they were equal we choose the minimum one
        ret = min(build(i+1,j),build(i,j-1));
    return ret;
}

int main(){
    while(scanf("%s",st)!=EOF){
        int len = strlen(st);
        dpout = map<int,map<int,string> >(); // initialize
        memset(dp,-1,sizeof(dp));
        rec(0,len-1); // first find max length
        printf("%s\n",build(0,len-1).c_str()); // then build the output
    }
}
