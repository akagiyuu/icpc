#include <bits/stdc++.h>

#define NAME ""
#define repz(i, a) for (int i = 0; i < a; ++i)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = b; i >= a; --i)
#define ll long long
#define ld long double
#define ii pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<bool>> colored(n + 1, vector<bool> (m + 1, false));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char ch;
            cin >> ch;
            colored[i][j] = (ch == '.');
        }
    }

    int actions = 0;
    // row coloring
    for (int i = 1; i <= n; ++i) {
        int j = 1; 
        while (j <= m) {
            if (!colored[i][j]) {
                actions++;
                for (; j <= m && !colored[i][j]; ++j) 
                    colored[i][j] = true;
            } else {
                j++;
            }
        } 
    }
    cout << actions << endl;
    // col coloring
    for (int j = 1; j <= m; ++j) {
        int i = 1; 
        while (i <= n) {
            if (!colored[i][j]) {
                actions++;
                for (; i <= n && !colored[i][j]; ++i) 
                    colored[i][j] = true;
            } else {
                i++;
            }
        } 
    }

    cout << actions;

    return 0;
}