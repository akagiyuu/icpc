// https://codeforces.com/problemset/problem/730/B

#include <algorithm>
#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

int cmp(int i, int j)
{
	cout << "? " << i << " " << j << endl;
	char c;
	cin >> c;
	if (c == '=')
		return 0;
	if (c == '<')
		return -1;
	return 1;
}

void solve()
{
	int n;
	cin >> n;
	int m, M, i;
	if (n % 2 == 0) {
		i = 3;
		m = 1;
		M = 2;
		if (cmp(1, 2) > 0) {
			swap(m, M);
		}
	} else {
		i = 2;
		m = 1;
		M = 1;
	}

	for (; i <= n; i += 2) {
		int cur_m = i, cur_M = i + 1;
		if (cmp(i, i + 1) > 0) {
			swap(cur_m, cur_M);
		}
		if(cmp(cur_m, m) < 0) {
			m = cur_m;
		}
		if(cmp(cur_M, M) > 0) {
			M = cur_M;
		}
	}

	cout << "! " << m << " " << M << endl;
}

signed main()
{
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}
