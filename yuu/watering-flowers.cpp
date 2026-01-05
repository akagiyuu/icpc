// https://codeforces.com/problemset/problem/617/C

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

const unsigned int INF = ULONG_LONG_MAX;

struct pt {
	int x, y;
};

unsigned int dist(const pt &a, const pt &b)
{
	unsigned int dx = abs(a.x - b.x);
	unsigned int dy = abs(a.y - b.y);

	return dx * dx + dy * dy;
}

void solve()
{
	int n;
	cin >> n;
	pt c1, c2;
	cin >> c1.x >> c1.y >> c2.x >> c2.y;
	vector<pt> a(n);
	fu(i, 0, n - 1) {
		cin >> a[i].x >> a[i].y;
	}

	unsigned int res = 0;
	fu(i, 0, n - 1) {
		res = max(res, dist(c2, a[i]));
	}
	fu(i, 0, n - 1) {
		unsigned int r1 = dist(c1, a[i]);
		unsigned int r2 = 0;
		fu(j, 0, n - 1) {
			if(dist(c1, a[j]) <= r1) continue;
			r2 = max(r2, dist(c2, a[j]));
		}
		res = min(res, r1 + r2);
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
