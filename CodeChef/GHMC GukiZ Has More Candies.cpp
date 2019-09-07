/*
 * we need maximum sum, so we have to take maximum numbers we can tak
 * first for each number, we make sure there's at one number with diff <= d
 * we iterate from smallest and check that
 * 
 * now for adding up large numbers, if we can add more than one number, we add from x, x-1 and all possible
 * if only we can add one number, we add largest after largest one we have
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

int a[maxn];

ll sumRan(ll n, ll x)
{
    return (n*(n-1)-(n-x)*(n-x-1))/2;
}


void solve(){
	int n,k,x,d;
	scii(n,k); scii(x,d);
	lp(i,k) sci(a[i]);
	sort(a,a+k);
	if(x<n){
		puts("-1"); return;
	}
	int rem = n - k;
	vector<int> av;
	av.push_back(0);
	ll la = -1e9;
	lp(i,k){
		if((a[i]-la<=d)||(i+1!=k && a[i+1]-a[i]<=d)){
			la = a[i];
			av.push_back(a[i]);
		}else{
			la = min(a[i]+d,x);
			if(la == a[i]) --la;
			av.push_back(a[i]);
			av.push_back(la);
			--rem;
		}
	}
	ll ret = 0;
	for(int i:av) ret += i;
	if(rem<0){
			puts("-1"); return;
	}
	sort(all(av));
	if(rem == 1 && av.back()+d<x){
		ret += av.back()+d;
		printf("%lld\n",ret);
		return;
	}
	av.push_back(x+1);
	for(int i=av.size()-1;i>0;i--){
		int ta = min(av[i]-av[i-1]-1,rem);
		ret += sumRan(av[i],ta);
		rem -= ta;
		if(rem<=0) break;
	}
	printf("%lld\n",ret);
}

int main() {
	freopen("in.txt","r",stdin);
	int tc;
	sci(tc);
	//tc = 1;
	while(tc--){
		solve();
		//puts("");
	}
}
