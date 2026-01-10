// https://codeforces.com/problemset/problem/1665/C

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

struct Node {
	int cnt, infected_cnt;
};

bool operator>(const Node &a, const Node &b)
{
	if (a.cnt != b.cnt)
		return a.cnt > b.cnt;
	return a.infected_cnt < b.infected_cnt;
}

void solve()
{
	int n;
	cin >> n;
	vector<int> p(n);
	fu(i, 1, n - 1)
	{
		cin >> p[i];
		p[i]--;
	}
	vector<int> cnt(n, 0);
	fu(i, 1, n - 1)
	{
		cnt[p[i]]++;
	}

	vector<int> comps;
	fu(i, 0, n - 1)
	{
		if (cnt[i] > 0)
			comps.push_back(cnt[i]);
	}
	comps.push_back(1);
	n = comps.size();
	sort(comps.begin(), comps.end(), [](int a, int b) { return a > b; });

	int res = n;
	fu(i, 0, n - 1)
	{
		comps[i] -= n - i;
	}
	vector<int> ncomps;
	fu(i, 0, n - 1)
	{
		if (comps[i] > 0)
			ncomps.push_back(comps[i]);
	}
	comps = ncomps;
	n = comps.size();

    int min = 0;
	while (!comps.empty()) {
		res++;
		comps[0]--;
		int v = comps[0];
		int i = 1;
		for (; i < (int)comps.size() && comps[i] > v; i++) {
			comps[i - 1] = comps[i];
		}
		comps[i - 1] = v;
        min++;
		while (!comps.empty() && comps.back() <= min)
			comps.pop_back();
	}
	cout << res << "\n";
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
