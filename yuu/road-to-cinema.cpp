// https://codeforces.com/problemset/problem/729/C

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

const int INF = LLONG_MAX;

void solve()
{
	int n, k, s, t;
	cin >> n >> k >> s >> t;
	vector<pi> cars(n);
	fu(i, 0, n - 1)
	{
		cin >> cars[i].fi >> cars[i].se;
	}

	k++;
	vector<int> segments(k);
	fu(i, 0, k - 2)
	{
		cin >> segments[i];
	}
	segments[k - 1] = s;
	sort(segments.begin(), segments.end());
	fd(i, k - 1, 1)
	{
		segments[i] -= segments[i - 1];
	}
	sort(segments.begin(), segments.end());
	fu(i, 0, k - 1)
	{
		segments[i] *= 2;
	}

	vector<int> prefix(k);
	prefix[0] = segments[0];
	fu(i, 1, k - 1)
	{
		prefix[i] = prefix[i - 1] + segments[i];
	}
	auto sum_range = [&](int i, int j) { return i == 0 ? prefix[j] : prefix[j] - prefix[i - 1]; };

	int res = INF;
	for (auto [cost, capacity] : cars) {
		if (upper_bound(segments.begin(), segments.end(), 2 * capacity) != segments.end())
			continue;

		int i = upper_bound(segments.begin(), segments.end(), capacity) - segments.begin();
		int current_t = s + sum_range(i, k - 1) - (k - i) * capacity;
		if (current_t <= t)
			res = min(res, cost);
	}
	if (res == INF) {
		cout << -1 << "\n";
		return;
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
