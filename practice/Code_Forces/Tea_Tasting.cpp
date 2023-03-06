
// @author mr_optimizer

#include <bits/stdc++.h>
using namespace std;
#define  rep(i,x,y)      for(int i=x ; i<y ; i++)
#define  F               first
#define  S               second
#define  pb              push_back
#define  ppb             pop_back
#define  sz(v)           int((v).size())
#define  all(v)          (v).begin(), (v).end()
#define  allr(v)         (v).rbegin(), (v).rend()
#define  endl            "\n"
#define  set_bits(x)     __builtin_popcountll(x)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

const long long MOD = 1e9 + 7;
const double PI = 3.14159265358979323846264338327950288419;
vector<int>isPrime;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < sz(nums) - 1; i++)cout << nums[i] << " "; if (sz(nums))cout << nums[nums.size() - 1];}
template <typename T>
void print2D(vector<vector<T>> &nums) {for (int i = 0; i < nums.size(); i++) {print1D(nums[i]); cout << endl;}}
long long power(long long x, long long n) {x = x % MOD; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % MOD; n = n >> 1; x = (x * x) % MOD;} return result;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;}
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
void sieve(ll n) {isPrime.resize(n, 1); for (int i = 2; i * i < n; i++) {if (isPrime[i]) {for (int j = i * i; j < n; j += i) {isPrime[j] = 0;}}}}
template <typename T>
void get(vector<T> &v, ll n) {rep(i, 0, n)cin >> v[i];}
void solve();
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//sieve(200001);
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
	ll n, m;
	cin >> n;
	//cin>>m;
	vll a(n), b(n);
	get(a, n);
	get(b, n);
	vll v(n);
	v[0] = b[0];
	rep(i, 1, n) {
		v[i] = b[i] + v[i - 1];
	}
	vll cnt(n + 1);
	vll extra(n);
	rep(i, 0, n) {
		ll tea = a[i];
		if (i != 0)tea += v[i - 1];
		auto idx = upper_bound(all(v), tea) - v.begin();
		cnt[i]++;
		cnt[idx]--;
		if (idx != n) {
			ll diff = tea;
			if (idx != 0)
				diff -= v[idx - 1];
			extra[idx] += min(b[idx], diff);
		}
	}
	rep(i, 1, n) {
		cnt[i] += cnt[i - 1];
	}
	vll ans;
	rep(i, 0, n) {
		ll tans = 0;
		tans = cnt[i] * b[i];
		tans += extra[i];
		ans.pb(tans);
	}
	print1D(ans);
	cout << endl;
}
