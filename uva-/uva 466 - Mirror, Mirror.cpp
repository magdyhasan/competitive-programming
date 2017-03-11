#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
 

typedef vector<string> vs;

int n;


vs roatate90(vs a){
	vs ret = a;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		ret[j][n - i - 1] = a[i][j];
	return ret;
}

vs reflect(vs a){
	vs ret = a;
	for (int i = 0; i < n; i++)
		ret[i] = a[n - i - 1];
	return ret;
}

int deg[] = { 90, 180, 270 };

char st1[100], st2[100];

int main(){
    freopen("uva.txt","rt",stdin);
	int tc = 1;
	while (scanf("%d", &n) == 1){
		vs a(n, ""), b(n, "");
		for (int i = 0; i < n; i++){
			scanf("%s%s", st1, st2);
			a[i] = st1, b[i] = st2;
		}
		vs t = a;
		int i;
		for (i = 0; i < 3; i++){
			t = roatate90(t);
			if (t == b) break;
		}
		if (a == b) printf("Pattern %d was preserved.\n", tc);
		else if (i == 3){
			t = a;
			t = reflect(t);
			if (t == b) printf("Pattern %d was reflected vertically.\n", tc);
			else{
				for (i = 0; i < 3; i++){
					t = roatate90(t);
					if (t == b) break;
				}
				if (i == 3) printf("Pattern %d was improperly transformed.\n", tc);
				else printf("Pattern %d was reflected vertically and rotated %d degrees.\n", tc, deg[i]);
			}
		}
		else
			printf("Pattern %d was rotated %d degrees.\n", tc, deg[i]);
		++tc;
	}
}
