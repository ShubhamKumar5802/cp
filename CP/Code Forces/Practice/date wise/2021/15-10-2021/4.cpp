#include<bits/stdc++.h>

using namespace std;
#define rep(i,x,y) for(int i=x ; i<y ; i++)
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define PRES(c,x) ((c).find(x) != (c).end())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;


long long mod=1e9+7;
template<typename T>
void print2D(vector<vector<T>> v){for (int i = 0; i < v.size(); i++){for (int j = 0; j < v[i].size(); j++)cout << v[i][j] <<", " ;cout << endl;}}
template<typename T>
void print1D(vector<T> nums){for (int i = 0; i < nums.size(); i++)cout << nums[i] << ", ";}
void printUoMap(unordered_map<int, int> m){unordered_map<int, int>::iterator i = m.begin();while (i != m.end()){cout << i->first << " -> " << i->second << endl;i++;}}
void swap(int &a, int &b){int temp = a;a = b;b = temp;}
void permutator(vector<int> nums, vector<int> cp, vector<vector<int>> &ans, set<int> s){if (cp.size() == nums.size()){ans.push_back(cp);return;}for (int i = 0; i < nums.size(); i++)if (s.find(nums[i]) == s.end()){cp.push_back(nums[i]);s.insert(nums[i]);permutator(nums, cp, ans, s);s.erase(s.find(nums[i]));cp.pop_back();}}
vector<vector<int>> permute(vector<int> &nums){vector<vector<int>> ans;vector<int> cp;set<int> s;permutator(nums, cp, ans, s);return ans;}
vector<vector<int>> subsets(vector<int>& nums) {vector<vector<int>> ans;int num=pow(2,nums.size());ans.push_back({});for(int i=1;i<num;i++){vector<int> t;for(int j=0;j<nums.size();j++)if((i&(1<<j)))t.push_back(nums[j]);ans.push_back(t);}return ans;}
int digits_count(int n){return(n < 10 ? 1 :n < 100 ? 2 :n < 1000 ? 3 :n < 10000 ? 4 :n < 100000 ? 5 :n < 1000000 ? 6:n < 10000000 ? 7:n < 100000000 ? 8:n < 1000000000 ? 9:0);}
int convert_to_decimal(long long n){int dec = 0, i = 0;while (n != 0){dec += (n%10)* pow(2, i++);n /= 10;}return dec;}
string convetr_to_binary_string(int x){string s;while(x){s.push_back('0'+(x&1));x>>=1;}reverse(s.begin(),s.end());return s;}
long long power(long long x,long long n){x=x%mod;if(x==0)return 0;long long result=1;while(n>0){if(n&1)result=(result*x)%mod;n=n>>1;x=(x*x)%mod;}return result;}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n96;
   cin>>n96;
   for(int x101=0;x101<n96;x101++){
        ll n1;
        cin>>n1;
        cout<<-n1+1<<" "<<n1<<endl;
   }
return 0;
}