// https://codeforces.com/problemset/problem/902/B

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
	vector<vector<int> > adj(n);
	fu(u, 1, n - 1)
	{
		int v;
		cin >> v;
		v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> c(n);
	fu(i, 0, n - 1) {
		cin >> c[i];
	}

	int res = 1;
	queue<int> q;
	vector<int> visited(n, false);
	q.push(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		visited[u] = true;
		for (auto v : adj[u]) {
			if (visited[v])
				continue;
			q.push(v);
			if (c[u] != c[v])
				res++;
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
	while (t--)
		solve();
}
