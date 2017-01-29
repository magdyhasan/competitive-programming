#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n,m;
int x[55],value;

inline int GCD(int a,int b){
    return (b == 0) ? a:GCD(b,a%b);
}

inline int LCM(int a,int b){
    return a*b/GCD(a,b);
}

int main(){
    while(scanf("%d%d",&n,&m)){
        if(n == 0 && m == 0)
            break;
        for(int i=0;i<n;i++)
            scanf("%d",x+i);
        for(int i=0;i<m;i++){
            int res_a = 0, res_b = (1<<30); // we want to maximize res_a (as long res_a <= value) and minimize res_b
            scanf("%d",&value);
            for(int c1=0;c1<n;c1++) // try each of the four number of the available coins
                for(int c2=c1+1;c2<n;c2++)
                    for(int c3=c2+1;c3<n;c3++)
                        for(int c4=c3+1;c4<n;c4++) {
                            int lcm = LCM(x[c1],x[c2]);
                            lcm = LCM(lcm,x[c3]);
                            lcm = LCM(lcm,x[c4]); // lcm of (c1,c2,c3,c4)
                            int ga = (value/lcm)*lcm; // maximum number <= value
                            int ma = ga; // minimum number >= value
                            if(ma < value)
                                ma += lcm;
                            res_a = max(res_a,ga);
                            res_b = min(res_b,ma);
                        }
            printf("%d %d\n",res_a,res_b);
        }

    }
}
