/*

use a frequency map to represent the needle string
create freq with key value pairs of {char c : int f}, where c is one of the 26 letters and f is the frequency of that letter in the needle
let n be needle.length()

maintain a sliding window of size n, using left and right pointers
if haystack[right] is a letter in haystack and freq[haystack[right]] > 0, subtract 


*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <array>

using namespace std;

bool allZero(unordered_map<char, int>& freq) {
    for (auto& pair: freq) {
        if (pair.second != 0) return false;
    }
    return true;
}

int main() {

    string needle, haystack;
    unordered_map<char, int> freq;
    unordered_set<long long> visited;

    cin >> needle;
    cin >> haystack;

    int n = needle.length();
    int m = haystack.length();
    int availableChars = n;

    int res = 0;

    // create frequency map
    for (char c: needle) {
        freq[c] += 1;
    }

    int left = 0;
    int right = 0;

    long long mod = 1e9+7, base = 31, hash = 0, power = 1;

    while (right < m) {
        char curr = haystack[right];

        if (freq.find(curr) != freq.end()) {
            freq[curr]--;
            availableChars--;
        }

        hash = (hash * base + (curr-'a'+1)) % mod;

        if (right-left+1 > n) { // increment left pointer
            char returnChar = haystack[left];

            if (freq.find(returnChar) != freq.end()) {
                freq[returnChar]++;
                availableChars++;
            }

            if (right-left+1 == n+1) {
                power = 1;
                for (int i = 0; i < n; i++) {
                    power = (power*base) % mod;
                }
            }
            hash = (hash - (returnChar - 'a' + 1) * power) % mod;
            if (hash < 0) hash += mod;
            left++;
        }

        if (right-left+1 == n && availableChars <= 0 && allZero(freq)) {
            if (visited.find(hash) == visited.end()) {
                visited.insert(hash);
                res++;
            }
        }

        right++;

    }

    cout << res << endl;
    return 0;
}