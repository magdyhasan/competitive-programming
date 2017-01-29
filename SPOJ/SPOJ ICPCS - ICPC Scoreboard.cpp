#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std;


int T, P, A, S;

struct team{
	int solved_problems, time_penalty, submission_penalty, id;

	bool operator < (const team &a) const{ // sort standing according to number of solved problems then consider penalties
		if (solved_problems != a.solved_problems)
			return solved_problems > a.solved_problems;
		return (time_penalty + submission_penalty) < (a.time_penalty + a.submission_penalty);
	}
} teams[105], temp[105];

bool equal(){
	for (int i = 0; i < T - 1; i++) {
		if (temp[i].solved_problems != temp[i + 1].solved_problems) 
			continue;
		if (temp[i].time_penalty + temp[i].submission_penalty > temp[i + 1].time_penalty + temp[i + 1].submission_penalty) // if penalty of team i > penalty of team i+1 then standing will change
			return 0;
		if (temp[i].time_penalty + temp[i].submission_penalty == temp[i + 1].time_penalty + temp[i + 1].submission_penalty // if there's was a tie in the original standing
			&& teams[i].time_penalty + teams[i].submission_penalty < teams[i + 1].time_penalty + teams[i + 1].submission_penalty) // and now it's not a tie
			return 0;
		if (temp[i].time_penalty + temp[i].submission_penalty < temp[i + 1].time_penalty + temp[i + 1].submission_penalty // if there wasn't a tie in the original standing
			&& teams[i].time_penalty + teams[i].submission_penalty == teams[i + 1].time_penalty + teams[i + 1].submission_penalty)// and now there's a tie
			return 0;
	}
	return 1;
}


int main(){
    freopen("uva.txt","rt",stdin);
	while (scanf("%d%d",&T,&P) && T && P) {
		for (int i = 0; i < T; i++){
			teams[i].solved_problems = teams[i].time_penalty = teams[i].submission_penalty = 0; // initialize team information
			teams[i].id = i;
			for (int j = 0; j < P; j++) {
				S = -1;
				scanf("%d%*c%d", &A, &S);
				if (S != -1) {
					teams[i].solved_problems++;  // set team information
					teams[i].submission_penalty += (A - 1) * 20;
					teams[i].time_penalty += S;
				}
			}
		}
		sort(teams, teams + T); // sort standing
		int l = 1, h = 5000; // linear search on the penalty range
		int lower = 0, upper = 0;
		while (l <= h) {
			for (int i = 0; i < T; i++) {
				temp[i] = teams[i]; // make a temporary save of the teams with the new penalty
				temp[i].submission_penalty = (teams[i].submission_penalty / 20)*l;
			}
			if (equal()) { // check if standing still the same
				upper = l; // move upper
				if (lower == 0) // set lower to lowest possible value
					lower = l;
			}
			l++;
		}
		if (upper == 5000) // if upper is too big
			printf("%d *\n", lower);
		else
			printf("%d %d\n", lower, upper);
	}
}
