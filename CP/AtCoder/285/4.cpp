
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
	// cin >> __;
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
	// map<string, ll>changed, used;
	vector<pair<string, string>>v;
	map<string, vector<string>>adj;
	bool ans = true;
	map<string, int>indeg;
	rep(i, 0, n) {
		string s, t;
		cin >> s >> t;
		v.pb({s, t});
		indeg[t] = 0;
		indeg[s] = 0;
	}
	rep(i, 0, n) {
		string s = v[i].F;
		string t = v[i].S;
		indeg[t]++;
		adj[s].pb(t);
	}
	queue<string>q;
	for (auto &p : indeg) {
		if (indeg[p.F] == 0) {
			q.push(p.F);
		}
	}
	vector<string>topo;
	while (q.size()) {
		string node = q.front();
		q.pop();
		topo.pb(node);
		for (auto &curr : adj[node]) {
			indeg[curr]--;
			if (indeg[curr] == 0) {
				q.push(curr);
			}
		}
	}
	// print1D(topo);
	if (topo.size() == indeg.size()) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
