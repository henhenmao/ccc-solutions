
/*
lowkey have no idea how to solve this

code below gives a 2/20 😭


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


void partitionHelper(vector<int>& houses, int k, int start, vector<pair<int, int>>& minMax, vector<double>& maxHose, vector<double>& temp) {
    int n = houses.size();

    if (k == 0) return;
    if (k == 1) {
        int groupMin = *min_element(houses.begin()+start, houses.end());
        int groupMax = *max_element(houses.begin()+start, houses.end());
        minMax.push_back({groupMin, groupMax});

        double maxAvg = 0;
        double hose;
        temp.clear();

        // cout << "partitions for this path: " << endl;
        for (auto [mini, maxi] : minMax) {
            double avg = (mini+maxi)/2.0;
            maxAvg = max(maxAvg, avg);
            hose = maxi-maxAvg;
            temp.push_back(hose);

            // cout << "{" << mini << " " << maxi << "}, ";
        }

        // cout << endl << endl;
        // cout << "the max hose length is " << hose << endl;

        maxHose.push_back(*max_element(temp.begin(), temp.end()));

        minMax.pop_back();
        return;
    }

    for (int end = start+1; end <= n-k+1; end++) {

        auto groupStart = houses.begin() + start;
        auto groupEnd = houses.begin() + end;
        int groupMin = *min_element(groupStart, groupEnd);
        int groupMax = *max_element(groupStart, groupEnd);

        minMax.push_back({groupMin, groupMax});
        partitionHelper(houses, k-1, end, minMax, maxHose, temp);
        minMax.pop_back();
    }
}

int main() {

    int n;
    int k;
    cin >> n;

    vector<int> houses(n);

    for (int i = 0; i < n; i++) {
        cin >> houses[i];
    }

    cin >> k;

    for (int &h : houses) {
        if (h > 500000) {
            h = -1 * (1000000-h);
        }
    }
    sort(houses.begin(), houses.end());


    vector<pair<int, int>> minMax;
    vector<double> maxHose;
    vector<double> temp;

    partitionHelper(houses, k, 0, minMax, maxHose, temp);

    // for (int num : maxHose) {
    //     cout << num << " ";
    // }
    // cout << endl;

    cout << *min_element(maxHose.begin(), maxHose.end()) << endl;
    return 0;
}