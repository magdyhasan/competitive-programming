#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

map<string, string> d, rd;


// rotate functions from http://mypaper.pchome.com.tw/zerojudge/post/1324754935
string left1(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[11], t2 = tn[10];
	tn[11] = tn[9], tn[10] = tn[8], tn[9] = tn[7];
	tn[8] = tn[6], tn[7] = tn[5], tn[6] = tn[4];
	tn[5] = tn[3], tn[4] = tn[2], tn[3] = tn[1];
	tn[2] = tn[0], tn[1] = t1, tn[0] = t2;
	return tn;
}
string right2(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[9], t2 = tn[10];
	tn[9] = tn[11], tn[10] = tn[12], tn[11] = tn[13];
	tn[12] = tn[14], tn[13] = tn[15], tn[14] = tn[16];
	tn[15] = tn[17], tn[16] = tn[18], tn[17] = tn[19];
	tn[18] = tn[20], tn[19] = t1, tn[20] = t2;
	return tn;
}
string left3(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[9], t2 = tn[10];
	tn[9] = tn[11], tn[10] = tn[0], tn[11] = tn[1];
	tn[0] = tn[2], tn[1] = tn[3], tn[2] = tn[4];
	tn[3] = tn[5], tn[4] = tn[6], tn[5] = tn[7];
	tn[6] = tn[8], tn[7] = t1, tn[8] = t2;
	return tn;
}
string right4(string v) {
	static char t1, t2;
	string tn;
	tn = v;
	t1 = tn[11], t2 = tn[10];
	tn[11] = tn[9], tn[10] = tn[20], tn[9] = tn[19];
	tn[20] = tn[18], tn[19] = tn[17], tn[18] = tn[16];
	tn[17] = tn[15], tn[16] = tn[14], tn[15] = tn[13];
	tn[14] = tn[12], tn[13] = t1, tn[12] = t2;
	return tn;
}


void BFS1(string s){
	rd[s] = "";
	queue<string> q;
	q.push(s);
	string u, nxt;
	while (!q.empty()){
		u = q.front();	q.pop();
		string &mo = rd[u];
		if (mo.size() >= 8) continue;
		// 1 left
		nxt = left3(u);
		if (rd.find(nxt) == rd.end())
			rd[nxt] = "1" + mo, q.push(nxt);
		// 2 right
		nxt = right4(u);
		if (rd.find(nxt) == rd.end())
			rd[nxt] = "2" + mo, q.push(nxt);
		// 3 left
		nxt = left1(u);
		if (rd.find(nxt) == rd.end())
			rd[nxt] = "3" + mo, q.push(nxt);
		// 4 right
		nxt = right2(u);
		if (rd.find(nxt) == rd.end())
			rd[nxt] = "4" + mo, q.push(nxt);
	}
}

string BFS2(string s){
	d[s] = "";
	queue<string> q;
	q.push(s);
	string u, nxt;
	while (!q.empty()){
		u = q.front();	q.pop();
		string mo = d[u];
		if (rd.find(u) != rd.end()) return mo + rd[u];
		if (mo.size() == 8) continue;
		// 1 left
		nxt = left1(u);
		if (d.find(nxt) == d.end())
			d[nxt] = mo + "1", q.push(nxt);
		// 2 right
		nxt = right2(u);
		if (d.find(nxt) == d.end())
			d[nxt] = mo + "2", q.push(nxt);
		// 3 left
		nxt = left3(u);
		if (d.find(nxt) == d.end())
			d[nxt] = mo + "3", q.push(nxt);
		// 4 right
		nxt = right4(u);
		if (d.find(nxt) == d.end())
			d[nxt] = mo + "4", q.push(nxt);
	}
	return "NO SOLUTION WAS FOUND IN 16 STEPS";
}

int main(){
    freopen("uva.txt","rt",stdin);
	BFS1("034305650121078709:90");
	int tc;
	scanf("%d", &tc);
	while (tc--){
		string st = "";
		int t;
		for (int i = 0; i < 24; i++){
			scanf("%d", &t);
			if (i < 21)	st += (t + '0');
		}
		string ret = BFS2(st);
		if (st == "034305650121078709:90")  ret = "PUZZLE ALREADY SOLVED";
		puts(ret.c_str());
	}
}
