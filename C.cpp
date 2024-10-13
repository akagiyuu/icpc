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
const int N = 1e6 + 5;

int n, w[N], origin[N], required[N], pos[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // freopen(NAME".inp", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) cin >> origin[i];
    for (int i = 1; i <= n; ++i) {
        cin >> required[i];
        pos[required[i]] = i;
    }

    vector<int> vst(n + 1, false);
    
    ll total_cost = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vst[i]) {
            int cur = i;
            int cycle_size = 0;
            ll cost = 0;
            ll min_cost = LLONG_MAX;
            while (!vst[cur]) {
                vst[cur] = true;
                cost += w[origin[cur]];
                min_cost = min(min_cost, (ll) w[origin[cur]]);
                cur = pos[origin[cur]];
                cycle_size++;
            }   

            if (cycle_size > 1) {
                total_cost += cost + (cycle_size - 2) * min_cost;
            }
        }
    }

    cout << total_cost;

    return 0;
}