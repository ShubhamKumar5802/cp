#include <iostream>
using namespace std;
int gcd(int a, int b){
  if(b==0)return a;	    
  else return gcd(b,a%b);
}
int main() {
	   
    int n;
    cin>>n;
    for(int x1=0;x1<n;x1++){
        int len;
        cin>>len;
        int nums[len];
        for(int i=0;i<len;i++){
            cin>>nums[i];
        }
        if(len==1){
            cout<<1;
            continue;
        }
        int notes=0;
        int maxi_gcd=1;
        int tempitr;
        for(int i=0;i<len;i++){
            int temp_gcd=0;
            int j;
            for( j=0;j<len;j++){
                if(j==1)continue;
                if(temp_gcd==0)temp_gcd=nums[j];
                temp_gcd=gcd(temp_gcd,nums[j]);
            }
            if(temp_gcd>maxi_gcd){
                maxi_gcd=temp_gcd;
                tempitr=i;
            }else if(temp_gcd==maxi_gcd){
                if(nums[i]>nums[tempitr])tempitr=i;
            }
        }
        for(int i=0;i<len;i++){
            if(i==tempitr)continue;
            notes+=nums[i]/maxi_gcd;
        }
        notes++;
        cout<<notes<<endl;
    }
	return 0;
}
