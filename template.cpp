#include <bits/stdc++.h>

#define int long long
#define double long double
#define fu(i, a, b) for (int i = (a); i <= (b); i++)
#define fd(i, a, b) for (int i = (a); i >= (b); i--)
#define fi first
#define se second
#define pi pair<int, int>

using namespace std;

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

bool maximize(int &a, int &b)
{
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
bool minimize(int &a, int &b)
{
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

void solve()
{
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

