#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int GCD(int a, int b){
	return (b == 0 ? a : GCD(b, a%b));
}

int main(){
	char word[50];

	while (scanf("%s",word)){
		if (word[0] == '#')
			break;
		int cnt[50] = {};
		int len = strlen(word);
		for (int i = 0; i < len; i++)
			cnt[word[i] - 'a']++; // get the count of each char in word
		long long ret = 1; // start with index 1
		for (int i = 0; i < len; i++) { // go over all chars of word
			for (int j = 0; j < (word[i] - 'a'); j++) { // go over all chars smaller than word[i] ( i can put it in place of word[i] and have smaller word )
				if (cnt[j] == 0) // if we don't have any of that char
					continue;
				cnt[j]--; // consider we used this char at the beginning of the new word
				int up[50] = {}; // this will have the number of perumtation for all the string ( without removing the reptation )
				for (int k = 2; k < len - i; k++) // if we are at word with length 4 .. we will have 4! (4*3*2) in up array
					up[k] = k;
				for (int k = 0; k < 26;k++) //go over all chars in the new formed word
					if (cnt[k]) { // if we have any of this char
						for (int down = 2; down <= cnt[k]; down++) { // we will remove its reptation 4!/cnt[k]!
							int _down = down; // this one of the factorial of cnt[k]
							for (int _up = 2; _up < len - i; _up++) { // we'll try to cancel it with any from up
								int gcd = GCD(up[_up], _down);
								_down /= gcd;
								up[_up] /= gcd;
							}
						}

					}
				long long temp = 1; // now what remains is only in up ( number of possible arrangnment of new smaller word )
				for (int k = 2; k < len - i; k++) 
					temp *= up[k];
				ret += temp; // we add this possible number to the total count
				cnt[j]++; // return the char we consider we used it
			}
			cnt[word[i] - 'a']--; // move to a new place of the word ( delete that char from word )
		}
		printf("%10lld\n",ret);
	}
}
