#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb emplace_back
#define F first
#define S second
#define fora(x, a) for(auto &x : a)

void solve(){

    int n,m;
    cin >> n >> m;

    vector<vector<char>> a(n + 2, vector<char>(m + 2));

    vector<vector<ll>> dp(n + 2, vector<ll>(m + 2, 0)); 

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }

    ll d = 1, col, row;
    for(int i = 1; i <= n; ++i){
        if (a[1][i] != '.') dp[1][i] = d; else d++; 
    }

    ll res = d;

    for(int i = 2; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if (a[i][j] != '.'){
                col = 0; row = 0;
                if (dp[i - 1][j] != 0){
                    if (dp[i - 1][j + 1] != dp[i - 1][j] && dp[i - 1][j - 1] != dp[i - 1][j]){
                        col = dp[i - 1][j];
                    }else 
                    if (dp[i][j - 1] != dp[i - 1][j - 1] && dp[i][j - 1] != dp[i + 1][j - 1]){
                        row = dp[i][j - 1];
                    }
                }
                if (col != 0) dp[i][j] = dp[i - 1][j];
                if (row != 0) dp[i][j] = dp[i][j - 1];
                if (col == 0 && row == 0){
                    dp[i][j] = ++d;
                }else if (col && row){
                    dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]);
                }
                res = max(dp[i][j], res);
            }
        }
    }

    cout << res << '\n';

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int t; cin >> t;while(t--) 
    solve();

}
