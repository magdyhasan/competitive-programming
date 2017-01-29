#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;

int tc,n,len;
char st[10010];
int have[30][10010];

void f(){
    have[(st[0]-'A')][0]++;
    for(int i=1;i<len;i++){
        have[(st[i]-'A')][i]++;
        for(int j=0;j<26;j++)
            have[j][i] += have[j][i-1];
    }
}

int BS(int l,int r,int key,int row){ // binary search where row is our if our first index of have ( represent which char )
    int mid;
    while(l < r){
        mid = (l+r)/2;
        if(have[row][mid] < key)
            l = mid+1;
        else
            r = mid;
    }
    return l;
}

void solve(){
    char ch;
    int pos = 0, tpos = 0, nu, j = 0;
    while(sscanf(st+tpos,"%d%c%n",&nu,&ch,&pos) == 2){ // read a number and char
        int mi = (j == 0 ? 0:have[(ch-'A')][j-1]); // get number of char we used so far
        int t = BS(j,len,nu+mi,(ch-'A')); // first index that's enough for this word
        if(t == len){ // if not enough number of char for it
            puts("NO");
            return;
        }
        tpos += pos;
        j = t+1;
    }
    puts("YES");
    return;
}

int main(){
    scanf("%d",&tc);
    while(tc--){
        memset(have,0,sizeof(have));
        scanf("%d%s",&n,st);
        len = strlen(st);
        f(); // make accumulate array of each letter in each position
        while(n--){
            scanf("%s",st); // read each word
            solve();
        }
    }
}
