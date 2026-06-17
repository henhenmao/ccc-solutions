

#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {

    string name1="", name2="";
    int r1 = 0, r2 = 0;
    int s1 = 0, s2 = 0;
    int d1 = 0, d2 = 0;

    string name;
    int r, s, d, n;
    cin >> n;

    if (n == 1) {
        cin >> name >> r >> s >> d;
        cout << name << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> name >> r >> s >> d;
        int curr_val = 2*r + 3*s + d;

        int val1 = 2*r1 + 3*s1 + d1;
        int val2 = 2*r2 + 3*s2 + d2;

        if ((curr_val > val1 )|| (curr_val == val1 && name < name1)) {
            r2 = r1;
            s2 = s1;
            d2 = d1;
            name2 = name1;

            r1 = r;
            s1 = s;
            d1 = d;
            name1 = name;

        } else if ((curr_val > val2) || (curr_val == val2 && name < name2)) {
            r2 = r;
            s2 = s;
            d2 = d;
            name2 = name;
        }
    }

    cout << name1 << endl << name2 << endl;

}