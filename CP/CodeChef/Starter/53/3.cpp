#include<bits/stdc++.h>
using namespace std;

#define  rep(i,x,y)      for(int i=x ; i<y ; i++)
#define  F               first
#define  S               second
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
#define  endl           "\n"

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
template <typename T>
void print2D(vector<vector<T>> &nums) {for (int i = 0; i < nums.size(); i++) {print1D(nums[i]); cout << endl;}}
template<typename T>
void swapit(T &a, T &b) {T temp = a; a = b; b = temp;}
int digits_count(int n) {return (n < 10 ? 1 : n < 100 ? 2 : n < 1000 ? 3 : n < 10000 ? 4 : n < 100000 ? 5 : n < 1000000 ? 6 : n < 10000000 ? 7 : n < 100000000 ? 8 : n < 1000000000 ? 9 : 0);}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}

bool isCorner(int i, int j) {
	if (i == 0) {
		if (j == 0 or j == 7)return true;
	}
	if (i == 7) {
		if (j == 0 or j == 7)return true;
	}
	return false;
}

void solve() {
	int ki, kj;
	cin >> ki >> kj;
	ki--;
	kj--;
	int b[8][8] = {0};
	b[ki][kj] = 1;
	int q1i = ki - 1;
	int q1j = kj - 2;
	int q2i = ki + 1;
	int q2j = kj + 2;
	if (isCorner(ki, kj)) {
		if (ki == 0 and kj == 0) {
			b[1][2] = 1;
		} else if (ki == 0 and kj == 7) {
			b[1][5] = 1;
		} else if (ki == 7 and kj == 0) {
			b[6][2] = 1;
		} else {
			b[6][5] = 1;
		}
	} else {
		if (ki <= 6 and ki >= 1 and kj >= 2 and kj <= 5) {
			q1i = ki - 1;
			q1j = kj - 2;
			q2i = ki + 1;
			q2j = kj + 2;

		} else if (kj == 0 and ki >= 2 and ki <= 5) {
			q1i = ki - 2;
			q1j = 1;
			q2i = ki + 2;
			q2j = 1;
		} else if (kj == 7 and ki >= 2 and ki <= 5) {
			q1i = ki - 2;
			q1j = 6;
			q2i = ki + 2;
			q2j = 6;
		} else if (ki == 0 and kj >= 2 and kj <= 5) {
			q1i = 1;
			q1j = kj - 2;
			q2i = 1;
			q2j = kj + 2;
		} else if (ki == 0 and kj >= 2 and kj <= 5) {
			q1i = 6;
			q1j = kj - 2;
			q2i = 6;
			q2j = kj + 2;
		} else if (kj == 1 and ki >= 2 and ki <= 5) {
			q1i = ki + 2;
			q1j = 0;
			q2i = ki - 2;
			q2j = 2;
		} else if (kj == 6 and ki >= 2 and ki <= 5) {
			q1i = ki + 2;
			q1j = 5;
			q2i = ki - 2;
			q2j = 7;
		} else if (ki == 0 and kj == 1) {
			q1i = 1;
			q1j = 3;
			q2i = 2;
			q2j = 0;
		} else if (ki == 1 and kj == 0) {
			q1i = 2;
			q1j = 2;
			q2i = 0;
			q2j = 2;
		} else if (ki == 1 and kj == 1) {
			q1i = 3;
			q1j = 0;
			q2i = 0;
			q2j = 4;
		} else if (ki == 1 and kj == 6) {
			q1i = 3;
			q1j = 7;
			q2i = 0;
			q2j = 3;
		} else if (ki == 1 and kj == 7) {
			q1i = 3;
			q1j = 6;
			q2i = 0;
			q2j = 5;
		} else if (ki == 0 and kj == 6) {
			q1i = 1;
			q1j = 4;
			q2i = 2;
			q2j = 7;
		} else if (ki == 6 and kj == 0) {
			q1i = 4;
			q1j = 1;
			q2i = 7;
			q2j = 2;
		} else if (ki == 6 and kj == 1) {
			q1i = 7;
			q1j = 3;
			q2i = 3;
			q2j = 0;
		} else if (ki == 7 and kj == 1) {
			q1i = 6;
			q1j = 3;
			q2i = 4;
			q2j = 0;
		} else if (ki == 6 and kj == 6) {
			q1i = 4;
			q1j = 7;
			q2i = 7;
			q2j = 3;
		} else if (ki == 6 and kj == 7) {
			q1i = 4;
			q1j = 6;
			q2i = 7;
			q2j = 4;
		} else if (ki == 7 and kj == 6) {
			q1i = 6;
			q1j = 4;
			q2i = 4;
			q2j = 7;
		}
		b[q1i][q1j] = 2;
		b[q2i][q2j] = 2;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 7; j++) {
			cout << b[i][j] << " ";
		}
		cout << b[i][7] << endl;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t clk__ = clock();
	int __ = 1;
	cin >> __;
	while (__--) solve();
	cerr << "Run Time : " << ((double)(clock() - clk__) / CLOCKS_PER_SEC) << "s";
	return 0;
}