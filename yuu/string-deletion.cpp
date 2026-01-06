// https://codeforces.com/problemset/problem/1430/D

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
	string s;
	cin >> n >> s;
	vector<pi> groups;

	char prev = s[0];
	int cnt = 1;
	fu(i, 1, n - 1)
	{
		if (s[i] == prev) {
			cnt++;
			continue;
		}

		groups.push_back({ prev - '0', cnt });
		prev = s[i];
		cnt = 1;
	}
	groups.push_back({ prev - '0', cnt });
	reverse(groups.begin(), groups.end());
	n = groups.size();

	int res = 0;
	int idx = -1;
	fd(i, n - 1, 0)
	{
		if (groups[i].se > 1) {
			idx = i;
			break;
		}
	}
	while (!groups.empty()) {
		n = groups.size();
		if (idx == -1) {
			res += (n + 1) / 2;
			break;
		}
        idx = min(idx, n - 1);
		if (groups[idx].se == 1) {
			fd(i, idx - 1, 0)
			{
				if (groups[i].se > 1) {
					idx = i;
					break;
				}
			}
		}
		if (groups[idx].se == 1) {
			res += (n + 1) / 2;
			break;
		}

		res++;
		groups[idx].se--;
		if (!groups.empty())
			groups.pop_back();
	}
	cout << res << "\n";
}

signed main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.tie(NULL);

	int t = 1;
	cin >> t;
	while (t--)
		solve();
}
