#include<bits/stdc++.h>
using namespace std;

#define  rep(i,x,y)      for(int i=x ; i<y ; i++)
#define  F               first
#define  S               second
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
template<typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }

const long long mod = 1e9 + 7;
const double pi = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1];}
template <typename T>
void print2D(vector<vector<T>> &nums){for(int i = 0; i < nums.size(); i++){print1D(nums[i]);cout << endl;}}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long resultult = 1; while (n > 0) {if (n & 1)resultult = (resultult * x) % mod; n = n >> 1; x = (x * x) % mod;} return resultult;}

ll id = 1;
void solve(){
 		cout<<"Case #"<<id<<": ";
 		id++;
        string s;
        cin>>s;
        int q;
        cin>>q;
        int ans = 0;
        int n = s.size();
        vector<vector<int>> v(n + 1, vector<int>(26, 0));
        v[1][s[0] - 'a']++;
        for(int i = 2; i <= n; i++) {
            v[i][s[i-1] - 'a']++;
            for(int j = 0; j < 26; j++) {
                v[i][j] += v[i-1][j];
            }
        }
        while(q--) {
            int l, r;
            cin>>l>>r;
            int sz = r - l + 1;
            if(!(sz&1)) {
                continue;
            }
            int mid = l + (r - l)/2;
            bool result = true, f = true;
            for(int i  = 0; i < 26; i++) {
                if(v[mid][i] - v[l-1][i] == v[r][i] - v[mid][i]) {
                    continue;
                }else {
                    int d = abs(v[mid][i] - v[l-1][i] - v[r][i] + v[mid][i]);
                    if(f) {
                        if(d == 1) {
                            f = false;
                        }else {
                            result = false;
                        }
                    }else {
                        result = false;
                    }
                }
            }
            if(!f && result) {
                ans++;
            }else {
                result = true;
                f = true;
                for(int i = 0; i < 26; i++) {
                    if(v[mid-1][i] - v[l-1][i] == v[r][i] - v[mid-1][i]) {
                        continue;
                    }else {
                        int d = abs(v[mid-1][i] - v[l-1][i] - v[r][i] + v[mid-1][i]);
                        if(f) {
                            if(d == 1) {
                                f = false;
                            }else {
                                result = false;
                                
                            }
                        }else {
                            result = false;
                        }
                    }
                }
                if(!f && result) {
                    ans++;
                }

            }

        }
        cout<<ans<<endl;
       
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t clk__ = clock();
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int __ = 1;
	cin >> __;
	while (__--) solve();
	cerr << "Run Time : " << ((double)(clock() - clk__) / CLOCKS_PER_SEC);
	return 0;
}