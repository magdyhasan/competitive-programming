/*
 * keep two sets, let's say we n numbers one
 * first one will have (n+1)/2 minimum numbers
 * second one will have n/2 maximum numbers
 *
 * now updating and median is easy to answer
 */
#include <bits/stdc++.h>
using namespace std;


#define all(v)          ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define sci(a)	scanf("%d",&a)
#define scii(a, b)	scanf("%d%d",&a, &b)
#define pri(a)	printf("%d\n",a)
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)


const int maxn = 2e5+50;
typedef long long ll;
int binomial_memo[120][120];

const ll mod = 1000000007;

multiset<int> a,b;

void fix(){
	while(!b.empty() && a.size()<b.size()){
		a.insert(*b.begin());
		b.erase(b.begin());
	}
	while(!a.empty() && b.size()<(b.size()+a.size())/2){
		b.insert(*(--a.end()));
		a.erase((--a.end()));
	}
}

void prt(){
	putchar('a');
	for(int i:a) printf(" %d",i);
	putchar(' ');
	putchar('b');
	for(int i:b) printf(" %d",i);
	puts("");
}

void solve(){
	int tc;
    scanf("%d", &tc);
    while(tc --){
		a.clear(); b.clear();
		int x;
		while(scanf("%d", &x)){
			if(x == 0)
				break;
			if(x > 0){
				if(!b.empty()&&*b.begin()<=x) b.insert(x);
				else a.insert(x);
				fix();
			}
			else{
				printf("%d\n", *(--a.end()));
				a.erase((--a.end()));
				fix();
			}
			//prt();
		}
		if(tc > 0)
			printf("\n");
    }
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	//sci(tc);
	tc = 1;
	while(tc--){
		solve();
		//puts("");
	}
}
