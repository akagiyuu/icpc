// https://codeforces.com/problemset/problem/140/A

#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

const double PI = acos(-1);
const double EPS = 1e-7;

void solve()
{
	double n, R, r;
	cin >> n >> R >> r;
	if (n == 1) {
		if (r <= R) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		return;
	}
	double possible = 2.L * (R - r) * sinl(PI / n);
	if (possible - 2.L * r > -EPS) {
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
	// cin >> t;
	while (t--)
		solve();
}
