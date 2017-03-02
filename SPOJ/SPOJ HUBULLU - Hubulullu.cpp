#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;


int main(){
	int T; scanf("%d", &T);
	while (T--){
		int n, p;
		scanf("%d%d", &n, &p);
		puts(p ? "Pagfloyd wins." : "Airborne wins.");
	}
}
