

#include <iostream>
#include <vector>

using namespace std;

int main() {

    int maxWeight, n;
    cin >> maxWeight;
    cin >> n;

    vector<int> cars(n);
    for(int i = 0; i < n; i++) {
        cin >> cars[i];
    }

    int left = 0, right = 0;
    int currWeight = 0;
    while (right < n) {

        if (right-left+1 > 4) {
            currWeight -= cars[left];
            left++;
        }

        currWeight += cars[right];
        if (currWeight > maxWeight) {
            break;
        }


        right++;
    }

    cout << right << endl;

    return 0;
}