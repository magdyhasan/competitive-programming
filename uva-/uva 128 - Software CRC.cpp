#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;

const long long g = 34943;

int main(){
    freopen("uva.txt","rt",stdin);
	char line[1005];
	while (gets(line) && line[0] != '#') {
		long long m = 0;
		int len = strlen(line);
		for (int i = 0; i < len; i++)
			m = ((m * 256) + line[i]) % g; // get m2
		m <<= 16; // get m 
		m %= g;
		int hex = (g - m) % g; // get the value needed 
		printf("%02X %02X\n", hex >> 8, hex % 256);
	}
}
