#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

bool is_adjacent(pair<int, int> p1, pair<int, int> p2) {
	int dist = max(abs(p1.x - p2.x), abs(p1.y - p2.y));
	return dist <= 1;
}

int main() {
	set<pair<int, int>> visited;
	// stores the current xy coordinates
	vector<pair<int, int>> rope;
	int knots = 10;
	for (int i = 0; i < knots; i++) {
		pair<int, int> temp(0,0);
		rope.push_back(temp);
	}

	visited.insert(rope[9]); // need to enter the starting tail position

	char direction;
	int steps;


	while (cin >> direction >> steps) {
		// perform these calculations 'step' number of times
		while (steps--) {
			// calculate the next position of the head
			if (direction == 'U') rope[0].y++;
			else if (direction == 'D') rope[0].y--;
			else if (direction == 'L') rope[0].x--;
			else if (direction == 'R') rope[0].x++;

			// iterate through the ropes knots
			// determine if they need to be moved and move them accordingly
			// you need to compare the knot with the knot infront of it,
			// so - 1
			for (int i = 1; i < knots; i++) {
				if (!is_adjacent(rope[i], rope[i - 1])) {
					if (rope[i - 1].x - rope[i].x > 0) rope[i].x++;
					else if (rope[i - 1].x - rope[i].x < 0) rope[i].x--;

					if (rope[i - 1].y - rope[i].y > 0) rope[i].y++;
					else if (rope[i - 1].y - rope[i].y < 0) rope[i].y--;

					if (i == 9) {
						visited.insert(rope[i]);
					}
				}
			}
		}

	}

	cout << visited.size();
}
