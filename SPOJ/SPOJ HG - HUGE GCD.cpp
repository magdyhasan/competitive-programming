#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

void fact(int n, map<ll, int> &c){
	for (ll i = 2; i*i <= n; i++)
		if (n%i == 0) {
			int cnt = 0;
			while (n%i == 0) {
				n /= i;
				cnt++;
			}
			c[i] += cnt;
		}
	if (n > 1)
		c[n] += 1;
}

string multiply(string a, string b){ // reverse after return to get number from left to right
	int ret[1050] = {};
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			ret[i + j] += (a[i] - '0')*(b[j] - '0');
	for (int i = 0; i < 1000; i++)
		ret[i + 1] += ret[i] / 10, ret[i] %= 10;
	string res = "";
	int i = 1000;
	while (!ret[i]) i--;
	for (; i >= 0; i--) res += (ret[i] + '0');
	return res;
}

int main(){
    freopen("uva.txt","rt",stdin);
	int n, m;
	scanf("%d", &n);
	int t;
	map<ll, int> c1, c2;
	for (int i = 0; i < n; i++){
		scanf("%d", &t);
		fact(t, c1);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) scanf("%d", &t), fact(t, c2);
	string ret = "1";
	for (auto i : c1){
		ll nu = i.first;
		int comm = min(i.second, c2[nu]);
		string pr = to_string(nu), tp = pr;
		for (int po = 0; po < comm - 1; po++)  pr = multiply(pr, tp);
		if (comm == 0) pr = "1";
		ret = multiply(ret, pr);
	}
	reverse(ret.begin(), ret.end());
	for (int i = min(8, (int)ret.size()-1); i >= 0; i--)
		putchar(char(ret[i]));
}
