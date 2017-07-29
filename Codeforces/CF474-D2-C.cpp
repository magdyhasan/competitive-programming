#include <bits/stdc++.h>
using namespace std;
#define all(v)           ((v).begin()), ((v).end())
#define sz size()
#define clr(v,d)         memset(v,d,sizeof(v))
#define rep(i, v)        for(int i=0;i<(v).sz;++i)
#define lp(i, n)         for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)     for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)     for(int i=(j);i>=(int)(n);--i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define DB1(a)          std::cout<<#a<<"="<<(a)<<endl
#define DB2(a,b)        std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<endl
#define DB3(a,b,c)      std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<endl
#define DB4(a,b,c,d)    std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<endl
#define DB5(a,b,c,d,e)  std::cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<endl
typedef pair<int, int> pii;
typedef long long ll;
const int  MAX = (int)1000 + 5;
const int  inf = (int)1e7;
const double EPS = 1e-9;

int dcmp(double a, double b) { return fabs(a - b) <= EPS ? 0 : a < b ? -1 : 1; }




struct Double {
	double d;
	Double() { d = 0.0; };
	Double(double d) : d(d) {}
	bool operator < (const Double& D) const {
		return dcmp(d, D.d) < 0;
	}
	bool operator > (const Double& D) const {
		return dcmp(d, D.d) > 0;
	}
	bool operator == (const Double& D) const {
		return dcmp(d, D.d) == 0;
	}
};


const double PI = acos(-1.0);

typedef complex<double> point;
#define X real()
#define Y imag()
#define angle(a)                (atan2((a).imag(), (a).real()))
#define vec(a,b)                ((b)-(a))
#define length(a)               (hypot((a).imag(), (a).real()))
#define rotateO(p,ang)          ((p)*exp(point(0,ang)))
#define rotateA(p,ang,about)    (rotateO(vec(about,p),ang)+about)

bool iSsquare(vector<point> p){
	map<Double, vector<pii> > ma;
	rep(i, p)
		lpi(j, i + 1, p.sz)
		ma[length(p[i] - p[j])].pb(mp(i, j));
	if (ma.sz != 2)  return 0;
	auto side = ma.begin();
	auto diagonal = ma.begin(); diagonal++;

	if (side->se.sz != 4 || diagonal->se.sz != 2) return 0;

	set<int> s = { diagonal->se[0].fi, diagonal->se[1].fi,
		diagonal->se[0].se, diagonal->se[1].se };
	return (s.sz == 4);
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("ci.in", "rt", stdin);
#endif
	cin.tie(NULL); ios_base::sync_with_stdio(false);
	int n;  cin >> n;
	lp(tq, n){
		vector<point> ho(4);
		vector<point> pos(4);
		int a, b, x, y;
		lp(i, 4){
			cin >> x >> y >> a >> b;
			ho[i] = point(a, b);     pos[i] = point(x, y);
		}
		int ret = inf;
		for (int r1 = 0; r1<4; r1++){

			point p1 = rotateA(pos[0], r1*PI / 2, ho[0]);

			for (int r2 = 0; r2<4; r2++){

				point p2 = rotateA(pos[1], r2*PI / 2, ho[1]);

				for (int r3 = 0; r3<4; r3++){

					point p3 = rotateA(pos[2], r3*PI / 2, ho[2]);

					for (int r4 = 0; r4<4; r4++){

						point p4 = rotateA(pos[3], r4*PI / 2, ho[3]);

						if (iSsquare({ p1, p2, p3, p4 }))
							ret = min(ret, r1 + r2 + r3 + r4);
					}
				}

			}
		}
		if (ret == inf)
			cout << -1 << endl;
		else
			cout << ret << endl;
	}





}