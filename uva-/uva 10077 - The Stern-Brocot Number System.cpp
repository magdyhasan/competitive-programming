#include<stdlib.h>
#include<stdio.h>
#include<string>
using namespace std;

struct fraction{ 
	int num, den;
	fraction()	{}
	fraction(int a, int b) : num(a), den(b)	{}
	
	fraction operator +(const fraction &co){
		return fraction(num + co.num, den + co.den);
	}

	bool operator > (const fraction &co){
		return ((num * co.den) > (den*co.num));
	}
	bool operator < (const fraction &co){
		return ((num * co.den) < (den*co.num));
	}
};

fraction target, tfraction;

int main(){
	while (scanf("%d%d",&target.num,&target.den)) {
		if (target.num == 1 && target.den == 1) 
			break;
		fraction prvl(0, 1), mid(1, 1), prvr(1, 0); // make the root of the tree
		string ans = "";
		while (1) {
			if (target > mid) { // if we want a bigger number then we'll go right
				prvl = mid; 
				mid = prvr + mid;
				ans += "R";
			}
			else if (target < mid) { // if we want a smaller number we'll go left
				prvr = mid;
				mid = prvl + mid;
				ans += "L";
			}
			else
				break;
		}
		puts(ans.c_str());
	}
}
