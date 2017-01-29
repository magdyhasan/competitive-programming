#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<list>
#include<utility>
#include<stack>
using namespace std;

typedef pair<char,char> pcc;

char line[200];
list< stack< pcc > > deck;
stack< pcc > st;
#define mp(a,b) make_pair(a,b)
#define c1 top().first
#define c2 top().second


void parse(){
    int j = 0;
    char ch1,ch2;
    while(sscanf(line+j,"%c%c",&ch1,&ch2) == 2){
        st.push(mp(ch1,ch2));
        deck.push_back(st);
        st.pop();
        j += 3;
    }
    return;
}

void solve(){
    int j = 0;
    list< stack< pcc > >::iterator card = deck.begin(),temp;
    while(card != deck.end()){
        bool f = 1; // check if we made change
        for(int l=3;l>0;l -= 2){ // try to move left 3 steps or 1 step
            if(j-l < 0)
                continue;
            temp = card;
            for(int t=0;t<l;t++)
                temp--; // go left by l
            if((*temp).c1 == (*card).c1 || (*temp).c2 == (*card).c2 ){ // if same cards
                (*temp).push((*card).top()); // push care onto temp
                (*card).pop(); // remove card
                if((*card).size() == 0) // if this pile is empty now
                    deck.erase(card);
                card = temp , j -= l; // go back to what we've changed
                f = 0; // we made a change
                break;
            }
        }
        if(f){
            card++;
            j++;
        }
    }
    return;
}

int main(){
    while(gets(line)){
        if(line[0] == '#')
            break;
        deck.clear();
        parse(); // read cards from first line
        gets(line); // read second line
        parse(); // read cards from second line
        solve();
        printf("%d pile%s remaining:",deck.size(),deck.size() == 1 ? "":"s");
        for(auto pile:deck)
            printf(" %d",pile.size());
        puts("");
    }
}
