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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int __ = 1;
	cin >> __;
	while (__--) {
		int n;
		cin >> n;
		int z = 0, o = 0, t = 0;
		rep(i, 0, n) {
			int temp;
			cin >> temp;
			if (temp % 3 == 0) {
				z++;
			} else if (temp % 3 == 1) {
				o++;
			} else {
				t++;
			}
		}
		int req = n / 3;
		z -= req;
		o -= req;
		t -= req;
		int ans = 0;
		while (z > 0) {
			if (o < 0) {
				o++;
				ans++;
			} else if (t < 0) {
				t++;
				ans += 2;
			}
			z--;
		}
		while (o > 0) {
			if (t < 0) {
				t++;
				ans++;
			} else if (z < 0) {
				z++;
				ans += 2;
			}
			o--;
		}
		while (t > 0) {
			if (z < 0) {
				z++;
				ans++;
			} else if (o < 0) {
				o++;
				ans += 2;
			}
			t--;
		}
		cout << ans << endl;
	}
	return 0;
}