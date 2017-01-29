#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

int dic[543000][30];
char word[50];
string prefix_word;
int node;

void add_word(){
	int cur_node = 0;
	for (int i = 0; word[i]; i++) {
		if (dic[cur_node][word[i] - 'a'] == 0)
			dic[cur_node][word[i] - 'a'] = ++node;
		cur_node = dic[cur_node][word[i] - 'a'];
	}
	dic[cur_node][29] = 1;
	return;
}

void print_all_words(int trie){
	if (dic[trie][29]) // if this a word print it
		puts(prefix_word.c_str());
	for (int j = 0; j < 26;j++) // find if there's a word after this node
		if (dic[trie][j] != 0) {
			prefix_word += (j + 'a'); // backtrack tp print this word
			print_all_words(dic[trie][j]);
			prefix_word.pop_back();
		}
	return;
}

bool find_prefix(){
	int cur_node = 0;
	for (int i = 0; word[i]; i++) { // check if this prefix already exist in the trie
		if (dic[cur_node][word[i] - 'a'] == 0) // if it didn't exist
			return false; 
		cur_node = dic[cur_node][word[i] - 'a'];
	}
	bool found_atleast_one_word = 0; 
	for (int j = 0; j < 26; j++)  // try to find any word start with this prefix
		if (dic[cur_node][j] != 0) {
			found_atleast_one_word = 1;
			prefix_word = word;
			prefix_word += ('a' + j);
			print_all_words(dic[cur_node][j]); // print words with prefix and char j
		}
	return found_atleast_one_word;
}

int main(){
	int number_of_words;
	scanf("%d", &number_of_words);
	while (number_of_words--) {
		scanf("%s", word);
		add_word(); // add word to trie
	}
	int number_of_prefixes;
	scanf("%d", &number_of_prefixes);
	for (int t = 1; t <= number_of_prefixes; t++) {
		scanf("%s", word);
		printf("Case #%d:\n", t);
		if (find_prefix() == false) // if we didn't find any word with that prefix
			puts("No match.");
	}
}
