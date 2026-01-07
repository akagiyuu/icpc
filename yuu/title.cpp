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
	int k;
	cin >> k;
	k--;
	string s;
	cin >> s;
	int n = s.size();

	fu(i, 0, n / 2 - 1)
	{
		int j = n - 1 - i;
		if (s[i] == '?' && s[j] == '?') {
			continue;
		}
		if (s[i] == '?') {
			s[i] = s[j];
			continue;
		}
		if (s[j] == '?') {
			s[j] = s[i];
			continue;
		}
		if (s[i] != s[j]) {
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	vector<bool> available(k + 1, true);
	fu(i, 0, n / 2)
	{
		if (s[i] == '?')
			continue;
		available[s[i] - 'a'] = false;
	}
	queue<char> possible;
	fd(i, k, 0)
	{
		if (available[i])
			possible.push('a' + i);
	}

	fd(i, n / 2, 0)
	{
		int j = n - 1 - i;
		if (s[i] != '?' || s[j] != '?')
			continue;

        char c = 'a';
        if(!possible.empty()) {
            c = possible.front();
            possible.pop();
        }
        s[i] = c;
        s[j] = c;
	}
    if(!possible.empty()) {
        cout << "IMPOSSIBLE\n";
        return;
    }
	cout << s << "\n";
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
