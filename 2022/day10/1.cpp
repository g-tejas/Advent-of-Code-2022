#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> xs;
	int x = 1; // stores current value of X
	xs.push_back(x); // at the zeroth cycle

	string line;
	while (getline(cin, line)) {
		// two cases addx or noop
		stringstream ss(line);
		string op; ss >> op;

		if (op == "addx") {
			int v;
			ss >> v;
			for (int i = 0; i < 2; i++) {
				xs.push_back(x);
			}
			x += v;

		} else {
			// noop
			xs.push_back(x);
		}
	}
	xs.push_back(x);

	// for (int c : xs) {
	// 	cout << c << endl;
	// }

	cout << xs[20] * 20 + xs[60] * 60 + xs[100] * 100 + xs[140] * 140 + xs[180] * 180 + xs[220] * 220;
}
