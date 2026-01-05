// https://codeforces.com/problemset/problem/2020/C

#include <bits/stdc++.h>

#define int unsigned long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

const int NBIT = 64;

void solve()
{
	int b, c, d;
	cin >> b >> c >> d;
	int a = 0;
	fu(i, 0, NBIT - 1)
	{
		int bi = b & (1ull << i);
		int ci = c & (1ull << i);
		int di = d & (1ull << i);
		if (bi == ci && bi != di)
			a |= 1ull << i;
	}
	if((a | b) - (a & c) != d) {
		cout << -1 << "\n";
	} else {
		cout << a << "\n";
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
