#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;


int dic[8000500][30], node;
int prefixes[8000500];
vector<string> words;
int n;
char word[90];

void init(){
	for (int i = 0; i < n * 80 + 50; i++) {
		for (int j = 0; j < 30; j++)
			dic[i][j] = 0;
		prefixes[i] = 0;
	}
	node = 0;
	return;
}

void add_word(){
	int cur_node = 0;
	for (int i = 0; word[i]; i++) {
		if (dic[cur_node][word[i] - 'a'] == 0)
			dic[cur_node][word[i] - 'a'] = ++node, prefixes[cur_node]++; // we added new letter to cur_node in the trie
		cur_node = dic[cur_node][word[i] - 'a'];
	}
	prefixes[cur_node]++; // we added a new word to cur_node
	dic[cur_node][29]++;
	return;
}

int check_typing(string &word_to_type){
	int ret = 1; // we ahve to type the first word
	int cur_node = dic[0][word_to_type[0] - 'a']; // start from the second letter because we already typed the first one
	for (int i = 1; word_to_type[i]; i++) { 
		ret += (prefixes[cur_node] > 1); // if we have more than one letter in this position of trie then we have to type it
		cur_node = dic[cur_node][word_to_type[i] - 'a']; 
	}
	return ret;
}

int main(){
	while (scanf("%d", &n) != EOF) {
		init(); 
		words = vector<string>(n+1);
		for (int i = 0; i < n; i++) {
			scanf("%s", word);
			words[i] = (string(word));
			add_word(); // add word to trie
		}
		int strokes = 0;
		for (int i = 0; i < n; i++)
			strokes += check_typing(words[i]); // check how many strikes needed for this word
		printf("%.2lf\n", (double)strokes / (n*1.0));
	}
}
