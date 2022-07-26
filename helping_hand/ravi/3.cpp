#include<bits/stdc++.h>
using namespace std;

 string arr;
string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while(i>=0 || j>=0 || carry){
        long sum = 0;
        if(i >= 0){sum += (num1[i] - '0');i--;}
        if(j >= 0){sum += (num2[j] - '0');j--;}
        sum += carry; 
        carry = sum / 10;
        sum = sum % 10;
        res =  res + to_string(sum);
    }
    reverse(res.begin(), res.end());
    return res;
}
void solve(){
	cin>>arr;
	sort(arr.begin(), arr.end());
    string a = "", b = "";
    for (int i = 0; i < arr.size(); i++)
    {
        if (i & 1)
            a.push_back(arr[i]);
        else
            b.push_back(arr[i]);
    }
 
    cout<< addStrings(a,b)<<endl;

}
int main() {
	int __ = 1;
	cin >> __;
	while (__--) solve();
	return 0;
}