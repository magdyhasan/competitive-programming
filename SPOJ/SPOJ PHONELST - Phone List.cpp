#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

struct Trie{
    Trie *child[10];
    bool word;
    Trie(){ // initialize
        for(int i=0;i<10;i++)
            child[i] = 0;
        word = 0;
    }
    bool add_word(char *str){ // try adding word without being a prefix of another
        Trie *tail;
        tail = this; // start from the beginning of the word
        for(int i=0;str[i];i++){
            if(tail->word) // if there was already word here ( hence there's another word that's a prefix of this one )
                return 0;
            int cur = str[i] - '0';
            if(tail->child[cur] == 0)
                tail->child[cur] = new Trie();
            tail = tail->child[cur]; // go to next digit
        }
        tail->word = 1; // mark here as a word
        for(int i=0;i<10;i++) // check if this gonna be a prefix of another word
            if(tail->child[i]) // of child[i] of tail is created this mean there's already word with this prefix
                return 0;
        return 1;
    }
};

int main(){
    int tc,n;
    scanf("%d",&tc);
    while(tc--){
        bool f = 1;
        scanf("%d",&n);
        Trie dic;
        char str[15];
        while(n--){
            scanf("%s",str);
            if(f) // if we haven't found any prefix yet
                f &= dic.add_word(str);
        }
        if(f)
            puts("YES");
        else
            puts("NO");
    }
}
