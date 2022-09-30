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

typedef unsigned long long ll;
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

const long long mod = 998244353;
const double pi = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1];}
template<typename T>
void swapit(T &a, T &b) {T temp = a; a = b; b = temp;}
int digits_count(int n) {return (n < 10 ? 1 : n < 100 ? 2 : n < 1000 ? 3 : n < 10000 ? 4 : n < 100000 ? 5 : n < 1000000 ? 6 : n < 10000000 ? 7 : n < 100000000 ? 8 : n < 1000000000 ? 9 : 0);}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}

ll findSum(ll N, ll K)
{
	ll ans = 0;

	// Counting the number of times 1, 2, ..,
	// K-1, 0 sequence occurs.
	ll y = N / K;

	// Finding the number of elements left which
	// are incomplete of sequence Leads to Case 1 type.
	ll x = N % K;

	// adding multiplication of number of
	// times 1, 2, .., K-1, 0 sequence occurs
	// and sum of first k natural number and sequence
	// from case 1.
	ans = (K * (K - (ll)1) / (ll) 2) * y + (x * (x + (ll) 1)) / (ll) 2;

	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int __ = 1;
	// cin>>__;
	ll arr[20];
	arr[0] = 0;
	ll fact = (ll)9;
	for (int i = 1; i < 19; i++) {
		arr[i] = fact ;
		fact *= (ll)10;
	}
	while (__--) {
		ll n;
		cin >> n;
		ll ans = (ll)0;
		ll	t = ceil(log10(n + 1));
		cout << t << endl;
		for (int i = 1; i < t; i++) {
			ans = ((ans % mod) + (findSum(arr[i], mod))) % mod;
			// ans  = ans % mod;
		}
		ll req = (n - arr[t] / (ll)9 + (ll)1);
		ans = ((ans % mod) + (findSum(req, mod))) % mod;
		// ans  = ans % mod;
		cout << ans << endl;
	}
	return 0;
}