#include <bits/stdc++.h>

using namespace std;
#define rep(i, x, y) for (int i = x; i < y; i++)
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
template <typename T>
void swapit(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int digits_count(int n) {
	return (n < 10 ? 1 : n < 100		? 2
	        : n < 1000		? 3
	        : n < 10000		? 4
	        : n < 100000		? 5
	        : n < 1000000	? 6
	        : n < 10000000	? 7
	        : n < 100000000	? 8
	        : n < 1000000000 ? 9
	        : 0);
}
int convert_to_decimal(long long n)
{
	int dec = 0, i = 0;
	while (n != 0)
	{
		dec += (n % 10) * pow(2, i++);
		n /= 10;
	}
	return dec;
}
string convetr_to_binary_string(int x)
{
	string s;
	while (x)
	{
		s.push_back('0' + (x & 1));
		x >>= 1;
	}
	reverse(s.begin(), s.end());
	return s;
}
long long power(long long x, long long n)
{
	x = x % mod;
	if (x == 0)
		return 0;
	long long result = 1;
	while (n > 0)
	{
		if (n & 1)
			result = (result * x) % mod;
		n = n >> 1;
		x = (x * x) % mod;
	}
	return result;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n96;
	cin >> n96;
	while (n96--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		int hash[101] = {0};
		for (int i = 1; i <= n; i++)
			hash[i] = 1;

		vi ans1, ans2;
		ans1.pb(a);
		hash[a] = 0;
		int s = n / 2;
		for (int i = b + 1; i <= n; i++)
		{
			if (s == 1)
				break;
			if (i > a and hash[i]) {
				hash[i] = 0;
				ans1.pb(i);
				s--;
			}
		}
		for (int i = a + 1; i <= n; i++)
		{
			if (s == 1)
				break;
			if (hash[i] and i != b) {
				hash[i] = 0;
				ans1.pb(i);
				s--;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (hash[i] and i <= b)
				ans2.pb(i);
		}
		if ((ans1.size() != ans2.size()) || (ans1.size() != n / 2))
		{
			cout << -1 << endl;
			continue;
		}
		for (int i = 0; i < ans1.size(); i++)
			cout << ans1[i] << " ";
		for (int i = 0; i < ans2.size() - 1; i++)
			cout << ans2[i] << " ";
		cout << ans2[ans2.size() - 1] << endl;
	}
	return 0;
}
