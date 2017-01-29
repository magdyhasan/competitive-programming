#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;

string morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

int dic[200005][30];
ll dp[10005];
int max_node;
vector<int> char_pos[10005];
char morse_sequence[10005], temp[30];
int sequence_len;


void init(){
	max_node = 0; // start from node 0 in the Trie
	for (int i = 0; i < 200005; i++) {
		if (i < 10005)
			dp[i] = -1, char_pos[i].clear(); 
		for (int j = 0; j < 30; j++)
			dic[i][j] = 0;
	}
}

void add_word(){ // add a new word to the dictionary
	int cur_node = 0; // start from root ( node 0 )
	for (int i = 0; temp[i]; i++) {
		if (dic[cur_node][temp[i] - 'A'] == 0) // if we didn't have that char in a path in the trie already
			dic[cur_node][temp[i] - 'A'] = ++max_node; // make a new node for it
		cur_node = dic[cur_node][temp[i] - 'A']; //go to next char/node
	}
	dic[cur_node][29]++; // mark this as a word
	return;
}

void get_char_from_sequence(){ // find all possible decoding of morse code into a char from each position in the morse sequence
	for (int i = 0; i < sequence_len; i++)
		for (int j = 0; j < 26; j++) { // try each morse code
			bool is_match = (i + morse[j].size() <= sequence_len ? 1 : 0);
			for (int k = 0; k < morse[j].size(); k++) 
				if (morse[j][k] != morse_sequence[i + k])
					is_match = 0;
			if (is_match)
				char_pos[i].push_back(j);
		}
	return;
}

ll rec(int idx, int first_pos, int node){
	if (idx == sequence_len) 
		return dic[node][29];
	if (first_pos == idx && dp[idx] != -1) // if we are starting a new word from already calculated position
		return dp[idx];
	ll ret = 0;
	for (int i = 0; i < char_pos[idx].size(); i++) // find all possible char from this position
		if (dic[node][char_pos[idx][i]]) // if this a prefix in any word in the Trie
			ret += rec(idx + morse[char_pos[idx][i]].size(), first_pos, dic[node][char_pos[idx][i]]); // try going into that path
	if (dic[node][29]) // if this a word in dictionary
		ret += (ll)dic[node][29] * rec(idx, idx, 0);  // nw we have a word in the dictionary and we start finding a new word
	if (first_pos == idx)
		dp[idx] = ret;
	return ret;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		init();
		scanf("%s", morse_sequence);
		sequence_len = strlen(morse_sequence);
		int N;
		scanf("%d", &N);
		while (N--) {
			scanf("%s", temp);
			add_word(); // add the new word to the dictionary
		}
		get_char_from_sequence();
		printf("%lld\n", rec(0, 0, 0));
	}
}
