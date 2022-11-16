#include<bits/stdc++.h>
using namespace std;
int subsequence_sum_k(vector&arr, int index, vector& v, vector& output, int sum, int k) {
	if (index == arr.size()) {
		if (sum == k) {
			output.push_back(v) ;
		}
		return ;
	}
	sum += arr[index];
	v.push_back(arr[index];
	            subsequence_sum_k(arr, index + 1, v, output, sum, k); // WHEN I AM TAKING THE NO.
	            v.pop_back();
	            sum -= arr[index]; //WHEN I AM DECIDING NO TO TAKE I HAVE TO SUBTRACT BECAUSE I AM REMOVING IT FROM THE SET
	            subsequence_sum_k(arr, index + 1, v, output, sum, k); // THIS IS THE CONDITION WHERE I AM DECIDING NO TO TAKE

}
int main() {
	vectorarr{// whatever you want to add};
		int k = ?; // target
		vectorv;
		vectoroutput;
		subsequence_sum_k(arr, 0, v, output, 0, k);

	}