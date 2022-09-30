#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n96;
    cin >> n96;
    for (int x101 = 0; x101 < n96; x101++)
    {
        int n,d;
        cin>>n>>d;
        int temp=n;
        int itr=0,ans=0;
        cout<<"all set"<<endl;
        while(temp>0){
            int rem=temp%10;
            temp=temp/10;
            itr++;
            if(rem==d){
                temp=temp*pow(10,itr) + (rem+1)*pow(10,itr-1);
                itr=0;
                ans=temp-n;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}