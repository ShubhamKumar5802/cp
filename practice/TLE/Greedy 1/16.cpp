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
	// cin >> __;
	while (__--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
bool isPrime(ll n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}


void factors(ll n, vll &v) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				v.push_back(i);
				n /= i;
			}
		}
	}
	if (n != 1) {
		v.push_back(n);
	}
}

void solve()
{
	ll n;
	cin >> n;
	if (n == 1 || isPrime(n)) {

		cout << "1" << endl << "0" << endl;
	}
	else {
		vll v;
		factors(n , v);
		if (v.size() == 2 or v.size() == 1)
			cout << "2" << endl;
		else {
			cout << "1" << endl << v[0]*v[1] << endl;
		}
	}
}
