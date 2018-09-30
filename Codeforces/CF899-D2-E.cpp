/*
	we need to keep each consective same numbers as intervals
	so use set of intervals {index, count of this number }

	now, when we want to remove we need largest number with least index
	for this we use another set { count of this number, -1 * index }
	this set end have the interval we need to remove as it have largest count and smallest index

	now when we remove this interval, notice we might need to merge 2 interval
	so it need careful check of the iterators
*/
#include<bits/stdc++.h>
using namespace std;


const int maxn = 300500;

int a[maxn];


int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	set<pair<int, int>> in, nu;
	for (int i = 0; i < n;){
		int j = i, cnt = 0;
		while (j < n && a[j] == a[i]) j++, cnt++;
		nu.insert({ cnt, -i });
		in.insert({ i, cnt });
		i = j;
	}
	int ret = 0;
	while (!in.empty()){
		ret++;
		auto it = nu.end();
		it--;
		auto it2 = in.lower_bound({ -it->second, it->first });
		auto er = it2, it3 = it2;
		auto ere = ++it2, erb = --it3;
		if (er != in.begin() && ere != in.end()){
			int i = erb->first, j = ere->first;
			if (a[i] == a[j]){
				in.insert({ i, erb->second + ere->second });
				nu.insert({ erb->second + ere->second, -i });

				nu.erase({ erb->second, -i });
				nu.erase({ ere->second, -j });

				in.erase(erb);
				in.erase(ere);
			}
		}
		nu.erase(it);
		in.erase(er);
	}
	printf("%d\n", ret);
}