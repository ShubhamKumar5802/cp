#include<bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(int i=x ; i<y ; i++)
#define f first
#define s second
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()

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
const double pi = 3.1415926536;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1];}
template<typename T>
void swapit(T &a, T &b) {T temp = a; a = b; b = temp;}
int gcd(int a, int b) {if (b == 0)return a; return gcd(b, a % b);}
int digits_count(int n) {return (n < 10 ? 1 : n < 100 ? 2 : n < 1000 ? 3 : n < 10000 ? 4 : n < 100000 ? 5 : n < 1000000 ? 6 : n < 10000000 ? 7 : n < 100000000 ? 8 : n < 1000000000 ? 9 : 0);}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n96;
	cin >> n96;
	while (n96--) {
		int n;
		cin >> n;
		deque<ll>dq, dq1, dq2;

		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			dq.pb(t);
			dq2.pb(t);
		}
		if (dq.size() <= 2) {
			if (dq.size() == 2) {
				cout << dq.front() << " ";
				dq.pop_front();
				cout << dq.front() << endl;
			} else {
				cout << dq.front() << endl;
			}
			continue;
		}


		while (dq.size()) {
			ll f1 = dq.front();
			ll l1 = dq.back();
			if (f1 < l1) {
				dq1.push_front(f1);
				dq.pop_front();
			} else {
				dq1.push_back(l1);
				dq.pop_back();
			}
		}
		deque<ll>dq3;
		dq3 = dq1;
		while (dq1.size()) {
			ll f1 = dq1.front();
			ll l1 = dq1.back();
			if (f1 < l1) {
				dq.push_front(f1);
				dq1.pop_front();
			} else {
				dq.push_back(l1);
				dq1.pop_back();
			}
		}


		if (dq == dq2) {
			while (dq3.size() != 1) {
				cout << dq3.front() << " ";
				dq3.pop_front();
			}
			cout << dq3.front() << endl;
		} else {
			dq.push_front(dq.back());
			dq.pop_back();
			if (dq == dq2) {
				while (dq3.size() != 1) {
					cout << dq3.front() << " ";
					dq3.pop_front();
				}
				cout << dq3.front() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}

	}
	return 0;
}