#include <iostream>
#include <ios>

using namespace std;

bool is_beautiful(int freq[52], bool should_check[52])
{
	int cur_freq = 0;
	for (int i = 0; i < 52; i++) {
		if (!should_check[i]) {
			continue;
		}
		if (cur_freq == 0) {
			cur_freq = freq[i];
		}

		if (freq[i] != cur_freq) {
			return false;
		}
	}
	return true;
}

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

	bool should_check[52] = { false };
	for (int i = 0; i < n; i++) {
		should_check[decode(s[i])] = true;
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		int freq[52] = { 0 };
		for (int j = i; j < n; j++) {
			freq[decode(s[j])] += 1;
            for(int i =0 ; i < 52; i++) {
                 cout << freq[i];
            }
			if (is_beautiful(freq, should_check)) {
				cout << i << " " << j << "\n";
				count += 1;
			}
		}
	}
	cout << count;
}
