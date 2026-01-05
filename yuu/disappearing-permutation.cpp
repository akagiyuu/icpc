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
	vector<int> a(n + 1);
	fu(i, 1, n)
	{
		cin >> a[i];
	}
	vector<int> d(n + 1);
	fu(i, 1, n)
	{
		cin >> d[i];
	}

	int cnt = 0;
	fu(i, 1, n)
	{
		int j = d[i];
		while (a[j] != 0) {
			int k = a[j];
			a[j] = 0;
			j = k;
			cnt++;
		}
		cout << cnt << " ";
	}
	cout << "\n";
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
