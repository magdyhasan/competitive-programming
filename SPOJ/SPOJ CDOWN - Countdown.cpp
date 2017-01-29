#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int par[1005],tree[1005],cnt[1005];
map<string,int> id;
vector<string> names;
int n,d,m,te;

bool cmp(const int& i,const int& j){
    if(cnt[i] != cnt[j])
        return cnt[i] > cnt[j];
    return names[i] < names[j];
}

int main(){
    //freopen("ci.in","rt",stdin);
    int tc;
    scanf("%d",&tc);
    for(int T=1;T<=tc;T++){
        scanf("%d%d",&m,&d);
        // initialize
        id.clear();
        names.clear();
        n = 0;
        memset(par,-1,sizeof(par));
        memset(cnt,0,sizeof(cnt));
        // read input
        char str[50];
        while(m--){
            scanf("%s%d",str,&te);
            string st(str);
            if(id.count(st) == 0)
                id[st] = n++,names.push_back(st);
            while(te--){
                scanf("%s",str);
                string stChild(str);
                if(id.count(stChild) == 0)
                    id[stChild] = n++, names.push_back(stChild);
                par[id[stChild]] = id[st];
            }
        }
        // from any name try to walk up to his d grand ( if there's no d grand it will be -1)
        for(int i=0;i<n;i++){
            tree[i] = i;
            int father = i;
            for(int i=0;i<d;i++){
                father = par[father];
                if(father == -1) // if he don't have father till the d
                    break;
            }
            if(father != -1)
                cnt[father]++;
        }

        sort(tree,tree+n,cmp); // sort according to number of grands he has then names

        int out = 0;
		printf( "Tree %d:\n", T );
        for(int i=0;i<n;i++){
            if(cnt[tree[i]] == 0) // if he has no d grandchild's stop
                break;
            if(i && cnt[tree[i]] != cnt[tree[i-1]] )// if a tie
                out++;
            if(i > 2 && cnt[tree[i]] != cnt[tree[i-1]] ) // if not a tie and we output 3
                break;
            if(out == 3) // if there's some ties and we output 3
                break;
            printf("%s %d\n",names[tree[i]].c_str(),cnt[tree[i]]);
        }
    }
}
