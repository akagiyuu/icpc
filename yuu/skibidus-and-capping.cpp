// https://codeforces.com/problemset/problem/2065/G

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;

vector<int> pr;
int lp[N];

void build()
{
	fu(i, 2, N - 1)
	{
		if (lp[i] == 0) {
			pr.push_back(i);
			lp[i] = i;
		}
		for (int j = 0; i * pr[j] < N; j++) {
			lp[i * pr[j]] = pr[j];
			if (pr[j] == lp[i])
				break;
		}
	}
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

	map<int, int> cnt_prime, cnt_semiprime;
	for (auto x : a) {
		vector<int> f;
		int tmp = x;
		while (tmp > 1) {
			f.push_back(lp[tmp]);
			tmp /= lp[tmp];
			if (f.size() > 2)
				break;
		}
		if (f.size() > 2)
			continue;
		if (f.size() == 1)
			cnt_prime[x]++;
		if (f.size() == 2)
			cnt_semiprime[x]++;
	}

	int res = 0;
	int sum = 0;
	for (auto [_, cnt] : cnt_prime) {
		sum += cnt;
	}
	for (auto [p, cnt] : cnt_prime) {
		res += cnt * (sum - cnt);
	}
	res /= 2;

	for (auto [sp, cnt] : cnt_semiprime) {
		int p = lp[sp];
		int q = sp / p;
		res += cnt * (cnt + 1) / 2;
		res += cnt * cnt_prime[p];
		if (p != q)
			res += cnt * cnt_prime[q];
	}

	cout << res << "\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	build();

	int t = 1;
	cin >> t;
	while (t--)
		solve();
}
