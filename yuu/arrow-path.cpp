// https://codeforces.com/problemset/problem/1948/C

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

bool dfs(int u, int end, vector<bool> &visited, const vector<vector<int> > &adj)
{
	if (u == end)
		return true;
	if (visited[u])
		return false;

	visited[u] = true;
	for (auto v : adj[u]) {
		if (dfs(v, end, visited, adj))
			return true;
	}
	return false;
}

void solve()
{
	int n;
	cin >> n;
	array<string, 2> grid;
	cin >> grid[0] >> grid[1];

	auto encode = [n](int i, int j) { return i == 0 ? j : n + j; };
	vector<vector<int> > adj(2 * n);
	array<pi, 4> direction = { {
		{ 1, 0 },
		{ -1, 0 },
		{ 0, 1 },
		{ 0, -1 },
	} };
	fu(i, 0, 1)
	{
		fu(j, 0, n - 1)
		{
			for (auto [di, dj] : direction) {
				int ni = i + di;
				int nj = j + dj;
				if (ni < 0 || ni >= 2 || nj < 0 || nj >= n)
					continue;
				if (grid[ni][nj] == '>')
					nj++;
				else if (grid[ni][nj] == '<')
					nj--;
				if (i != ni || j != nj)
					adj[encode(i, j)].push_back(encode(ni, nj));
			}
		}
	}
	vector<bool> visited(2 * n, false);
	if (dfs(0, encode(1, n - 1), visited, adj)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
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
