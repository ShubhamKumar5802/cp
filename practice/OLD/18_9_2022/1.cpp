#include <iostream>
using namespace std;

#define N 9

void print(int arr[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
bool leftDia(int ans[N][N], int num, int i, int j)
{
    j += i;
    i = 0;
    if (j > 9){
        i += j % 9;
        j = 9;
    }
    while (i < 9 && j > 0){
        if (ans[i][j] == num)
            return false;
        i++;
        j--;
    }
    return true;
}
bool rightDia(int ans[N][N], int num, int i, int j)
{
    j -= i;
    i = 0;
    if (j < 0){
        i += abs(j);
        j = 0;
    }
    while (i < 9 && j < 9){
        if (ans[i][j] == num)
            return false;
        i++;
        j++;
    }
    return true;
}
bool isSafe(int grid[N][N], int row, int col, int num){


    int startRow = row - row % 3, startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
              return false;

    return rightDia(grid, num,  row, col) && leftDia(grid, num,  row, col);
}

bool solveSudoku(int grid[N][N], int row, int col){
    if (row == N - 1 && col == N)
        return true;
    if (col == N) {
        row++;
        col = 0;
    }
    if (grid[row][col] > -1)
        return solveSudoku(grid, row, col + 1);

    for (int num = 0; num < N; num++){
        if (isSafe(grid, row, col, num)){
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }
    return false;
}

int main()
{
    int grid[N][N] = { { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 },
                    { -1, -1, -1, -1, -1, -1, -1, -1, -1 } };

    if (solveSudoku(grid, 0, 0))
        print(grid);

    return 0;
}
