#include<stdlib.h>
#include<stdio.h>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

char li[100500];
int sqr(int x){ return x*x; }

int main(){
    freopen("uva.txt","rt",stdin);
	int T; scanf("%d", &T);
	gets(li);
	gets(li);
	while (T--){
		gets(li);
		int x1, y1, x2, y2;
		double di = 0;
		while (gets(li) && li[0] != '\0'){
			sscanf(li, "%d%d%d%d", &x1, &y1, &x2, &y2);
			di += sqrt(sqr(x2 - x1) + sqr(y2 - y1));
		}
		di /= 1000.;
		double hs = di*2. / 20.;
		int ms = (int)round(hs * 60);
		printf("%d:%02d\n", ms / 60, ms % 60);
		if (T) puts("");
	}
}

