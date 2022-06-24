#include <bits/stdc++.h>
using namespace std;
void print2D(vector<vector<int>> v){for (int i = 0; i < v.size(); i++){for (int j = 0; j < v[i].size(); j++)cout << v[i][j] << ", ";cout << endl;}}
void print1D(vector<int> nums){for (int i = 0; i < nums.size(); i++)cout << nums[i] << ", ";}
void printUoMap(unordered_map<int, int> m){unordered_map<int, int>::iterator i = m.begin();while (i != m.end()){cout << i->first << " -> " << i->second << endl;i++;}}
void swap(int &a, int &b){int temp = a;a = b;b = temp;}
void permutator(vector<int> nums, vector<int> cp, vector<vector<int>> &ans, set<int> s){if (cp.size() == nums.size()){ans.push_back(cp);return;}for (int i = 0; i < nums.size(); i++)if (s.find(nums[i]) == s.end()){cp.push_back(nums[i]);s.insert(nums[i]);permutator(nums, cp, ans, s);s.erase(s.find(nums[i]));cp.pop_back();}}
vector<vector<int>> permute(vector<int> &nums){vector<vector<int>> ans;vector<int> cp;set<int> s;permutator(nums, cp, ans, s);return ans;}
vector<vector<int>> subsets(vector<int>& nums) {vector<vector<int>> ans;int num=pow(2,nums.size());ans.push_back({});for(int i=1;i<num;i++){vector<int> t;for(int j=0;j<nums.size();j++)if((i&(1<<j)))t.push_back(nums[j]);ans.push_back(t);}return ans;}
int digits_count(int n){return(n < 10 ? 1 :n < 100 ? 2 :n < 1000 ? 3 :n < 10000 ? 4 :n < 100000 ? 5 :n < 1000000 ? 6:n < 10000000 ? 7:n < 100000000 ? 8:n < 1000000000 ? 9:0);}
int convert_to_decimal(long long n){int dec = 0, i = 0;while (n != 0){dec += (n%10)* pow(2, i++);n /= 10;}return dec;}
string convetr_to_binary_string(int x){string s;while(x){s.push_back('0'+(x&1));x>>=1;}reverse(s.begin(),s.end());return s;}
#define mod 1000000007
long long chefola[100001];
long long prifix[100001];
void chefolaGenerator(){
    for(long long i=1;i<100001;i++){
        long long k=i/10;
        long long temp=i;
        while(k){
            temp=(temp*10+k%10)%mod;
            k/=10;
        }
        chefola[i]=temp;
    }
}
void prifixGenerator(){
    prifix[0]=0;
    for(long long i=1;i<100001;i++){
        prifix[i]=(prifix[i-1]+chefola[i])%mod;
    }
}
long long power(long long x,long long y){
    long long res=1;
    x=(x%mod);
    if(x==0)return 0;
    while(y>0){
        if(y&1)res=((res%mod)*(x%mod))%mod;
        y=y>>1;
        x=((x%mod)*(x%mod))%mod;
    }
    return res;
}


int main()
{      
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    chefolaGenerator();
    prifixGenerator();
    long long n96;
    cin>>n96;
    for(long long x101=0;x101<n96;x101++){
        long long l,r;
        cin>>l>>r;
        long long e=prifix[r]-prifix[l];
        long long temp2=chefola[l];
        long long ans=1;
        ans=power(temp2,e);
        cout<<(ans)%mod<<endl;
    }
    return 0;
}