

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int r, c;
    int x, y;
    cin >> r >> c;

    int currx = 0;
    int curry = 0;

    while (true) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;

        currx = max(0, min(r, currx + x));
        curry = max(0, min(c, curry + y));

        cout << currx << " " << curry << endl;
    }

    return 0;
}