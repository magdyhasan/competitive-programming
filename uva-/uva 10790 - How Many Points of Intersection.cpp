#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main(){
    long long a,b,Apairs,Bpairs;
    int tc = 1;
    while(scanf("%lld%lld",&a,&b)){
        if(a == 0 && b == 0)
            break;
        Apairs = a*(a-1)/2; // number of pairs of a
        Bpairs = b*(b-1)/2;// number of pairs of b
        printf("Case %d: %lld\n",tc++,(long long)Apairs*Bpairs); // for each pair of a and b we have 1 intersection point
    }
}
