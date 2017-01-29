#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;


char bo[10];

inline bool checkWin(char ch){
    if(bo[0] == ch && bo[4] == ch && bo[8] == ch) // same diagonal
        return 1;
    if(bo[2] == ch && bo[4] == ch && bo[6] == ch) // same diagonal
        return 1;
    for(int i=0;i<3;i++) // check each row and column
        if( (bo[i*3] == bo[i*3+1] && bo[i*3+1] == bo[i*3+2] && bo[i*3] == ch) ||
            (bo[i] == bo[i+3] && bo[i+3] == bo[i+6] && bo[i] == ch ) )
            return 1;
    return 0;
}

int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        scanf("%s",bo);
        scanf("%s",bo+3);
        scanf("%s",bo+6);
        bool x = checkWin('X');
        bool o = checkWin('O');
        int xn = count(bo,bo+9,'X'); // count X's
        int on = count(bo,bo+9,'O'); // count O's
        if(x && o) // if both won then it's no ( because when first one won it must been stopped )
            puts("no");
        else if(o){
            if( xn == on ) // if O wins then number of O's must be equal to number of X's because X's goes first
                puts("yes");
            else
                puts("no");
        }
        else if(x){
            if(xn == on+1) // if X wins then X's == O's+1 because X's goes first
                puts("yes");
            else
                puts("no");
        }
        else if(xn == on+1 || xn == on ) // if x is one move ahead from O or X is same as O and X is going to do move now
            puts("yes");
        else
            puts("no");
    }
}
