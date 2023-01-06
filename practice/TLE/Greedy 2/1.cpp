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
void get(vll &v, ll n) {rep(i, 0, n)cin >> v[i];}
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
	cin >> __;
	while (__--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
void solve()
{
	ll n;
	cin >> n;
	string e, c;
	cin >> e >> c;
	ll cnt2 = 0, cnt10 = 0, cnt01 = 0, cnt0 = 0;
	ll ans = 0;
	rep(i, 0, n) {
		if (e[i] == '1' and c[i] == '1') {
			cnt2++;
		} else if (e[i] == '0' and c[i] == '0') {
			cnt0++;
		} else if (e[i] == '1') {
			cnt10++;
		} else {
			cnt01++;
		}
	}
	ans += min(cnt2, cnt0);
	cnt2 -= ans;
	ll temp = min(cnt10, cnt01);
	ans += temp;
	cnt01 -= temp;
	cnt10 -= temp;

	ans += min(cnt10, cnt2);
	cnt2 -= min(cnt10, cnt2);
	ans += min(cnt01, cnt2);
	cnt2 -= min(cnt01, cnt2);
	ans += cnt2 / 2;
	cout << ans << endl;
}
