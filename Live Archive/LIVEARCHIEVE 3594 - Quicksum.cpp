#include<bits/stdc++.h>
using namespace std;



int main(){
    freopen("uva.txt","rt",stdin);
	string li;
	while (getline(cin, li)){
		if (li[0] == '#') break;
		long long ret = 0;
		for (int i = 0; i < li.size(); i++) if (li[i] != ' ')
			ret += (li[i] - 'A' + 1)*(i + 1);
		printf("%lld\n", ret);
	}
}

