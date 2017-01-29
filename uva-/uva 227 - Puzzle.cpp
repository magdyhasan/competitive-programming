#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char x[7][7],ch[1005],moves[1005];
int posi,posj;

bool read(){
    for(int i=0;i<5;i++){
        gets(x[i]);
        if( i == 0 && x[i][0] == 'Z')
            return 0;
        for(int j = 0;j<5;j++) // find space position
            if(x[i][j] == ' ')
                posi = i, posj = j;
    }
    return 1;
}

inline bool isValdi(int i,int j){
    return (i < 5 && i >= 0 && j >= 0 && j < 5);
}

void solve(){
    bool ok = 1; // if puzzle is valid
    for(;;){
        gets(ch);
        for(int i=0;ch[i];i++)
        if(ch[i] == 'A'){ // simulate the problem
            if(!isValdi(posi-1,posj))
                ok = 0;
            swap(x[posi][posj],x[posi-1][posj]);
            posi = posi-1, posj = posj;

        }else if(ch[i] == 'B'){
            if(!isValdi(posi+1,posj))
                ok = 0;
            swap(x[posi][posj],x[posi+1][posj]);
            posi = posi+1, posj = posj;

        }else if(ch[i] == 'R'){
            if(!isValdi(posi,posj+1))
                ok = 0;
            swap(x[posi][posj],x[posi][posj+1]);
            posi = posi, posj = posj+1;

        }else if(ch[i] == 'L'){
            if(!isValdi(posi,posj-1))
                ok = 0;
            swap(x[posi][posj],x[posi][posj-1]);
            posi = posi, posj = posj-1;

        }else if(ch[i] == '0') // at end of moves
            goto end;
    }
    end:
    if(ok) // if valid
        for(int i=0;i<5;i++)
            for(int j=0;j<5;j++)
                printf(j == 4 ? "%c\n":"%c ",x[i][j]);
    else
        puts("This puzzle has no final configuration.");
    return;
}

int main(){
    int tc = 0;
    while(1){
        if(!read())
            break;
        if(tc)
            puts("");
        printf("Puzzle #%d:\n",++tc,posi,posj);
        solve();
    }
}
