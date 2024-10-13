#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int ALPHABET_SIZE = 52;

inline int getIndex(char ch) {
    return (ch >= 'a') ? (ch - 'a') : (ch - 'A' + 26);
}

int countBeautifulSubstrings(const string& s) {
    int n = s.length();
    vector<int> freq(ALPHABET_SIZE, 0);
    vector<int> uniqueChars;
    int beautifulCount = 0;

    for (int end = 0; end < n; ++end) {
        int idx = getIndex(s[end]);
        if (freq[idx] == 0) uniqueChars.push_back(idx);
        ++freq[idx];

        int targetFreq = freq[idx];
        bool isBeautiful = true;

        for (int uniqueChar : uniqueChars) {
            if (freq[uniqueChar] != 0 && freq[uniqueChar] != targetFreq) {
                isBeautiful = false;
                break;
            }
        }

        if (isBeautiful) ++beautifulCount;

        for (int start = 0; start < end; ++start) {
            idx = getIndex(s[start]);
            --freq[idx];

            isBeautiful = true;
            for (int uniqueChar : uniqueChars) {
                if (freq[uniqueChar] != 0 && freq[uniqueChar] != targetFreq) {
                    isBeautiful = false;
                    break;
                }
            }

            if (isBeautiful) ++beautifulCount;
        }
    }

    return beautifulCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;

    cout << countBeautifulSubstrings(s) << endl;
    return 0;
}