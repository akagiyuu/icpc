// https://codeforces.com/problemset/problem/429/D

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
	int n;
	cin >> n;
	vector<int> a(n);
	fu(i, 0, n - 1)
	{
		cin >> a[i];
	}
	fu(i, 1, n - 1)
	{
		a[i] += a[i - 1];
	}

	int res = LONG_LONG_MAX;
	fu(i, 0, n - 1)
	{
		fu(j, i + 1, n - 1)
		{
			int x = i - j;
			int y = a[i] - a[j];
			res = min(res, x * x + y * y);
		}
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
