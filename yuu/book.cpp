// https://codeforces.com/problemset/problem/1572/A

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

int solve()
{
	int n;
	cin >> n;
	vector<vector<int> > lock(n);
	vector<int> deps_cnt(n);
	fu(i, 0, n - 1)
	{
		cin >> deps_cnt[i];
		fu(j, 0, deps_cnt[i] - 1)
		{
			int k;
			cin >> k;
			k--;
			lock[k].push_back(i);
		}
	}

	priority_queue<pi, vector<pi>, greater<pi> > finished;
	fu(i, 0, n - 1)
	{
		if (deps_cnt[i] == 0) {
			finished.push({ 1, i });
		}
	}

	int cnt = finished.size();
	int res = 1;
	while (!finished.empty()) {
		auto [step, u] = finished.top();
		finished.pop();

		for (auto v : lock[u]) {
			deps_cnt[v]--;
			if (deps_cnt[v] > 0)
				continue;
            cnt++;
			if (v > u) {
				finished.push({ step, v });
			} else {
                finished.push({ step + 1, v });
			}
		}

        res = max(res, step);
	}
	if (cnt < n)
		return -1;

	return res;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--)
		cout << solve() << "\n";
}
