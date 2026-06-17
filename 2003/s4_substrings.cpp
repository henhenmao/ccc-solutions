
#include <iostream>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
	unordered_map<char, TrieNode*> children;
    
    ~TrieNode() {
        for (auto& [c, node] : children) {
            delete node;
        }
    }
};

int countSubstrings(string &s) {
	TrieNode* head = new TrieNode();
	int k = s.length();
	
	// holds the count of unique substrings
	int count = 0;
	
	for (int i = 0 ; i < k; i++) {
		TrieNode* temp = head;
		for (int j = i; j < k; j++) {
            if (temp->children.find(s[j]) == temp->children.end()) {
                temp->children[s[j]] = new TrieNode();
                count++;
            }
            temp = temp->children[s[j]];
		}
	}

    delete head;
	return count+1; // include the empty substring

}

int main() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        cout << countSubstrings(s) << endl;
    }

    return 0;
}