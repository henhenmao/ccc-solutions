

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<string, char> words;

    int n;

    char c;
    string code;
    string inp;
    string curr;
    string res;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c >> code;
        words[code] = c;
    }

    cin >> inp;
    for (int i = 0; i < (int)inp.length(); i++) {
        curr += inp[i];
        // cout << curr << endl;
        if (words.find(curr) != words.end()) {
            res += words[curr];
            curr.clear();
        }
    }

    cout << res << endl;

    return 0;
}