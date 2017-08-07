#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uva.txt","rt",stdin);
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	bool f = 0;
	int ret;
	if (a >= c) {
		printf("%d\n", a);
		return 0;
	}
	while (true){
		f = !f;
		if (f) {
			if (a + b >= c) {
				ret = c;
				break;
			}
			a += b;
		}
		else {
			if (c - d <= a) {
				ret = a;
				break;
			}
			c -= d;
		}
	}
	cout << ret;
}

