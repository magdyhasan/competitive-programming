#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <algorithm>
using namespace std;

typedef long long ll;

ll get_digit(ll x){ // get number of digit
	ll ret = 0;
	while (x > 0) {
		ret++;
		x /= 10;
	}
	return ret;
}

ll accum_sum[42765]; // save number of digits in a certin level ( leve 1 = 1, level 2 = 1 2, level 3 = 1 2 3 )
char st[1000000] = {};

void init(){ // generate number of digits in all levels
	ll tot = 0;
	ll cur_num = 1, cur_len = 0;
	ll mx = 4147483647; 
	int accum_len = 0; 
	accum_sum[0] = 0;
	while (tot <= mx) {
		sprintf(st + strlen(st), "%lld", cur_num); // make a string of all digits in the max level
		tot += cur_len + get_digit(cur_num++); // add the number of digits of current level to previous level number of digits
		cur_len += get_digit(cur_num - 1); // increase level length we have till now (1234) this level has length 4
		accum_sum[++accum_len] = tot; 
	}
	return;
}


int main(){
	init(); // get all number of 
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		ll i;
		scanf("%lld", &i);
		int pos = lower_bound(accum_sum, accum_sum + 42765, i) - accum_sum; // get the level of i
		i -= accum_sum[pos-1] + 1; // find i in that level
		printf("%c\n", st[i]);
	}
}
