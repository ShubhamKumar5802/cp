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
	vll cat(n);
	vll dam(n);
	rep(i, 0, n)cin >> cat[i];
	rep(i, 0, n)cin >> dam[i];
	vll fire, froz;
	rep(i, 0, n) {
		if (cat[i]) {
			fire.pb(dam[i]);
		} else {
			froz.pb(dam[i]);
		}
	}
	sort(all(fire));
	sort(all(froz));
	if (fire.size() == 0) {
		ll ans = accumulate(all(froz), 0ll);
		cout << ans << endl;
		return;
	} else if (froz.size() == 0) {
		ll ans = accumulate(all(fire), 0ll);
		cout << ans << endl;
		return;
	}
	ll ans1 = 0;
	if (fire.size() > froz.size() or (fire.size() == froz.size() and fire[0] <= froz[0])) {
		ans1 = 2 * accumulate(all(froz), 0ll);
		ll n1 = froz.size();
		int i = fire.size() - 1;
		while (i > 0) {
			if (n1) {
				ans1 += 2 * fire[i];
				n1--;
			} else {
				ans1 += fire[i];
			}
			i--;
		}
		ans1 += fire[0];
	} else {
		ans1 = 2 * accumulate(all(fire), 0ll);
		ll n1 = fire.size();
		int i = froz.size() - 1;
		while (i > 0) {
			if (n1) {
				ans1 += 2 * froz[i];
				n1--;
			} else {
				ans1 += froz[i];
			}
			i--;
		}
		ans1 += froz[0];
	}
	// ll ans = max(ans1, ans2);
	cout << ans1 << endl;
}
