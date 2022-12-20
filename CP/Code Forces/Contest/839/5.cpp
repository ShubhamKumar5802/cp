#include <bits/stdc++.h>
using namespace std;

struct Array {
	int arr[100];
	int i = 0;
	void push_back(int val);
	void pop_back();
	int val(int idx);
	int size();
};

// // a.val(2) =
// int main() {
// 	int i;
// 	Student s1, s2;
// 	s1.name = "Ramanujan";
// 	s2.name = "Alina";
// 	s1.roll = 1;
// 	s2.roll = 2;
// 	s1.sem = 5;
// 	s2.sem = 5;

// 	cout << s1.seyHello() << endl;

// 	return 0;
// }