// https://codeforces.com/problemset/problem/735/C

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
	if (n == 2)
		return 1;

	int ans = 2;
	int a = 1, b = 2, c = 3;
	while (c <= n) {
        a = b;
        b = c;
        c = a + b;
        ans++;
	}
    ans--;
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--)
		cout << solve() << "\n";
}
