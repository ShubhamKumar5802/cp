#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int>&a, vector<int>&b) {
	return a[2] < b[2];
}


int main() {
	int n;
	cout << "Enter no of process" << endl;
	cin >> n;
	vector<vector<int>> tab(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cout << "Enter bt and at" << endl;
		tab[i][0] = i + 1;
		cin >> tab[i][1] >> tab[i][2];
	}
	// priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>()>pq;
	// for (int i = 0; i < n; i++) {
	// 	pq.push({tab[i][2], tab[i][1], tab[i][0]});
	// }
	int timmer = 0;
	while (tab.size()) {
		sort(tab.begin(), tab.end(), cmp);
		bool flag = true;
		for (int i = 0; i < tab.size(); i++) {
			if (timmer >= tab[i][1]) {
				timmer++;
				cout << "P" << tab[i][0] << ",";
				flag = false;
				tab[i][2]--;
				if (tab[i][2] == 0) {
					tab.erase(tab.begin() + i);
				}
				break;
			}
		}
		if (flag) {
			timmer++;
			cout << "_,";
		}
	}
	return 0;
}