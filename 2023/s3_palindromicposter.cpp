

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void fillRow(vector<vector<char>>& grid, int rowIndex, char c) {
    int m = grid[0].size();
    for (int j = 0; j < m; j++) {
        grid[rowIndex][j] = c;
    }
}

void fillCol(vector<vector<char>>& grid, int colIndex, char c) {
    int n = grid.size();
    for (int i = 0; i < n; i++) {
        grid[i][colIndex] = c;
    }
}

void incrementRow(vector<vector<char>>& grid, int rowIndex, int a, int b) {
    for (int j = a; j < b; j++) {
        grid[rowIndex][j]++;
    }
}

void incrementCol(vector<vector<char>>& grid, int colIndex, int a, int b) {
    for (int i = a; i < b; i++) {
        grid[i][colIndex]++;
    }
}

void printGrid(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void printFlippedGrid(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    
    for (int j = 0; j < m; j++) {
        for (int i = n-1; i >= 0; i--) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}


void reducePalindromes(vector<vector<char>>& grid, int numCols) {
    int m = grid[0].size();

    if (numCols % 2 == 1) {
        grid[0][(int)(m/2)]++;
        // cout << grid[0][(int)(m/2)] << endl;
        numCols--;
    }

    for (int j = 0; j < (int)(numCols/2); j++) {
        grid[0][j]++;
        grid[0][m-j-1]++;
    }
}

int main() {

    int n, m, r, c;
    cin >> n >> m >> r >> c;
    bool flipped = false;



    if (r == 0 && c == 0) {
        vector<vector<char>> grid(n, vector<char>(m, 'a'));
        incrementRow(grid, 0, 0, m);
        incrementCol(grid, 0, 0, n);
        printGrid(grid);
        return 0;
    }

    if (r == n && c == m) {
        vector<vector<char>> grid(n, vector<char>(m, 'a'));
        printGrid(grid);
        return 0;
    }

    if (c == m) {
        swap(n, m);
        swap(r, c);
        flipped = true;
    }

    vector<vector<char>> grid(n, vector<char>(m, 'b'));

    // if either R == N or C == M:
    // fill grid with 'b' and reduce palindromic columns two at a time

    if (r == n) {
        if (m % 2 == 0 && c % 2 == 1) { // even number of columns
            cout << "IMPOSSIBLE" << endl;
            return 0;
        } else {
            reducePalindromes(grid, m-c);
        }

        if (flipped) {
            printFlippedGrid(grid);
        } else {
            printGrid(grid);
        }
        return 0;
        
    }

    // fill the first R rows and first C cols with 'a'
    for (int i = 0; i < r; i++) {
        fillRow(grid, i, 'a');
    }

    for (int j = 0; j < c; j++) {
        fillCol(grid, j, 'a');
    }



    // if either R == 0 or C == 0:
    // if R == 0: increment the last M-C characters of the last row

    if (r == 0) {
        incrementRow(grid, grid.size()-1, c, m);
    }

    if (c == 0) {
        incrementCol(grid, grid[0].size()-1, r, n);
    }

    if (flipped) {
        printFlippedGrid(grid);
    } else {
        printGrid(grid);
    }

    return 0;
}