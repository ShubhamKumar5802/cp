#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int z = 0; z < n; z++)
    {
        string key = "", word = "";
        cin >> key;
        cin >> word;
        if (word.size() == 1)
        {
            cout << "0" <<endl;
            continue;
            key="";
            word="";
        }
        else
        {
            unordered_map<char, int> um;
            for (int i = 0; i < key.size(); i++)
            {
                um[key[i]] = i + 1;
            }
            int time = 0;
            for (int i = 1; i < word.size(); i++)
            {
                int temp = um[word[i]] - um[word[i - 1]];
                time = time + abs(temp);
            }
            cout << time << endl;
            key="";
            word="";
        }
    }
    return 0;
}