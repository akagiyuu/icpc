// https://codeforces.com/problemset/problem/385/D

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
const double EPS = 1e-8;
const double INF = 1e18;

typedef complex<double> P;
struct L : public vector<P> {
	L(const P &a, const P &b)
	{
		push_back(a);
		push_back(b);
	}
	L()
	{
	}
};
struct Light {
	P mid;
	double angle;
};

double cross(const P &a, const P &b)
{
	return imag(conj(a) * b);
}

P crosspoint(const L &l, const L &m)
{
	double A = cross(l[1] - l[0], m[1] - m[0]);
	double B = cross(l[1] - l[0], l[1] - m[0]);
	if (abs(A) < EPS)
		return P(INF, 0);
	return m[0] + B / A * (m[1] - m[0]);
}

P rotate(const P &p, double angle)
{
	return p * P(cos(angle), sin(angle));
}

void solve()
{
	int n;
	double l, r;
	cin >> n >> l >> r;

	vector<Light> lights(n);
	fu(i, 0, n - 1)
	{
		double x, y;
		cin >> x >> y;

		lights[i].mid = P(x, y);
		cin >> lights[i].angle;
		lights[i].angle *= PI / 180.;
	}

	L Ox(P(0, 0), P(1, 0));

	vector<double> dp(1ll << n, 0);
	fu(mask, 0, (1ll << n) - 1)
	{
		fu(i, 0, n - 1)
		{
			if ((mask >> i) & 1)
				continue;
			auto light = lights[i];
			P cur(l + dp[mask], 0);
			cur = rotate(cur - light.mid, light.angle) + light.mid;
			cur = crosspoint(Ox, L(light.mid, cur));
            if(cur.real() < l + dp[mask]) {
                cur = P(INF, 0);
            }
			dp[mask | (1ll << i)] = max(dp[mask | (1ll << i)], cur.real() - l);
		}
	}

	double res = 0;
	fu(mask, 0, (1ll << n) - 1)
	{
		res = max(res, dp[mask]);
	}
	res = min(res, r - l);

	cout << fixed << setprecision(6) << res << "\n";
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
