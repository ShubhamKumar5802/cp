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
template<typename T>
void swapit(T &a, T &b) {T temp = a; a = b; b = temp;}
int digits_count(int n) {return (n < 10 ? 1 : n < 100 ? 2 : n < 1000 ? 3 : n < 10000 ? 4 : n < 100000 ? 5 : n < 1000000 ? 6 : n < 10000000 ? 7 : n < 100000000 ? 8 : n < 1000000000 ? 9 : 0);}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}

unordered_map<int,vi>adj;
vector<int> disc{0}, low{0}, visited{0};
int tim = 1;
set<pair<int,int>> ans;
set<vector<int>>aa;
void dfs(int curr, int prev) {
    disc[curr] = low[curr] = tim++;
    for (int &next : adj[curr]) {
        if (disc[next] == 0) {
            dfs(next, curr);
            low[curr] = min(low[curr], low[next]);
        } else if (next != prev)
            low[curr] = min(low[curr], disc[next]);
        if (low[next] > disc[curr]) 
            ans.insert({curr + 1, next + 1});
    }
}
int dfs(int node, int target, bool taken){
	visited[node] = 1;
	if(node==target)return 0;
	for(auto &x: adj[node]){
		if(!visited[x]){
			if(ans.find({node, x}) != ans.end()){
				if(taken)return 2;
				if(dfs(x, target, true)==1)return 1;
			}else{
				if(dfs(x, target, taken)==1)return 1;
			}
		}
	}
	return 2;
}
void help(){
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			if()
		}
	}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	rep(i,0,m){
		ll u,v;
		cin>>u>>v;
		adj[u-1].pb(v-1);
		adj[v-1].pb(u-1);
	}
	disc = vector<int>(n);
    low = vector<int>(n);
    visited = vector<int>(n);
    dfs(0, -1);
    help();
    // rep(i,0,ans.size()){
    // 	cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    // }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t clk__ = clock();
	int __ = 1;
	// cin >> __;
	while (__--) solve();
	cerr << "Run Time : " << ((double)(clock() - clk__) / CLOCKS_PER_SEC)<<"s";
	return 0;
}