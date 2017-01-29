#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

int prime_factors[40000], prime_factors_count[40000];

int main(){
	string line;
	while (getline(cin,line)) {
		int p = 1, prime,power; // p is the prime we will make from the prime base represntation
		istringstream iss(line);
		while (iss >> prime ) {
			if (prime == 0)
				return 0;
			iss >> power;
			for (int i = 1; i <= power; i++) // get prime^power
				p *= prime;
		}
		p--;  // get p-1
		int cur_prime = 0;
		for (int i = 2; i*i <= p; i++) // get orime factors of p-1
			if (p%i == 0) {
				int i_cnt = 0;
				while (p%i == 0)
					p /= i, i_cnt++;
				prime_factors[cur_prime] = i;
				prime_factors_count[cur_prime++] = i_cnt;
			}
		if (p > 1)
			prime_factors[cur_prime] = p, prime_factors_count[cur_prime++] = 1;
		for (int i = cur_prime - 1; i >= 0; i--) { // display it on decreasing order
			if (i != cur_prime - 1)
				cout << " ";
			cout << prime_factors[i] << " " << prime_factors_count[i];
		}
		cout << "\n";
	}
}
