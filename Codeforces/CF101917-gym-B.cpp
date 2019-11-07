/*
  Let's fix the first time, now we have some available person to consider
  now let's sort available people by e and iterate on them, which means increasing second time
  let's push while iterating into priority queue d of added persons, and when size of queue > k, let's remove bigger one
  now we have least k persons with fixed a and e, and minimize the answer
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
 
 
const int maxn = 500500;
const double eps = 1e-8;
 
typedef  long long ll;
 
const ll mod = 1e9+7;
 
struct pe{
    ll a,e,d;
}a[maxn];
 
 
vector<pe> v;
 
void solve() {
    int n,k; scii(n,k);
    lp(i,n){
        scanf("%lld %lld %lld",&a[i].a,&a[i].e,&a[i].d);
    }
    sort(a,a+n,[](const pe& p1, const pe& p2){
        return p1.a < p2.a;
    });
    ll ret = 1LL<<55;
    lp(i,n){
        ll cur = a[i].a;
        v.push_back(a[i]);
        sort(v.begin(),v.end(),[](const pe& p1, const pe& p2){
            return p1.e < p2.e;
        });
        priority_queue<int> pq;
        for(auto j:v){
            pq.push(j.d);
            while(pq.size()>k){
                pq.pop();
            }
            if(pq.size() == k)
                ret = min(ret,cur+j.e+pq.top());
        }
    }
    prll(ret);
 
}
 
 
int main(){
 ////   freopen("in.txt","r",stdin);
    int tc = 1;
    //sci(tc);
    while(tc--){
        solve();
    }
}
