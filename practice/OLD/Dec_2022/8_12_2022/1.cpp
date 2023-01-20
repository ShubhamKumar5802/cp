#include <bits/stdc++.h>
using namespace std;
#define  rep(i,x,y)      for(int i=x ; i<y ; i++)
#define  F               first
#define  S               second
#define  pb              push_back
#define  sz(v)           int((v).size())
#define  all(v)          (v).begin(), (v).end()
#define  gcd             __gcd
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

const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1];}
template <typename T>
void print2D(vector<vector<T>> &nums) {for (int i = 0; i < nums.size(); i++) {print1D(nums[i]); cout << endl;}}
long long power(long long x, long long n) {x = x % MOD; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % MOD; n = n >> 1; x = (x * x) % MOD;} return result;}

void solve();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int __ = 1;
	// cin >> __;
	while (__--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
map<char, int>bug;
ll b, s, c;
ll pb, ps, pc, r;
bool check(ll cnt) {
	ll cost = 0;
	ll rb = cnt * bug['B'];
	ll rs = cnt * bug['S'];
	ll rc = cnt * bug['C'];

	rb -= min(b, rb);
	rs -= min(s, rs);
	rc -= min(c, rc);

	cost += pb * rb;
	cost += ps * rs;
	cost += pc * rc;
	return cost <= r;
}
void solve()
{
	string st;
	cin >> st;
	cin >> b >> s >> c >> pb >> ps >> pc >> r;

	bug['B'] = 0;
	bug['S'] = 0;
	bug['C'] = 0;

	rep(i, 0, sz(st))bug[st[i]]++;


	ll l = 0, h = 1e14;
	ll ans = 0;
	while (l <= h) {
		ll mid = (l + h) / 2;
		if (check(mid)) {
			ans = max(ans, mid);
			l = mid + 1;
		} else {
			h = mid - 1;
		}
	}
	cout << ans << endl;



}
