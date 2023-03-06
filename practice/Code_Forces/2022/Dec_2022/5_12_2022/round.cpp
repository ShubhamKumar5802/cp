#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cout << "Enter no of process" << endl;
	cin >> n;
	vector<vector<int>> tab(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		cout << "Enter at and bt" << endl;
		tab[i][0] = i + 1;
		cin >> tab[i][1] >> tab[i][2];
	}
	queue<vector<int>>q;
	int tc = 2;
	int timmer = 0;
	while (tab.size() || q.size() > 0) {
		bool flag = true;
		for (int i = 0; i < tab.size(); i++) {
			if (timmer >= tab[i][1]) {
				q.push(tab[i]);
				tab.erase(tab.begin() + i);
				flag = false;
				break;
			}
		}
		if (!flag)continue;
		if (q.size() > 0) {
			auto curr = q.front();
			q.pop();
			int t = min(curr[2], tc);
			curr[2] -= t;
			timmer += t;
			for (int i = 0; i < t; i++) {
				cout << "P" << curr[0] << ",";
			}
			for (int i = 0; i < tab.size(); i++) {
				if (timmer >= tab[i][1]) {
					q.push(tab[i]);
					tab.erase(tab.begin() + i);
					flag = false;
					break;
				}
			}
			if (curr[2]) {
				q.push(curr);
			}
		}
		else {
			timmer++;
			cout << "_,";
		}
	}

	return 0;
}