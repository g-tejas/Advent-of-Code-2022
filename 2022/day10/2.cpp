#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> xs; // this tells us the position of the 
	// sprite middle at the start of each cycle
	int x = 1; // stores current value of X
	// xs.push_back(x); // at the zeroth cycle

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

	// prints out the array
	for (int i = 0; i < 240; i++) {
		// we need to choose whether to print . or #
		if (abs( (i % 40) - xs[i]) <= 1) cout << "#";
		else cout << ".";
		if (i == 39 || i == 79 || i == 119 || i == 159 || i == 199 || i == 239) {
			cout << "\n";
		}
	}
}
