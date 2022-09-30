#include<bits/stdc++.h>
using namespace std;

#define  rep(i,x,y)      for(int i=x ; i<y ; i++)
#define  F               first
#define  S               second
#define  pb              push_back
#define  sz(v)           int((v).size())
#define  all(v)          (v).begin(), (v).end()
#define  min3(a,b,c)     min(a,min(b,c))
#define  min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define  max3(a,b,c)     max(a,max(b,c))
#define  max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define  gcd             __gcd
#define  ub              upper_bound
#define  lb              lower_bound
#define  endl           "\n"

typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
template<typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }

const long long mod = 1e9 + 7;
const double pi = 3.14159265358979323846264338327950288419;
template<typename T>
void print1D(vector<T> nums) {for (int i = 0; i < nums.size() - 1; i++)cout << nums[i] << " "; cout << nums[nums.size() - 1];}
template <typename T>
void print2D(vector<vector<T>> &nums){for(int i = 0; i < nums.size(); i++){print1D(nums[i]);cout << endl;}}
long long power(long long x, long long n) {x = x % mod; if (x == 0)return 0; long long result = 1; while (n > 0) {if (n & 1)result = (result * x) % mod; n = n >> 1; x = (x * x) % mod;} return result;}

// bool sqaure_check(vector<vector<int>> ans, int num, int i, int j)
// {
//     int startRow = i - i % 3;
//     int startCol = j - j % 3;
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             if (ans[i + startRow][j + startCol] == num)
//                 return false;
//         }
//     }
//     return true;
// }
// bool leftDia(vector<vector<int>> &ans, int num, int i, int j)
// {
//     j += i;
//     i = 0;
//     if (j > 8)
//     {
//         i += j % 8;
//         j = 8;
//     }
//     while (i < 9 && j > 0)
//     {
//         if (ans[i][j] == num)
//             return false;
//         i++;
//         j--;
//     }
//     return true;
// }
// bool rightDia(vector<vector<int>> &ans, int num, int i, int j)
// {
//     j -= i;
//     i = 0;
//     if (j < 0)
//     {
//         i += abs(j);
//         j = 0;
//     }
//     while (i < 9 && j < 9)
//     {
//         if (ans[i][j] == num)
//             return false;
//         i++;
//         j++;
//     }
//     return true;
// }
// bool isSafe(vector<vector<int>> ans, int num, int i, int j)
// {
//     return sqaure_check(ans, num, i, j) && leftDia(ans, num, i, j) && rightDia(ans, num, i, j);
// }
vector<vector<int>> ans;

static bool isValid(vector<vector<int>>& mat, int row, int col, int ch) {
    // Checking the row:
    for(int j=0; j<9; ++j) {
        if(mat[row][j] == ch) return false;
    }
    
    // Checking for Column:
    for(int i=0; i<9; ++i) {
        if(mat[i][col] == ch) return false;
    }
    
    // Checking for 3x3 Sub-grid:
    int ri = (row/3)*3;
    int cj = (col/3)*3;
    
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j) {
            if(mat[ri + i][cj + j] == ch) return false;
        }
    }
    return true;
}

void recur(vector<vector<int>>& mat, int row, int col) {
    if(row == 9) {
        ans = mat;
        return;
    }

    int next_r = -1, next_c = -1;
    
    if(col == 8) {
        next_r = row+1;
        next_c = 0;
    }
    else {
        next_r = row;
        next_c = col+1;
    }
    
    if(mat[row][col] != -1) {
        recur(mat, next_r, next_c);
    }            
    else {
        for(char ch = 1; ch <= 9; ++ch) {
            if(isValid(mat, row, col, ch)) {
                mat[row][col] = ch;
                recur(mat, next_r, next_c);
                mat[row][col] = -1;
            }
        }
    }
    return;
}
  
void solve(){
    vector<vector<int>> v = {
        {-1, 4, -1, -1, -1, -1, -1, 2, 8},
        {3, -1, -1, -1, 7, -1, 3, 5, 6},
        {5, -1, 7, -1, -1, -1, -1, -1, -1},
        {-1, -1, 5, -1, 1, 3, 5, -1, -1},
        {-1, 4, -1, -1, 2, 8, -1, -1, -1},
        {-1, 8, -1, 4, -1, -1, 2, -1, 3},
        {4, 5, -1, 2, 7, 4, -1, 5, 2},
        {-1, 6, 3, 0, -1, 1, -1, 0, -1},
        {-1, 7, -1, 6, -1, -1, -1, -1, -1}
    };
    	// recur(v, 0, 0);
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	clock_t clk__ = clock();
	int __ = 1;
	cin >> __;
	while (__--) solve();
	cerr << "Run Time : " << ((double)(clock() - clk__) / CLOCKS_PER_SEC);
	return 0;
}