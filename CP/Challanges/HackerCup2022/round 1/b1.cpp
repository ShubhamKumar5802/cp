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

const long long mod = 1e9 + 7;
const long long MOD = 1e9 + 7;
const double pi = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1];}
template <typename T>
void print2D(vector<vector<T>> &nums) {for (int i = 0; i < nums.size(); i++) {print1D(nums[i]); cout << endl;}}

ll id = 1;
void solve() {
	ll n, q;
	cin >> n;
	ll xi = 0, xi2 = 0, yi = 0, yi2 = 0;
	rep(i, 0, n) {
		ll t;
		cin >> t;
		xi = (xi % MOD + t % MOD) % MOD;
		xi2 = (xi2 % MOD + (t % MOD * t % MOD) % MOD) % MOD;
		cin >> t;
		yi = (yi % MOD + t % MOD) % MOD;
		yi2 = (yi2 % MOD + (t % MOD * t % MOD) % MOD) % MOD;
	}
	cin >> q;
	ll ans = 0 ;
	while (q--) {
		ll x = 0, y = 0;
		cin >> x >> y;
		ans = (ans % MOD + (((y % MOD * y % MOD) % MOD) % MOD * n % MOD) % MOD + yi2 % MOD - ((2 * y % MOD * yi % MOD) % MOD) % MOD + MOD) % MOD;
		ans = (ans % MOD + (((x % MOD * x % MOD) % MOD) % MOD * n % MOD) % MOD + xi2 % MOD - ((2 * x % MOD * xi % MOD) % MOD) % MOD + MOD) % MOD;
	}
	cout << "Case #" << id << ": " << ans << endl;
	id++;
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