

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


/*
magnify function takes the current magnificaton state
tries to narrow it down
checks the "quadrants of the four big boxes"
i didn't have better word for quadrant even though theres only three areas

*/
bool magnify(int m, long long n, long long x, long long y) {
    // first check that the x coordinate is within the middle three fifths
    long long gap = n/5;
    long long leftBound = gap, rightBound = gap*4;
    int quadrant = -1;


    // cout << "leftbound is " << leftBound << endl;
    // cout << "rightbound is " << rightBound << endl;
    // cout << "gap is " << gap << endl;

    // then check which of the three boxes it is above
    if (x >= leftBound && x < leftBound+gap) {
        quadrant = 1;
    } else if (x >= leftBound+gap && x < leftBound+gap*2) {
        quadrant = 2;
    } else if (x >= leftBound+gap*2 && x < rightBound) {
        quadrant = 3;
    } else {
        return false; // x is on the left or right edge where crystals do not exist
    }

    // determine the height of the crystal on the current quadrant
    // note that quadrant 1 and 3 have the same height (1 block up)
    // quadrant 2 is twice is high as the other two (2 blocks up)

    long long height;
    if (quadrant == 1 || quadrant == 3) { 
        height = pow(5,m-1);
    } else {
        height = 2 * pow(5,m-1);
    }

    if (y < height) return true;

    long long next_x, next_y, next_n;
    next_x = x-gap*quadrant;
    next_y = y-height;
    next_n = pow(5, m-1);

    return magnify(m-1, next_n, next_x, next_y);
}

int main() {

    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {

        long long m, x, y;
        cin >> m >> x >> y;

        long long n = pow(5, m);

        bool mag = magnify(m, n, x, y);

        if (mag) {
            cout << "crystal" << endl;
        } else {
            cout << "empty" << endl;
        }
    }

    return 0;
}