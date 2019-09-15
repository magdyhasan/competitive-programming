/*
	Think of each query as three cases:
	- the two nodes in same component without X's in between, we just return manhattan distance
	- different components, just output -1
	- same component but with X's between, max 1 X in a column, we break it up
	we go from left to nearst X and add it's manhattan distance
	go from right to nearst X to it's left and add it's distance
	in between, we can just use distance from bfs, because from column with 1 X, there's just one way to go, so BFS will work
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

vector<int> obt, obtr;
int d[2][maxn];
int vis[2][maxn];
int cnt;

char s[2][maxn];

int di[] = {1,0,-1};
int dj[] = {0,1,0};

int n,q;

bool val(int i,int j){
    return i >=0 && j >= 0 && i <2 && j < n && !vis[i][j] && s[i][j] != 'X';
}


void bfs(int i,int j){
    queue<int> q;
    q.push(i); q.push(j);
    vis[i][j] = ++cnt;
    d[i][j] = 1;
    while(!q.empty()){
        int i = q.front(); q.pop();
        int j = q.front(); q.pop();
        lp(k,3){
            int ni = i + di[k], nj = j + dj[k];
            if(val(ni,nj)){
                d[ni][nj] = d[i][j]+1;
                vis[ni][nj] = cnt;
                q.push(ni);
                q.push(nj);
            }
        }
    }
}

int dis(int si,int sj,int ti, int tj){
    return (abs(ti-si)+abs(tj-sj));
}

int qu(int si,int sj,int ti, int tj){
    if(sj>tj) swap(si,ti), swap(sj,tj);
    if(vis[si][sj]!=vis[ti][tj] || s[si][sj] == 'X' || s[ti][tj] == 'X') return -1;
    int be = upper_bound(all(obt),sj)-obt.begin();
   // printf("%d %d %d %d\n",si,sj,ti,tj);
   // pri(obt[be]);
    if(obt[be]>=tj) return dis(si,sj,ti,tj);
    int en = upper_bound(all(obt),tj)-obt.begin()-1;
   // printf("%d %d %d %d\n",obtr[be],obt[be],obtr[en],obt[en]);
    return dis(si,sj,obtr[be],obt[be])+(d[obtr[en]][obt[en]]-d[obtr[be]][obt[be]])+dis(ti,tj,obtr[en],obt[en]);
}

void privis(){
    lp(i,2) {
        lp(j,n) printf("%d ",vis[i][j]);
        puts("");
    }
}

int main() {
    scii(n,q);
    scanf("%s%s",s[0],s[1]);
    clr(d,63);
    obt.push_back(-1);
    obtr.push_back(0);
    lp(j,n){
        int nob = 0;
        lp(i,2){
            if(s[i][j]=='X') ++nob;
            else if(!vis[i][j]) bfs(i,j);
        }
        if(nob==1){
            obt.push_back(j);
            obtr.push_back((s[0][j] == 'X' ? 1:0));
        }
    }
    obt.push_back(n);
    obtr.push_back(0);
    while(q--){
        int u,v; scii(u,v);
        --u; --v;
        //puts("qqqq");
        pri(qu(u/n,u%n,v/n,v%n));
    }
}



