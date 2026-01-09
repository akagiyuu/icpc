// https://codeforces.com/problemset/problem/459/D

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

vector<int> a, f, g;

int count(int l, int r)
{
	if (r - l <= 1)
		return 0;

	int mid = (l + r) / 2;
	int res = count(l, mid) + count(mid, r);

    fu(i, l, mid - 1) {
        int j = lower_bound(g.begin() + mid, g.begin() + r, f[i]) - g.begin();
        res += j - mid;
    }

	inplace_merge(g.begin() + l, g.begin() + mid, g.begin() + r);

    return res;
}

void solve()
{
	int n;
	cin >> n;
	a.resize(n);
	f.resize(n);
	g.resize(n);
	fu(i, 0, n - 1)
	{
		cin >> a[i];
	}
	map<int, int> cnt;
	fu(i, 0, n - 1)
	{
		cnt[a[i]]++;
		f[i] = cnt[a[i]];
	}
	cnt.clear();
	fd(i, n - 1, 0)
	{
		cnt[a[i]]++;
		g[i] = cnt[a[i]];
	}
    cout << count(0, n) << "\n";
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
