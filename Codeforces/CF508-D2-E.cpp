/*
 * greedy:
 * main observation is that inserting ')' have to be in order
 * so it's always better to close when we have chance, else we add opening
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 300500;
int l[maxn], r[maxn];
int n;

void solve(){
	cin >> n;
	deque<pair<int,int>> q;
	for(int i=0;i<n;i++) cin >> l[i] >> r[i];
	string ret;
	int j =0;
	for(int i=0;i<2*n;i++){
		if(!q.empty() && q.front().first <= i){
			auto u = q.front() ; q.pop_front();
			if(u.second < i){
				//cout << u.second;
				cout << "IMPOSSIBLE";
				return;
			}
			ret += ')';
		}else if(j<n){
			ret += '(';
			q.emplace_front(i+l[j],i+r[j]);
			++j;
		}else{
			cout << "IMPOSSIBLE";
			return;
		}
		//cout << ret << endl;
	}
	cout << ret;
}

int main() {
	solve();
}
