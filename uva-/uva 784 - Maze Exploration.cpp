#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

char grid[35][83];
int n;

void print(int i,int j){
    if(i < 0 || j < 0 || grid[i][j] == '\0' || (grid[i][j] != ' ' && grid[i][j] != '*') )
        return;
    grid[i][j] = '#';
    print(i+1,j);
    print(i-1,j);
    print(i,j+1);
    print(i,j-1);
}

int main(){
    //freopen("ci.in","rt",stdin);
    int tc;
    scanf("%d",&tc);
    getchar();
    while(tc--){
        n = 0;
        while(gets(grid[n++])){
            if(grid[n-1][0] == '_')
                break;
        }
        n--;
        for(int i=0;i<n;i++)
            for(int j=0;grid[i][j];j++)
                if(grid[i][j] == '*')
                    print(i,j);
        for(int i=0;i<n+1;i++)
            puts(grid[i]);
    }
}
