// https://codeforces.com/problemset/problem/615/D

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

const int MOD = 1e9 + 7;

int powmod(int a, int b)
{
    a %= MOD;
    b %= MOD - 1;
	int res = 1;
	while (b) {
		if (b & 1)
			res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void solve()
{
	int m, p;
	cin >> m;
	map<int, int> mp;
	fu(i, 1, m)
	{
		cin >> p;
		mp[p] += 1;
	}

	int res = 1;
    int prev_cnt = 1;
	for (auto [p, cnt] : mp) {
        res = powmod(res, cnt + 1);
        res = res * powmod(powmod(p, cnt * (cnt + 1) / 2), prev_cnt) % MOD;
        prev_cnt = prev_cnt * (cnt + 1) % (MOD - 1);
	}
    cout << res << "\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--)
		solve();
}
