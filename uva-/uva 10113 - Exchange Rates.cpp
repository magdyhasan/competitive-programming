#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<map>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;
typedef long long ll;

const ll inf = (ll)1e17;

pair<ll,ll> adj[70][70];
map<string,int> nu;
int n;

inline ll GCD(ll a,ll b){
    if(b == 0)
        return a;
    return GCD(b,a%b);
}


void floyd(){
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if( adj[i][j].first == inf && adj[i][k].first != inf && adj[k][j].first != inf ){
                    // if k is common type between i,j
                    ll g = GCD(adj[i][k].second,adj[k][j].first); // we find the gcd of the common type rate (k)

                    adj[i][j].first = adj[k][j].first/g*adj[i][k].first; // this how many we need from the (i,k) in order to exchange with (k,j)
                    adj[i][j].second = adj[i][k].second/g*adj[k][j].second;
                    /**
                            this adj[i][k].second
                                     |
                                     *
                        2 shirt = 5 sock // sock is the k ( the common type )
                        94 sock = 9 pant
                            *
                            |
                    this adj[k][j].first

                    */

                    g = GCD(adj[i][j].first,adj[i][j].second); // we get them to lowest term
                    adj[i][j].first /= g;
                    adj[i][j].second /= g;
                    // vice versa
                    adj[j][i].first = adj[i][j].second;
                    adj[j][i].second = adj[i][j].first;
                }
}

int main(){
    //freopen("ci.in","rt",stdin);
    int i,j,t1,t2,nu1,nu2;
    string ch,item1,item2;
    char eq;
    for(i=0;i<70;i++)
        for(j=0;j<70;j++)
            adj[i][j].first = adj[i][j].second = inf;

    while(getline(cin,ch)){
        if(ch[0] == '.')
            break;
        if(ch[0] == '!'){
            istringstream(ch) >> eq >> t1 >> item1 >> eq >> t2 >> item2;
            if(nu.count(item1) == 0) // if they didn't occur before we give them an id
                nu[item1] = n++;
            if(nu.count(item2) == 0)
                nu[item2] = n++;
            nu1 = nu[item1];
            nu2 = nu[item2];
            ll g = GCD(t1,t2); // get them to lowest term by GCD
            adj[nu1][nu2].first = t1/g;
            adj[nu1][nu2].second = t2/g;
            // vice versa
            adj[nu2][nu1].first = t2/g;
            adj[nu2][nu1].second = t1/g;
        }else{
            istringstream(ch) >> eq >> item1 >> eq >> item2;
            t1 = nu[item1];
            t2 = nu[item2];
            floyd();
            if(adj[t1][t2].first == inf)
                cout << "? " << item1 << " = ? " << item2 << endl;
            else
                cout << adj[t1][t2].first << " " << item1 << " = " << adj[t1][t2].second << " " << item2 << endl;
        }
    }
}
