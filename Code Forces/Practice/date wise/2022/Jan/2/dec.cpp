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


string drc(string s) {
	int n = s.size();
	string ans = "";
	queue<char>st;

	for (int i = 0; i < n ; i++) {
		if (isdigit(s[i])) {
			st.push(s[i]);
		}
	}
	int i = n - 1;
	while (i >= 0) {
		if (s[i] == '*') {
			string ch;
			i--;
			ch = s[i];
			i--;
			ch += s[i];
			ans = ch + ans;
		} else if (s[i] == '0') {
			ans = st.front() + ans;
			st.pop();
		} else if (isdigit(s[i])) {
			i--;
			continue;
		} else {
			ans = s[i] + ans;
		}
		i--;
	}

	return ans;
}

vector<long> sol (vector<int> numbers, vector<vector<int>>queries) {
	vector<long> arr;
	vector<long>psum(numbers.size()), zeros(numbers.size());
	psum[0] = numbers[0];
	zeros[0] = (numbers[0] == 0) ? 1 : 0;
	for (int i = 1; i < numbers.size(); i++) {
		psum[i] = psum[i - 1] + numbers[i];
		zeros[i] = zeros[i - 1] + (numbers[i] == 0 ? 1 : 0);
	}

	for (int i = 0; i < queries.size(); i++) {
		long l = queries[i][0] - 1;
		long r = queries[i][1] - 1;
		long exsum = queries[i][2];

		long sum = psum[r] - psum[l] + numbers[l];
		sum += (exsum * (zeros[r] - zeros[l] + (numbers[l] == 0 ? 1 : 0)));
		arr.push_back((long)sum);
		sum = 0;
	}

	return arr;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int __ = 1;
	// cin>>__;
	while (__--) {
		int n;

		cin >> n;
		vector<int> numbers(n); vector<vector<int>>queries(1, vector<int>(3));

		for (int i = 0; i < n; i++) {
			cin >> numbers[i];
		}
		cin >> n;
		cin >> n;
		cin >> queries[0][0];
		cin >> queries[0][1];
		cin >> queries[0][2];
		vector<long>v;
		v = sol(numbers, queries);
		print1D(v);
	}
	return 0;
}