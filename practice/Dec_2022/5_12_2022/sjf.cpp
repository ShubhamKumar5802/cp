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
		cout << "Enter at and bt" << endl;
		tab[i][0] = i + 1;
		// for (int j = 2; j <= 3; j++) {
		cin >> tab[i][1] >> tab[i][2];
		// }
	}
	sort(tab.begin(), tab.end(), cmp);
	int timmer = 0;
	vector<int>ct(n);
	vector<vector<int>>table = tab;
	while (tab.size()) {
		bool f = true;
		for (int i = 0; i < tab.size(); i++) {
			if (tab[i][1] <= timmer) {
				timmer += tab[i][2];
				for (int t = 0; t < tab[i][2]; t++) {
					cout << "P" << tab[i][0] << ",";
				}
				ct[tab[i][0] - 1] = timmer;
				tab.erase(tab.begin() + i);
				f = false;
				break;
			}
		}
		if (f) {
			cout << "_,";
			timmer++;
		}
	}
	cout << endl;
	cout << "Table" << endl;
	cout << "P_ID\t" << "AT\t" << "BT\t" << "CT\t" << "TAT" << endl;
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "\t" << table[i][1] << "\t" << table[i][2] << "\t" << ct[i] << "\t" << ct[i] - table[i][1] << endl;
	}


	return 0;
}