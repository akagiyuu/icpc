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

vector<int> adj[N];
unordered_set<int> f[N];

unordered_set<int> dfs(int u) {
    f[u].insert(u);
    for (auto v : adj[u]) {
        auto tmp = dfs(v);
        f[u].insert(tmp.begin(), tmp.end());
    }
    return f[u];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    int n;
    cin >> n;
    set<int> tmp;
    for (int i = 1; i <= n; ++i) tmp.insert(i);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        tmp.erase(v);
    }

    int root = *tmp.begin();
    dfs(root);

    // for (int i = 1; i <= n; ++i) {
    //     cout << i << ": ";
    //     for (auto j : f[i]) cout << j << ' ';
    //     cout << endl;
    // }

    int t = 1;
    cin >> t;
    while(t--) {
        int u, v;
        cin >> u >> v;
        // for (auto x : f[u]) cout << x << ' ';
        if (f[u].find(v) != f[u].end()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
