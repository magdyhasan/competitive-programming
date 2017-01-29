#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<map>
#include<iostream>
using namespace std;

char dic[210][15],str[15],str1[15],str2[15];
int n;
long long adj[210][210];
map<string,int> id;

int dif(char *a,char *b){ // get the difference of char between 2 words
    int i=0,j=0;
    int ret = 0;
    for(;a[i]&&b[j];i++,j++)
        if(a[i] != b[j])
            ret++;
    for(;a[i];i++) // if there're more char in a
        ret++;
    for(;b[j];j++)// if there're more char in b
        ret++;
    return ret;
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        n = 0;
        while(gets(str)){
            if(str[0] == '*')
                break;
            id[str] = n; // give the word an id
            strcpy(dic[n++],str); // store the words
        }
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++){
                adj[i][j] = adj[j][i] = (1<<30); // initialize adj
                if(dif(dic[i],dic[j]) == 1) // if distance between i,j is 1 make them adjacent
                    adj[i][j] = adj[j][i] = 1;
            }
        // Floyd-warshall
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(adj[i][j] > adj[i][k]+adj[k][j])
                        adj[i][j] = adj[i][k]+adj[k][j];
        while(gets(str)){
            if(strlen(str) == 0)
                break;
            sscanf(str,"%s%s",str1,str2);
            printf("%s %s %d\n",str1,str2,adj[id[str1]][id[str2]]);
        }
        if(tc)
            puts("");
    }
}
