/**
with building output in the maximizing function
*/


#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<map>
#include<iostream>
using namespace std;

#define mp(a,b) make_pair(a,b)

pair<int,string> dp[1005][1005];
char st[1005];

pair<int,string> rec(int i,int j){
    if(j-i < 1){
        if(i == j) // if i only have one char return it as string
            return mp(1,string(1,st[i]));
        return mp(0,""); // if string is empty
    }
    pair<int,string> &ret = dp[i][j];
    if(ret.first != -1)
        return ret;
    if(st[i] == st[j]) { // if they're equal
        ret = rec(i+1,j-1); // get what's between them
        ret.first += 2; // we have now more 2 chars
        ret.second = st[i] + ret.second + st[j]; // our string st[i] in front and st[j] in back
        return ret;
    }
    pair<int,string> c1 = rec(i+1,j); // else we  try the both options
    pair<int,string> c2 = rec(i,j-1);
    if(c1.first > c2.first) // if choice 1 has more chars than choice 2
        return ret = c1;
    if(c2.first > c1.first) // if choice 2 has more chars than choice 2
        return ret = c2;
    if(c1.second < c2.second) // if they're equal and choice 1 is the first lexicographically
        return ret = c1;
    return ret = c2; // else choice 2 is the first lexicographically
}

int main(){
    while(scanf("%s",st)!=EOF){
        int len = strlen(st);
        for(int i=0;i<=len;i++) // initialize
            for(int j=0;j<=len;j++)
                dp[i][j] = mp(-1,"");

        printf("%s\n",rec(0,len-1).second.c_str());
    }
}
