#include <iostream>
#include <ios>
#include <vector>

using namespace std;

int MOD = 1000000007;

struct Pacman {
	int dir;
	int x;
	int y;
};

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, p, m;
	cin >> n >> p >> m;
	vector<Pacman> pacmans(p);
	for (size_t i = 0; i < p; i++) {
		cin >> pacmans[i].dir >> pacmans[i].x >> pacmans[i].y;
	}

	int combined_x = 0;
	int combined_y = 0;

	while (m--) {
		int type, k;
		cin >> type >> k;
		if (type == 3) {
			combined_x = k / n;
			combined_y = k % n;
		}
	}
}
