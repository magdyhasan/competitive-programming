#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

const int inf = (int)1e8;


struct Trie{
    Trie  *child[28];
    bool leaf;
    Trie (){
        for(int i=0;i<28;i++)
            child[i] = 0;
        leaf = 0;
    }
    void add_word(char *str){
        if(*str == '\0'){
            leaf = 1;
            return;
        }
        int cur = (*str)-'a';
        if(child[cur] == 0)
            child[cur] = new Trie();
        return child[cur]->add_word(str+1);
    }
    bool check_word(char *str){
        if(*str == '\0')
            return leaf;
        int cur = (*str)-'a';
        if(child[cur] == 0)
            return 0;
        return child[cur]->check_word(str+1);
    }
    bool check_prefix(char *str){
        if(*str == '\0')
            return 1;
        int cur = (*str)-'a';
        if(child[cur] == 0)
            return 0;
        return child[cur]->check_prefix(str+1);
    }
};

int words,m,n;
char ch[15];
char p[15];
int v[15];

Trie Dic;

bool vis[15];

int rec(int idx,char *st){ // backtrack to check all solution
    st[idx] = '\0'; // set last char as null
    int ret = -inf;

    if(!Dic.check_prefix(st)) // if current word is not prefix of any word in the dictionary then it's not gonna make a word
        return ret; // return -inf to ignore this option
    if(Dic.check_word(st)) // if it make a word then we might end the word here
        ret = 0; // now we have option to stop here ( if we can't stop here and can't make valid words return inf )
    for(int i=0;i<n;i++) // try any tile that's not already taken and backtrack on it
        if(!vis[i]){
            vis[i] = 1;
            st[idx] = p[i]; // we add this char to our word
            int t = rec(idx+1,st)+v[i];
            ret = max(ret,t);
            vis[i] = 0;
        }
    return ret;
}


int main(){
    scanf("%d",&words);
    while(words--){
        scanf("%s",ch);
        if(strlen(ch) > 12) // we can't have word length > 10 because problem said each tile max size is 10
            continue;
        Dic.add_word(ch); // add to our current dictionary
    }
    scanf("%d",&m);
    while(m--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s%d",p+i,v+i);
        char tile[15];
        printf("%d\n",rec(0,tile));
    }
}
