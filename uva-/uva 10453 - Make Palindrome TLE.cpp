#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n;
char a[1004];
int dp[1005][1005];

int rec(int i,int j){
    if(j-i < 1)
        return 0;
    int &ret = dp[i][j];
    if(ret != -1)
        return ret;

    if(a[i] == a[j]) // if the left and right are equal we don't have to add anything
        return ret = rec(i+1,j-1);
    ret = rec(i+1,j)+1; // we try to add one match for the left ( e.g abc we add abca )
    ret = min(ret,rec(i,j-1)+1); // try to add one match for the right (e.g abc we add cabc )
    return ret;
}

void build(int i,int j){ // now build the output with the same function
    if(j-i < 1){
        if(j == i) // if there one char we print it
            putchar(a[j]);
        return;
    }

    if(a[i] == a[j]){ // if they are equal we print them as the leftmost char and rightmost
        putchar(a[i]); // print the left most ( abca we first print a then handle bc )
        build(i+1,j-1);// handle bc
        putchar(a[j]); // print the last a
        return;
    }
    int c1 = rec(i+1,j)+1; // we try the 2 choices
    int c2 = rec(i,j-1)+1;
    int opt = rec(i,j); // we see what was the optimal way
    if(opt == c1){ // if the optimal way was the first
        putchar(a[i]); // we have this char
        build(i+1,j); // print what is in the middle
        putchar(a[i]); // now print the one we added ( that match to a[i])
    }else{ // same here as above
        putchar(a[j]); // here we just added the char in the first
        build(i,j-1);
        putchar(a[j]);
    }
}

int main(){
    while(scanf("%s",a) == 1){
        memset(dp,-1,sizeof(dp));
        printf("%d ",rec(0,strlen(a)-1));
        build(0,strlen(a)-1);
        puts("");
    }
}
