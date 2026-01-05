// https://codeforces.com/problemset/problem/479/B

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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	fu(i, 0, n - 1)
	{
		cin >> a[i];
	}

	vector<pi> ops;
	int diff = 0;
	fu(_, 1, k)
	{
		auto [min, max] = minmax_element(a.begin(), a.end());
		diff = *max - *min;
		if (diff <= 1)
			break;
		int i = max - a.begin();
		int j = min - a.begin();
		ops.push_back({ i, j });
		a[i] -= 1;
		a[j] += 1;
	}
	auto [min, max] = minmax_element(a.begin(), a.end());
	diff = *max - *min;
	cout << diff << " " << ops.size() << "\n";
	for (auto [i, j] : ops) {
		cout << i + 1 << " " << j + 1 << "\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solve();
}
