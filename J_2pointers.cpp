#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

const int ALPHABET_SIZE = 52;

int getIndex(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 'a';
    return ch - 'A' + 26;
}

bool isBeautiful(const vector<int>& freq, int unique_count) {
    int count = -1; 
    int t = 0;
    for (int f : freq) {
        if (f > 0) {
            if (count == -1) count = f, t++;
            else {
                if (count != f) return false;
                if (count == f) t++;
            }
        }
    }
    return (t == unique_count);
}

int countBeautifulSubstrings(const string& s, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(ALPHABET_SIZE, 0));  
    int beautifulCount = 0;
    int uniqueCount = 0;

    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if (dp[i + 1][getIndex(s[i])] == 0) uniqueCount++;
        dp[i + 1][getIndex(s[i])]++; 
    }

    for (int start = 0; start < n; start++) {
        for (int end = start; end < n; end++) {
            vector<int> freq(ALPHABET_SIZE, 0);

            for (int c = 0; c < ALPHABET_SIZE; c++) {
                freq[c] = dp[end + 1][c] - dp[start][c];
            }

            if (isBeautiful(freq, uniqueCount)) {
                beautifulCount++;
            }
        }
    }

    return beautifulCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;
    cin >> n;
    cin >> s;

    cout << countBeautifulSubstrings(s, n) << endl;
    return 0;
}
