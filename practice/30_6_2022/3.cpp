#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool check_for_errors(string &input_str, map<char, vector<char>>& adj_list, map<char, int>& num_parents, char& root) {
    char parent;
    int idx = 0;
    bool E5_error = false;
    for (int i = 0; i < input_str.size(); i++) {
        if (input_str[i] != '(' and input_str[i] != ')' and input_str[i] != ',' and input_str[i] != ' ') { //If input_str[i] is a node
            idx++;
            if (idx % 2 == 1) {
                if (i - 1 >= 0 and input_str[i - 1] != '(') {
                    cout << "E1\n";
                    return false;
                } else if (i + 1 < input_str.size() and input_str[i + 1] != ',') {
                    cout << "E1\n";
                    return false;
                }
                parent = input_str[i];
            } else {
                if (i - 1 >= 0 and input_str[i - 1] != ',') {
                    cout << "E1\n";
                    return false;
                } else if (i + 1 < input_str.size() and input_str[i + 1] != ')') {
                    cout << "E1\n";
                    return false;
                }

                for (int j = 0; j < adj_list[parent].size(); j++) {
                    if (adj_list[parent][j] == input_str[i]) {
                        cout << "E2\n";
                        return false;
                    }
                }

                if (adj_list[parent].size() == 2) {
                    cout << "E3\n";
                    return false;
                }
                num_parents[input_str[i]]++;
                num_parents[parent];
                if (num_parents[input_str[i]] == 2) {
                    E5_error = true;
                }
                adj_list[parent].push_back(input_str[i]);
                idx = 0;
            }
        } else if (i - 1 <= 0 and input_str[i] == ' ') {
            if (input_str[i] == ' ') {
                cout << "E1\n";
                return false;
            }
        }
    }
    int num_roots = 0;
    for (auto &kv : num_parents) {
        if (kv.second == 0) {
            root = kv.first;
            num_roots++;
            if (num_roots == 2) {
                cout << "E4\n";
                return false;
            }
        }
    }
    if (E5_error == true) {
        cout << "E5\n";
        return false;
    }
    return true;
}

void print_expression(map<char, vector<char>> adj_list, char curr) {
    cout << "(" << curr;
    int num_child = adj_list[curr].size();
    if (num_child == 1) {
        print_expression(adj_list, adj_list[curr][0]);
    } else if (num_child == 2) {
        if (adj_list[curr][0] < adj_list[curr][1]) {
            print_expression(adj_list, adj_list[curr][0]);
            print_expression(adj_list, adj_list[curr][1]);
        } else {
            print_expression(adj_list, adj_list[curr][1]);
            print_expression(adj_list, adj_list[curr][0]);
        }
    }
    cout << ")";
}


int main() {

    string input_str;
    getline(cin, input_str);

    char root;
    map<char, vector<char>> adj_list;
    map<char, int> num_parents;
    if (!check_for_errors(input_str, adj_list, num_parents, root)) {
        return 0;
    }
    print_expression(adj_list, root);
    return 0;
}