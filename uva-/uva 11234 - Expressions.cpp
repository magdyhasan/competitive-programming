#include<stdlib.h>
#include<stdio.h>
#include<queue>
#include<string.h>
#include<cctype>
using namespace std;

/*
The idea is to build the expression tree
and then traversal it from down right level by level ( so basically opposite of inorder traversal )
*/
char s[10001];


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int lvl=0,mxlvl=0;
        queue<char> tree[6000]; // this our tree ( each level is represented by a queue )
        for(int i=strlen(s)-1;i>=0;i--) // build the tree from the right of the string
            if(isupper(s[i])){ // if it operator make a new level ( this operator is the parent of it ) and add next operands to this level
                tree[lvl++].push(s[i]);
                mxlvl = max(mxlvl,lvl); // get max level to traversal the tree later from it
            }else{ // if it operand ( number or lower case according to problem statement ) we push it in the current level
                tree[lvl].push(s[i]);
                while(tree[lvl].size() % 2 == 0) // if we have 2 nodes as operands then we can't add more here ( we go up till we find level that need another operand )
                    lvl--;
            }
        for(int i=mxlvl;i>=0;i--) // now we go from down right of the tree
            while(!tree[i].empty()){ // we take all elements in that level then go to higher level
                putchar(tree[i].front());
                tree[i].pop();
            }
        puts("");
    }
}
