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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
template<typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }

const long long mod = 1e9 + 7;
const double pi = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1] << endl;}
template<typename T>
void swapit(T &a, T &b) {T temp = a; a = b; b = temp;}
int digits_count(int n) {return (n < 10 ? 1 : n < 100 ? 2 : n < 1000 ? 3 : n < 10000 ? 4 : n < 100000 ? 5 : n < 1000000 ? 6 : n < 10000000 ? 7 : n < 100000000 ? 8 : n < 1000000000 ? 9 : 0);}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int __;
	cin >> __;
	while (__--) {
		int n;
		cin >> n;
		priority_queue<pll>pq1;
		for (int i = 0; i < n; i++) {
			ll t;
			cin >> t;
			pq1.push({t, i + 1});
		}
		deque<pll>dq;
		ll sum = 0;
		dq.push_back({0, 0});
		bool flag = false;
		int l = 0, r = 0;
		while (pq1.size()) {
			auto pq = pq1.top();
			if (flag) {
				r++;
				auto ptr = pq.second;
				pq1.pop();
				dq.push_back({r, ptr});
				sum += 2 * r * (pq.ff);
			} else {
				l--;
				auto ptr = pq.second;
				pq1.pop();
				dq.push_back({l, ptr});
				sum += 2 * abs(l) * (pq.ff);
			}
			flag = !flag;
		}

		vll ans(n + 1);


		for (auto i = dq.begin(); i != dq.end(); i++) {
			int idx = i->second;
			int val = i->first;
			ans[idx] = val;
		}
		cout<<sum<<endl;
		print1D(ans);

	}
	return 0;
}