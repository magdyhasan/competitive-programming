#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int k, n;

int a[64];

string build(int idx, int mi, int mx){
	if (idx == k) return "";
	string ret = "";
	for (int i = idx; i < k; i++) if (a[i] >= mi && a[i] < mx){
		ret = "(";
		ret += "L" + build(i + 1, mi, a[i]); // left
		ret += "R" + build(i + 1, a[i], mx); // right
		ret += ")";
		break;
	}
	return ret;
}

int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d", &n, &k) == 2){
		set<string> s;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < k; j++)
				scanf("%d", &a[j]);
			s.insert(build(0, -12345678, 123456789));
		}
		printf("%d\n", s.size());
	}
}
