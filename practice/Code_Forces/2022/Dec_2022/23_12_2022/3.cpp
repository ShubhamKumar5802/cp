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
void get(vll &v, ll n) {rep(i, 0, n)cin >> v[i];}
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
	cin >> __;
	while (__--) {
		solve();
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll memo[100001][2];
bool dfs(vector<vc>&c, vvll &visited, int i, int j) {
	if (i == c.size() or i < 0 or j == 2 or j < 0 or visited[i][j] or c[i][j] == 'W')return false;

	visited[i][j] = 1;
	if (c[0][c.size() - 1] == 'B' and visited[0][c.size() - 1]) {
		return true;
	}
	if (c[0][c.size() - 1] == 'W' and visited[1][c.size() - 1]) {
		return true;
	}
	return dfs(c, visited, i, j + 1) or dfs(c, visited, i - 1, j) or dfs(c, visited, i, j - 1) or dfs(c, visited, i + 1, j);

}
void solve()
{
	ll n;
	cin >> n;
	vector<vc>c(2, vc(n));
	rep(i, 0, n)cin >> c[0][i];
	rep(i, 0, n)cin >> c[1][i];
	bool r1 = true, r2 = true;
	rep(i, 0, n) {
		if (c[0][i] == 'B' and c[1][i] == 'B') {
			swap(r1, r2);
		} else if (c[0][i] == 'B' and c[1][i] == 'W') {
			r1 = false;
		} else {
			r2 = false;
		}
	}
	bool ans = r1 or r2;
	cout << (ans ? "YES" : "NO") << endl;
}
