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
const int N = 205;

int n, m;
ll grid[N][N][N];

void update(int x, int y, int z, int w) {
    for (int i = x; i <= n; i += i & (-i)) {
        for (int j = y; j <= n; j += j & (-j)) {
            for (int k = z; k <= n; k += k & (-k)) {
                grid[i][j][k] += w;
            }
        }
    }
}

ll query(int x, int y, int z) {
    ll result = 0;
    for (int i = x; i > 0; i -= i & (-i)) {
        for (int j = y; j > 0; j -= j & (-j)) {
            for (int k = z; k > 0; k -= k & (-k)) {
                result += grid[i][j][k];
            }
        }
    }
    return result;
}

ll query(int x1, int y1, int z1, int x2, int y2, int z2) {
    return query(x2, y2, z2) - query(x1 - 1, y2, z2) - query(x2, y1 - 1, z2) - query(x2, y2, z1 - 1)
            + query(x1 - 1, y1 - 1, z2) + query(x1 - 1, y2, z1 - 1) + query(x2, y1 - 1, z1 - 1)
            - query(x1 - 1, y1 - 1, z1 - 1);
}

void solve() {
    cin >> n >> m;
    memset(grid, 0, sizeof(grid));
    
    while (m--) {
        string type;
        cin >> type;
        if (type == "UPDATE") {
            int x, y, z, w;
            cin >> x >> y >> z >> w;
            update(x, y, z, w);
        } else {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << query(x1, y1, z1, x2, y2, z2) << '\n';
        }
    }
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}