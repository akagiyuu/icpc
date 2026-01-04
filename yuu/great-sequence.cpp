// https://codeforces.com/problemset/problem/1641/A

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

void solve()
{
	int n, x, tmp;
	cin >> n >> x;
	map<int, int> cnt;
	fu(i, 0, n - 1)
	{
		cin >> tmp;
		cnt[tmp]++;
	}
    int res = 0;
	for (auto [val, c] : cnt) {
        if(c == 0) continue;

        int c2 = cnt[val * x];
        res += max(c - c2, 0ll);
        cnt[val * x] = max(c2 - c, 0ll);
	}
    cout << res << "\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--)
		solve();
}
