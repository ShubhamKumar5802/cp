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

vector<bool>is_prime(900001, true);
void Seive(int n) {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
		if (is_prime[i] && (long long)i * i <= n) {
			for (int j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Seive(900000);
	int __ = 1;
	cin >> __;
	while (__--) {
		int n;
		cin >> n;
		vvll v;
		for (int i = 0; i < n - 1; i++) {
			vll tv;
			for (int j = 0; j < n - 1; j++) {
				tv.pb(4);
			}
			v.pb(tv);
		}
		int next_prime ;
		for (int i = (4 * (n - 1) + 1); i < 90000; i++) {
			int next_ele = i - 4 * (n - 1);
			if (is_prime[i] and is_prime[next_ele] == false) {
				next_prime = i;
				break;
			}
		}
		int next_ele = next_prime - 4 * (n - 1);
		for (int i = 0; i < n - 1; i++) {
			v[i].pb(next_ele);
		}
		vll tv(n - 1, next_ele);
		v.pb(tv);
		int next_e;
		for (int i = ((n - 1) * (next_ele) + 1); i < 50000; i++) {
			next_e = i - ((n - 1) * (next_ele));
			if (is_prime[i] and is_prime[next_e] == false) {
				next_prime = i;
				break;
			}
		}

		// next_ele = next_prime - ((n - 1) * (next_ele));
		v[n - 1].pb(next_e);
		for (int i = 0; i < n ; i++) {
			print1D(v[i]);
			cout << endl;
		}
	}
	return 0;
}