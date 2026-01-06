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

const __int128 INF = 1e18;

struct pt {
	int x, y;
};

__int128 dist(const pt &a, const pt &b)
{
	__int128 dx = a.x - b.x;
	__int128 dy = a.y - b.y;

	return dx * dx + dy * dy;
}

__int128 nearest_dist(int l, int r, vector<pt> &p)
{
	if (r - l <= 3) {
		__int128 res = INF;
		fu(i, l, r - 1)
		{
			fu(j, i + 1, r - 1)
			{
				res = min(res, dist(p[i], p[j]));
			}
		}
		sort(p.begin() + l, p.begin() + r, [](const pt &a, const pt &b) {
			if (a.y != b.y)
				return a.y < b.y;
			return a.x < b.x;
		});
		return res;
	}

	int m = (l + r) / 2;
	int mx = p[m].x;

	__int128 res = nearest_dist(l, m, p);
	res = min(res, nearest_dist(m, r, p));

	inplace_merge(p.begin() + l, p.begin() + m, p.begin() + r, [](const pt &a, const pt &b) {
		if (a.y != b.y)
			return a.y < b.y;
		return a.x < b.x;
	});

	vector<pt> strip;
	fu(i, l, r - 1)
	{
		__int128 dx = p[i].x - mx;
		if (dx * dx < res) {
			strip.push_back(p[i]);
		}
	}

	int n = strip.size();
	fu(i, 0, n - 1)
	{
		fu(j, i + 1, n - 1)
		{
			__int128 dy = strip[i].y - strip[j].y;
			if (dy * dy >= res)
				break;
			res = min(res, dist(strip[i], strip[j]));
		}
	}

	return res;
}

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

	vector<pt> p(n);
	fu(i, 0, n - 1)
	{
		p[i].x = i;
		p[i].y = a[i];
	}

	sort(p.begin(), p.end(), [](const pt &a, const pt &b) {
		if (a.x != b.x)
			return a.x < b.x;
		return a.y < b.y;
	});
	cout << (int)nearest_dist(0, n, p) << "\n";
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
