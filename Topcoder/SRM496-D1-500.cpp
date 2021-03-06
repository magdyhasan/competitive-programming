/*
first, since verlocity is fixed, we can find all posiible ones and try for each fixed one

now, thinking about the problem like a graph,
some nodes are in left, wanted to be matched with nodes in right
nodes in right >= nodes in left, and each node in left can have at most 2 edges to right

now what we want is number of maximum matching but this NP hard problem

key is that every node in left side can have at most 2 outgoing edges,
so think about one node in right, that may be matched with more than one node
say we are at node x, and fixing distance to be d
node x in right, can have edges with (x-d,x+d) nodes in right at most
and node x-d, can only have edges to (x,x-2*d)

after drawing some examples and noticing the pattern, notice we only have disjoints paths of nodes

so now if we sort nodes in left in ascending order, and find for that node all possible nodes
that might be invloved in this path, there will be 3 cases:
1- nodes in left > nodes in right in this path, this case means this invalid case
2- nodes in left == nodes in right, in this case we only have on arrangment
3- nodes in left < nodes in right, and since this a path between nodes in left and right
nodes in left+1 == nodes in right, like we have one node in left and two nodes in right to choose from
so in this case we can choose from nodes in right where we place nodes in left,
this is just nCk(nodes in right, nodes in left), which in this case is just nodes in right
because nodes in right always equal nodes in left+1
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



class OneDimensionalBalls {
public:
	long long countValidGuesses(vector <int> firstPicture, vector <int> secondPicture);
};


ll calc(set<int> &a, set<int> &b, int d){
	ll ret = 1;
	while (!a.empty()){
		ll u = *a.begin(); // choose first node from left to start out path
		a.erase(a.begin());
		ll firstPicture = 1, secondPicture = 0;// firstPicture == nodes in left, we have one node in left now
		// secondPicture == nodes in right, we have none now
		if (b.find(u - d) != b.end()){// since this smallest one in nodes on left, we can only match it once with u -d
			// because of u-d have another edge, that would u-2*d, but u is already smallest only
			++secondPicture;
			b.erase(u - d);
		}
		//now try to build path, alternating from left to right
		while (b.find(u + d) != b.end()){// find node in right, that is: u+d
			secondPicture++;// we have one more node in right
			b.erase(u + d);
			u = u + d + d;// now try to find another one in this path in left nodes
			if (a.find(u) != a.end()) {
				firstPicture++;
				a.erase(u);
			}
			else// if we can't find left node, we can't continue this path
				break;
		}
		if (firstPicture > secondPicture) return 0LL;// more nodes in left to fit than nodes in right
		if (secondPicture == firstPicture + 1) ret *= secondPicture;// we have path with mutliple ordering
	}
	return ret;
}



long long OneDimensionalBalls::countValidGuesses(vector <int> a, vector <int> b) {
	set<int> ds;
	for (auto i : a) for (auto j : b) if (i != j) // finding all possible distances, handle tha d != 0
		ds.insert(abs(i - j));
	ll ret = 0;
	for (auto d : ds){
		set<int> l(a.begin(), a.end());// sort all nodes in left
		set<int> r(b.begin(), b.end());// sort all nodes in right
		ret += calc(l, r, d);
	}
	return ret;
}


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, long long p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	OneDimensionalBalls *obj;
	long long answer;
	obj = new OneDimensionalBalls();
	clock_t startTime = clock();
	answer = obj->countValidGuesses(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	}
	else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	}
	else if (hasAnswer) {
		cout << "Match :-)" << endl;
	}
	else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <int> p0;
	vector <int> p1;
	long long p2;

	{
		// ----- test 0 -----
		int t0[] = { 12, 11 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { 10, 11, 13 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 3ll;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = { 1, 2, 3 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { 1, 2, 3 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 0ll;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = { 1, 3 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { 1, 3 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 1ll;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = { 7234 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { 6316, 689156, 689160, 689161, 800000, 1000001 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 6ll;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		int t0[] = { 6, 2, 4 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		int t1[] = { 1, 2, 3, 4, 5, 7, 8 };
		p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
		p2 = 7ll;
		all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	}
	else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
