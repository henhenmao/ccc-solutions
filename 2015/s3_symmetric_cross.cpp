

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<int>> m(r, vector<int>(c));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> m[i][j];
        }
    }

    int res_size = -1, res_i = -1, res_j = -1;

    for (int i = 1; i < r-1; i++) {
        for (int j = 1; j < c-1; j++) {
            int topHeight = i, bottomHeight = r-i-1, leftLength = j, rightLength = c-j-1;
            int maxLength = min(min(topHeight, bottomHeight), min(leftLength, rightLength));
            int size = 0;

            for (int k = 0; k <= maxLength; k++) {
                if (m[i][j-k] != m[i-k][j]) {
                    break;
                }

                if (m[i-k][j] != m[i][j+k]) {
                    break;
                }

                if (m[i][j+k] != m[i+k][j]) {
                    break;
                }

                if (m[i+k][j] != m[i][j-k]) {
                    break;
                }

                size += 1;
            }

            if (size > res_size) {
                res_size = size;
                res_i = i;
                res_j = j;
            }
        }
    }

    cout << res_size-1 << " " << res_i+1 << " " << res_j+1 << endl;
    return 0;
}