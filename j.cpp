#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int MOD = 1000000007;

int decode(char c)
{
	if ('a' <= c && c <= 'z') {
		return c - 'a';
	}

	return c - 'A' + 26;
}
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n;
	cin >> s;

	vector<bool> should_check(52, false);
	for (int i = 0; i < n; i++) {
		should_check[decode(s[i])] = true;
	}
	int check_count = 0;
	for (int i = 0; i < 52; i++) {
		if (should_check[i]) {
			check_count += 1;
		}
	}

	vector<vector<int> > prefix_freq(n, vector<int>(52, 0));
	prefix_freq[0][decode(s[0])] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 52; j++) {
			prefix_freq[i][j] = prefix_freq[i - 1][j];
		}
		prefix_freq[i][decode(s[i])]++;
	}

	vector<int> zero(52, 0);

	int count = 0;
	for (int i = 0; i < n - check_count + 1; i++) {
        bool quit = false;
		for (int j = n - 1; j >= i + check_count - 1 && !quit; j--) {
			auto freq_left = i == 0 ? zero : prefix_freq[i - 1];
			auto freq_right = prefix_freq[j];
			int cur_freq = 0;

			bool is_beautiful = true;
			for (int i = 0; i < 52; i++) {
				if (!should_check[i]) {
					continue;
				}
				int value = freq_right[i] - freq_left[i];
				if (value == 0) {
                    is_beautiful = false;
                    quit = true;
                    break;
				}
				if (cur_freq == 0) {
					cur_freq = value;
				}

				if (value != cur_freq) {
					is_beautiful = false;
					break;
				}
			}
			if (is_beautiful) {
				count  = (count + 1) % MOD;
			}
		}
	}
	cout << count;
}
