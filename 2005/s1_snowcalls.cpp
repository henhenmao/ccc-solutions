

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {

    int t;
    cin >> t;
    cin.ignore(); // i forgot what this does

    unordered_map<char, vector<char>> keypad = {{'2', {'A', 'B', 'C'}}, {'3', {'D', 'E', 'F'}}, {'4', {'G', 'H', 'I'}},
    {'5', {'J', 'K', 'L'}}, {'6', {'M', 'N', 'O'}}, {'7', {'P', 'Q', 'R', 'S'}},
    {'8', {'T', 'U', 'V'}}, {'9', {'W', 'X', 'Y', 'Z'}}};

    vector<string> numbers(t);
    vector<string> res;

    for (int i = 0; i < t; i++ ) {
        getline(cin, numbers[i]);
    }


    for (string line : numbers) {
        string new_number;


        int n = 0;
        int i = 0;
        while (n < 10) {
            char c = line[i];

            if (c == '-') {
                i++;
                continue;
            }

            if (!isalpha(c)) {
                new_number += c;
                i++;
                n++;
                continue;
            } 

            for (auto& pair : keypad) {
                if (find(pair.second.begin(), pair.second.end(), c) != pair.second.end()) {
                    new_number += pair.first;
                    break;
                }
            }
            n++;
            i++;
        }

        res.push_back(new_number);
    }

    for (int i = 0; i < t; i++) {
        res[i].insert(3, 1, '-');
        res[i].insert(7, 1, '-');
        cout << res[i] << endl;
    }

    return 0;
}