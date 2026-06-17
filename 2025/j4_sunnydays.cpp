


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
find the longest consecutive sequence of S's with at most one P value

use two pointer sliding window appporach

*/

int main() {
    int n;
    cin >> n;
    vector<char> days(n);

    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    int left = 0;
    int maxLength = 0;
    int pDays = 0;

    for (int right = 0; right < n; right++) {
        if (days[right] != 'S') pDays++;
        
        while (pDays > 1) {
            if (days[left] != 'S') pDays--;
            left++;
        }

        maxLength = max(maxLength, right-left+1);
    }

    if (find(days.begin(), days.end(), 'P') == days.end()) { // if every single element is sunny, one of the sunny days must be wrong
        maxLength -= 1;
    }

    cout << maxLength << endl;
    return 0;
}