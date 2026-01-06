// https://codeforces.com/problemset/problem/2072/F

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
	int n, k;
	cin >> n >> k;
	n--;
	fu(i, 0, n)
	{
		if (i & (n - i)) {
			cout << 0 << " ";
		} else {
			cout << k << " ";
		}
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
