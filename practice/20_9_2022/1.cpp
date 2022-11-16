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
int ans = 0;
bool isPalin(string& s)
{
	int i = 0, j = s.length() - 1;
	while (i <= j)
	{
		if (s[i] != s[j])
			return false;
		i++;
		j--;
	}
	return true;
}
void dfs(string& s, string& s1, string& s2, int i)
{
	if (i >= s.length())
	{
		if (isPalin(s1) && isPalin(s2))
		{
			ans = max(ans, ((int)s1.length()) * ((int)s2.length()));
		}
		return;
	}
	s1 += s[i];
	dfs(s, s1, s2, i + 1);
	s1.pop_back();

	s2 += s[i];
	dfs(s, s1, s2, i + 1);
	s2.pop_back();

	dfs(s, s1, s2, i + 1);
}
void solve()
{
	string s;
	cin >> s;
	string s1 = "", s2 = "";
	int i = 0;
	dfs(s, s1, s2, i);
	cout << ans << endl;
}
