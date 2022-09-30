#include<bits/stdc++.h>
using namespace std;

#define  rep(i,x,y)      for(int i=x ; i<y ; i++)
#define  ff              first
#define  ss              second
#define  pb              push_back
#define  sz(v)           int((v).size())
#define  all(v)          (v).begin(), (v).end()
#define  min3(a,b,c)     min(a,min(b,c))
#define  min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define  max3(a,b,c)     max(a,max(b,c))
#define  max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define  gcd             __gcd
#define  ub              upper_bound
#define  lb              lower_bound

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
template<typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }

const long long mod = 1e9 + 7;
const double pi = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1];}
template<typename T>
void swapit(T &a, T &b) {T temp = a; a = b; b = temp;}
int digits_count(int n) {return (n < 10 ? 1 : n < 100 ? 2 : n < 1000 ? 3 : n < 10000 ? 4 : n < 100000 ? 5 : n < 1000000 ? 6 : n < 10000000 ? 7 : n < 100000000 ? 8 : n < 1000000000 ? 9 : 0);}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}

bool canProcide(int kr, int kc, int rr1, int rc1, int rr2, int rc2) {
	if (((kr == 1 and kc == 1) or (kr == 8 and kc == 8) or (kr == 8 and kc == 1))) {
		if ((rr1 != rr2))return true;
		else {
			if (abs(kc - rc1) > 1 and abs(kc - rc2) > 1)return true;
			return false;
		}
	} else if ((kr == 1 or kr == 8)) {
		if ((rc1 != rc2))return true;
		else {
			if (abs(kr - rr1) > 1 and abs(kr - rr2) > 1)return true;
			return false;
		}
	} else if ((kc == 1 or kc == 8)) {
		if ((rr1 != rr2))return true;
		else {
			if (abs(kc - rc1) > 1 and abs(kc - rc2) > 1)return true;
			return false;
		}
	} else {
		return false;
	}
}

int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, -1, -1, 1};
bool underAttack(int kr, int kc, int rr, int rc) {
	for (int i = 0; i < 4; i++) {
		int newr = kr + dx[i];
		int newc = kc + dy[i];
		if (newr >= 1 and newr <= 8 and newc >= 1 and newc <= 8) {
			if (newr == rr and newc == rc) {
				return true;
			}
		}
	}
	return false;
}

bool underPsudoAttack(int kr, int kc, int rr, int rc) {
	if ((kr == 1 and kc == 1) or (kr == 8 and kc == 8) or (kr == 1 and kc == 8) or (kr == 8 and kc == 1)) {
		if ((abs(kr - rr) <= 1) or (abs(kc - rc) <= 1))return true;
		else false;
	} else if (kr == 1 or kr == 8) {
		if (abs(kc - rc) <= 1)return true;
		else return false;
	} else {
		if (abs(kr - rr) <= 1)return true;
		else return false;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int __ = 1;
	cin >> __;
	while (__--) {
		int kr, kc, rr1, rc1, rr2, rc2;
		cin >> kr >> kc >> rr1 >> rc1 >> rr2 >> rc2;
		if (canProcide(kr, kc, rr1, rc1, rr2, rc2)) {
			//for rook-1
			if ((underAttack(kr, kc, rr1, rc1) == false) and ((abs(kr - rr1) == 1) or (abs(kc - rc1) == 1))) {
				if (underPsudoAttack(kr, kc, rr2, rc2) == false) {
					cout << "Yes" << endl;
					continue;
				}
			}
			if ((underAttack(kr, kc, rr2, rc2) == false) and ((abs(kr - rr2) == 1) or (abs(kc - rc2) == 1))) {
				if (underPsudoAttack(kr, kc, rr1, rc1) == false) {
					cout << "Yes" << endl;
					continue;
				}
			}
			cout << "NO" << endl;

		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}