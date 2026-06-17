

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    unordered_map<int, int> freq;
    pair<int, int> top1 = {-1, -1};
    pair<int, int> top2 = {2000, 2000};

    freq[-1] = 0;
    freq[2000] = 0;

    cin >> n;
    int curr;

    for (int i = 0; i < n; i++) {
        cin >> curr;
        freq[curr]++;

        if (top1.first == -1 || freq[curr] > freq[top1.first] || (freq[curr] == freq[top1.first] && curr > top1.first && curr != top1.first)) {
            top1.second = top1.first;
            top1.first = curr;
        } else if (curr != top1.first && (top1.second == -1 || freq[curr] > freq[top1.second] || (freq[curr] == freq[top1.second] && curr < top1.second))) {
            top1.second = curr;
        }

        if (top2.first == 2000 || freq[curr] > freq[top2.first] || (freq[curr] == freq[top2.first] && curr < top2.first && curr != top2.first)) {
            top2.second = top2.first;
            top2.first = curr;
        } else if (curr != top2.first && (top2.second == 2000 || freq[curr] > freq[top2.second] || (freq[curr] == freq[top2.second] && curr > top2.second && curr != top2.first))) {
            top2.second = curr;
        }

    }

    int difference1 = abs(top1.first-top1.second);
    int difference2 = abs(top2.first-top2.second);f

    // cout << "top1: " << endl << top1.first << endl << top1.second << endl;
    // cout << "top2: " << endl << top2.first << endl << top2.second << endl;
    // cout << difference1 << endl;
    // cout << difference2 << endl;

    cout << max(difference1, difference2) << endl;

    return 0;
}