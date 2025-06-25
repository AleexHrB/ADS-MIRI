#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int kmp(const string& s) {
    int n = s.length();
    vector<int> P(n);
    int j = -1;
    for (int i = 0; i < n; ++i) {
        while (j >= 0 and s[j] != s[i]) j = j ? P[j-1] : -1;
        P[i] = ++j;
    }
    return P[n-1];
}


int main() {
    string s;

    while (cin >> s) {
        string r;
        r = s;
        reverse(r.begin(), r.end());
        cout << kmp(r+"#"+s) << endl;
    }
}
