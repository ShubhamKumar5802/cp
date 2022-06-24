#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;


bool Area(ll dX0, ll dY0, ll dX1, ll dY1, ll dX2, ll dY2)
{
    ll dArea = ((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0))/2.0;
    return dArea==0;
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin>>n;
   ll arr[n][2];
   for(int i=0;i<n;i++){
       cin>>arr[i][0];
       cin>>arr[i][1];
   }
   ll ans=n*(n-1ll)*(n-2ll)/6ll;
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           for(int k=j+1;k<n;k++){
               if(Area(arr[i][0],arr[i][1],arr[j][0],arr[j][1],arr[k][0],arr[k][1])){
                ans--;
               }
           }
       }
   }
   cout<<ans<<endl;
return 0;
}