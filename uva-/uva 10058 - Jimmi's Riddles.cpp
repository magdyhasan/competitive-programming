#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

string verbs[] = { "hate", "love", "know", "like" };
string nouns[] = { "tom", "jerry", "goofy", "mickey", "jimmy", "dog", "cat", "mouse" };

string trimeSpaces(string st){
	while (st.size() > 0 && st[0] == ' ') st = st.substr(1);
	while (st.size() > 0 && st.back() == ' ') st.pop_back();
	return st;
}

bool isVERB(string st){
	for (string vs : verbs) if (vs == st) return true;
	return false;
}

bool isNOUN(string st){
	for (string noun : nouns) if (noun == st) return true;
	return false;
}


bool isARTICLE(string st){
	return (st == "a" || st == "the");
}

bool isACTOR(vector<string> vec){
	if (vec.size() == 1) return isNOUN(vec[0]);
	if (vec.size() == 2) return (isARTICLE(vec[0]) && isNOUN(vec[1]));
	return false;
}

bool isACTIVE_LIST(vector<string> vec){
	if (isACTOR(vec)) return true;
	vector<string> t;	
	for (int i = 0; i < vec.size(); i++){
		if (vec[i] == "and"){
			vector<string> t2;
			for (int j = i + 1; j < vec.size(); j++) t2.push_back(vec[j]);
			if (isACTIVE_LIST(t) && isACTOR(t2)) return true;
		}
		t.push_back(vec[i]);
	}
	return false;
}

bool isACTION(vector<string> vec){
	vector<string> t;
	for (int i = 0; i + 1 < vec.size(); i++){
		if (i && isVERB(vec[i])){
			vector<string> t2;
			for (int j = i + 1; j < vec.size(); j++) t2.push_back(vec[j]);
			if (isACTIVE_LIST(t) && isACTIVE_LIST(t2)) return true;
		}
		t.push_back(vec[i]);
	}
	return false;
}

bool isSTATEMENT(vector<string> vec){
	if (isACTION(vec))	 return true;
	vector<string> t;
	for (int i = 0; i + 1 < vec.size(); i++){
		if (i && vec[i] == ","){
			vector<string> t2;
			for (int j = i + 1; j < vec.size(); j++) t2.push_back(vec[j]);
			if (isACTION(t2)) return true;
		}
		t.push_back(vec[i]);
	}
	return false;
}

int main(){
    freopen("uva.txt","rt",stdin);
	char st[1000500];
	while (gets(st)){
		istringstream iss(st);
		string t;
		vector<string> vec;
		while (iss >> t){
			while (t.size() > 0 && t.back() == 's') t.pop_back();
			vec.push_back(t);
		}
		if (isSTATEMENT(vec)) puts("YES I WILL");
		else puts("NO I WON'T");
	}
}
