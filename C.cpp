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
    int min_cost = *min_element(w + 1, w + n + 1);

    for (int i = 1; i <= n; ++i) {
        if (origin[i] == required[i] || vst[i]) continue;

        int cur = i;
        int cycle_size = 0;
        ll cycle_min = LLONG_MAX;
        ll cycle_sum = 0;

        while (!vst[cur]) {
            vst[cur] = true;
            int color = origin[cur];
            cycle_min = min(cycle_min, (ll) w[color]);
            cycle_sum += w[color];
            cycle_size++;
            cur = pos[color];
        }

        total_cost += min(cycle_sum + (cycle_size - 2) * cycle_min, 
                          cycle_sum + cycle_min + (cycle_size + 1) * min_cost);
    }

    cout << total_cost;

    return 0;
}