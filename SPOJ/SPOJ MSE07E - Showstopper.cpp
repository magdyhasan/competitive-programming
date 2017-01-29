#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;

typedef long long ll;
const ll MAX = (ll)1e6 + 150;

ll x[MAX], y[MAX], z[MAX];
ll numberOfLines;

ll odd(ll range){ // find if the odd refernce is in the range from 1 to range
	ll sum = 0;
	for (int i = 0; i < numberOfLines; i++) {
		if (range < x[i]) // x[i] is not in range form 1 to x[i]
			continue;
		sum += (min(range, y[i]) - x[i] ) / z[i]+1; // find how many refences added by that line
	}
	return sum;
}

void solve(){
	ll l = 1, r = (1LL << 40), pos = -1; 
	while (l <= r) { // binary search to find the odd in a pattern like this 0001000 ( if it exist) 
		ll mid = (l + r) / 2;
		if (odd(mid) & 1) // if the one is to our left
			r = mid - 1, pos = mid;
		else // the one ( if exist ) is to our right
			l = mid + 1;
	}
	if (pos == -1) // if we didn't find any odd refernce
		cout << "no corruption\n";
	else
		cout << pos << " " << odd(pos) - odd(pos - 1) << "\n";
	numberOfLines = 0;
	return;
}

int main(){
	string line;
	while (getline(cin,line)) {
		if (line.size() < 5) { // check if line is empty ( don't have 3 numbers on it because he might has \r so it's size will not be 0)
			if (numberOfLines != 0) // if we have readed some data
				solve();
			continue;
		}
		istringstream(line) >> x[numberOfLines] >> y[numberOfLines] >> z[numberOfLines]; // read x y z
		numberOfLines++; // we have readed a new line of data
	}
	if (numberOfLines > 0)
		solve();
}
