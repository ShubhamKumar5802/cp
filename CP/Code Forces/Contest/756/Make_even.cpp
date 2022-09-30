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
		ll n;
		cin >> n;
		if (n % 2 == 0) {
			cout << "0" << endl;
		} else {
			int count = 0;

			string str = to_string(n);
			int it = str[0] - '0';
			if (it % ll(2) == 0) {
				cout << "1" << endl;
				continue;
			}
			for (int i = 1; i < str.size(); i++) {
				it = str[i] - '0';
				if (it % ll(2) == 0) {
					count = 1;
					cout << "2" << endl;
					break;
				}
			}
			if (count == 0) {
				cout << "-1" << endl;
			}
		}

	}
	return 0;
}