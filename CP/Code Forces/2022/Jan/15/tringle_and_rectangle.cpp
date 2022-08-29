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
		ll w, h;
		cin >> w >> h;
		ll s1, s2, s3, s4;
		cin >> s1;
		vll vs1(s1);
		rep(i, 0, s1)cin >> vs1[i];
		cin >> s2;
		vll vs2(s2);
		rep(i, 0, s2)cin >> vs2[i];
		cin >> s3;
		vll vs3(s3);
		rep(i, 0, s3)cin >> vs3[i];
		cin >> s4;
		vll vs4(s4);
		rep(i, 0, s4)cin >> vs4[i];
		ll ans = 0;
		s1 = *max_element(all(vs1)) - *min_element(all(vs1));
		ans  = max(ans, s1 * h);
		s2 = *max_element(all(vs2)) - *min_element(all(vs2));
		ans  = max(ans, s2 * h);
		s3 = *max_element(all(vs3)) - *min_element(all(vs3));
		ans  = max(ans, s3 * w);
		s4 = *max_element(all(vs4)) - *min_element(all(vs4));
		ans  = max(ans, s4 * w);
		cout << ans << endl;
	}
	return 0;
}