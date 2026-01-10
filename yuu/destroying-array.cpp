// https://codeforces.com/problemset/problem/722/C

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

int n;
vector<int> a, parent, sz, sum;
int max_sum = 0;

void init()
{
	parent.resize(n);
	sz.resize(n);
	sum.resize(n);
}

void make(int x)
{
	sz[x] = 1;
	parent[x] = x;
	sum[x] = a[x];
	max_sum = max(max_sum, a[x]);
}

int find(int x)
{
	while (parent[x] != x)
		x = parent[x];

	return x;
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
		return;

	if (sz[x] > sz[y])
		swap(x, y);
	parent[x] = y;
	sz[y] += sz[x];
	sum[y] += sum[x];
	max_sum = max(max_sum, sum[y]);
}

void solve()
{
	cin >> n;
	a.resize(n);
	init();
	fu(i, 0, n - 1)
	{
		cin >> a[i];
	}
	vector<int> p(n);
	fu(i, 0, n - 1)
	{
		cin >> p[i];
		p[i]--;
	}

	vector<bool> is_added(n, false);
	vector<int> res;
	fd(i, n - 1, 0)
	{
		res.push_back(max_sum);
		int x = p[i];
		make(x);
		is_added[x] = true;
		if (x <= n - 2 && is_added[x + 1]) {
			unite(x, x + 1);
		}
		if (x >= 1 && is_added[x - 1]) {
			unite(x, x - 1);
		}
	}
    fd(i, (int)res.size() - 1, 0) {
        cout << res[i] << "\n";
    }
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
