/*
  -we always can make a 1 size component by remvoing edge from a leaf
  -we can never make size n component after removing edge
  -if we need size i component then there must be n-i component
  after this check, we build the tree like this:
  going from first component we build a path tree and attach nodes to a node in the path to make spcicfic size component
  
*/
#include<bits/stdc++.h>
using namespace std;


#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scll(a)	scanf("%lld",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define prll(a)	printf("%lld\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)



const double eps = 1e-8;

typedef  long long ll;

const ll mod = 1e9+7;

const int inf = 1<<30;
const int maxn = 900500;//2e5+5;
const double EPS = 1e-7;

//int a[maxn], b[maxn];

void no(){
    puts("-1");
    exit(0);
}

char s[maxn];


void solve() {
    scanf("%s",s);
    int n = strlen(s);
    if(s[0]=='0'||s[n-1]=='1')
        no();
    lpi(i,1,n-1) if(s[i]!=s[n-i-2])
        no();
    puts("1 2");
    int last = 1;
    lpi(i,1,n-1){
        printf("%d %d\n",last+1,i+2);
        if(s[i]=='1')
            last = i+1;
    }
}


int main(){
    freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    lp(tt,tc){
//        printf("Case %d:\n",tt+1);
        solve();
    }
}
