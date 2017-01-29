#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

char DNA1[205][20], DNA2[205][20];
int dD1[205], dD2[205];

int main(){
    freopen("uva.txt","rt",stdin);
	int T = 0, n;
	while (scanf("%d", &n) == 1){
		map<int ,char> ma;
		if (T++) puts("");
		for (int i = 0; i < n; i++){
			scanf("%s", &DNA1[i]);
			if (DNA1[i][0] <= '9')
				sscanf(DNA1[i], "%d", &dD1[i]);
		}
		for (int i = 0; i < n; i++){
			scanf("%s", &DNA2[i]);
			if (DNA2[i][0] <= '9')
				sscanf(DNA2[i], "%d", &dD2[i]);
		}
		bool edit = false, error = false;
		do{
			edit = false;
			for (int i = 0; i < n;i++)
				if (DNA1[i][0] > '9' && DNA2[i][0] > '9') {
					if (DNA1[i][0] != DNA2[i][0]) {
						error = true;
						break;
					}
				}
				else if (DNA1[i][0] > '9' && DNA2[i][0] <= '9'){
					char &t = ma[dD2[i]];
					if (t == 0)
						edit = 1, t = DNA1[i][0];
					else if (t != DNA1[i][0]){
						error = true;
						break;
					}
				} 
				else if (DNA1[i][0] <= '9' && DNA2[i][0] > '9'){
					char &t = ma[dD1[i]];
					if (t == 0)
						edit = 1, t = DNA2[i][0];
					else if (t != DNA2[i][0]){
						error = true;
						break;
					}
				}
				else{
					char &t1 = ma[dD1[i]], &t2 = ma[dD2[i]];
					if (t1 != 0 && t2 != 0){
						if (t1 != t2) {
							error = true;
							break;
						}
					}
					else if (t1 != 0 && t2 == 0) t2 = t1, edit = 1;
					else if (t2 != 0 && t1 == 0) t1 = t2, edit = 1;
				}
		} while (edit && !error);
		int cnt = 0;
		for (auto it : ma) if (it.second)  cnt++;
		if (error || cnt == 0) puts("NO");
		else{
			puts("YES");
			for (auto it : ma) if (it.second)
				printf("%d %c\n", it.first, it.second);
		}
	}
}
