#include<bits/stdc++.h>

using namespace std;
#define rep(i,x,y) for(int i=x ; i<y ; i++)
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;


long long mod = 1e9 + 7;
template<typename T>
void swapit(T &a, T &b) {T temp = a; a = b; b = temp;}
int gcd(int a, int b) {if (b == 0)return a; return gcd(b, a % b);}
int digits_count(int n) {return (n < 10 ? 1 : n < 100 ? 2 : n < 1000 ? 3 : n < 10000 ? 4 : n < 100000 ? 5 : n < 1000000 ? 6 : n < 10000000 ? 7 : n < 100000000 ? 8 : n < 1000000000 ? 9 : 0);}
int convert_to_decimal(long long n) {int dec = 0, i = 0; while (n != 0) {dec += (n % 10) * pow(2, i++); n /= 10;} return dec;}
string convetr_to_binary_string(int x) {string s; while (x) {s.push_back('0' + (x & 1)); x >>= 1;} reverse(s.begin(), s.end()); return s;}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n96;
	cin >> n96;
	while (n96--) {
		string s;
		cin >> s;
		ll ab = 0, ba = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] == 'a' and s[i + 1] == 'b')ab++;
			else if (s[i] == 'b' and s[i + 1] == 'a')ba++;
		}
		if (ab == ba) {

		} else if (ab > ba) {
			int i = s.size() - 1;
			while (s[i] == 'a')i--;
			s[i] = 'a';

		} else {
			int i = s.size() - 1;
			while (s[i] == 'b')i--;
			s[i] = 'b';
		}
		cout << s << endl;

	}
	return 0;
}