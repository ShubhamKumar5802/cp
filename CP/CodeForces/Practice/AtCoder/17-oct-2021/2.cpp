#include<bits/stdc++.h>

using namespace std;
void lshift(string s, string &ans){
    ans= s;
    ans.pop_back();
   ans+=s[s.size()-1];
//    cout<<ans<<endl;
}
void rshift(string s, string &ans){
     ans=s.substr(1);
     ans+=s[0];
    //  cout<<ans<<endl;
}
int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   string s;
   cin>>s;
   string maxi=s,mini=s;
    string ans;
    for(int i=0;i<s.size();i++){
        lshift(s,ans);
        maxi=max(maxi,ans);
        mini=min(mini,ans);
        rshift(s,ans);
        maxi=max(maxi,ans);
        mini=min(mini,ans);
        s=ans;
    }
   cout<<mini<<endl;
   cout<<maxi<<endl;

return 0;
}