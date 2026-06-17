

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int r, c, m;
int grid(int row, int col) {
    return (row * c + col) % m + 1;
}

int main () {
    cin >> r;
    cin >> c;
    cin >> m;

    vector<int> prevRow(c, 0), currRow(c, 0);
    for (int j = 0; j < c; j++) {
        prevRow[j] += grid(0, j);
    }

    for (int i = 1; i < r; i++) {
        currRow[0] = min(prevRow[0], prevRow[1]) + grid(i, 0);
        currRow[c-1] = min(prevRow[c-1], prevRow[c-2]) + grid(i, c-1);

        for (int j = 1; j < c-1; j++) {
            currRow[j] = min(min(prevRow[j-1], prevRow[j]), prevRow[j+1]) + grid(i, j);
        }

        swap(prevRow, currRow);
    }
    cout << *min_element(prevRow.begin(), prevRow.end()) << endl;

    return 0;
}