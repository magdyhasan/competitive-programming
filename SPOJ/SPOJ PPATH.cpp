#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<cstring>
#include<map>

using namespace std;


typedef pair<int,int> pii;
#define mp(a,b) make_pair(a,b)


vector<bool> prime(10020,1); // prime[i] will be 1 if i is prime
bool vis[10000];
int a,b;


void primes(){ // generate all prime in the range of 4 digits
    prime[0] = prime[1] = 0;
    for(int i=2;i<10000;i++)
        if(prime[i])
            for(int j=i*i;j<10000;j+=i)
                prime[j] = 0;
}

int main(){
    primes();
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%d%d",&a,&b);
        queue< pii > q;
        q.push(mp(a,0));
        memset(vis,0,sizeof(vis));
        bool done = 0;
        vis[a] = 1;
        while(!q.empty()){ // normal BFS
            pii cur = q.front();
            q.pop();
            if(cur.first == b){
                done = 1;
                printf("%d\n",cur.second);
                break;
            }
            for(int i=10;i<100000;i*=10) // choose one of the four digit to change it
                for(int j=0;j<10;j++){ // choose the digit you're going to add
                    if(i == 10000 && j == 0) // can't add 0 at the beginning.
                        continue;
                    int t = j; // this our current digit
                    t = (cur.first/i)*10+t; // add the digits that are to the left of the digit we changed
                    t = t*(i/10)+(cur.first%(i/10)); // add the digits that are to the right of the digit we changed
                    if(prime[t] && !vis[t]) // if our new number is not visited before and is prime
                        q.push(mp(t,cur.second+1)),vis[t]=1;
                }

        }
        if(!done)
            puts("Impossible");
    }
}
