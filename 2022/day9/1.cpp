#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

bool is_adjacent(pair<int, int> p1, pair<int, int> p2) {
	int dist = max(abs(p1.x - p2.x), abs(p1.y - p2.y));
	return dist == 1 || dist == 0;
}

int main() {
	set<pair<int, int>> visited;
	// stores the current xy coordinates
	pair<int, int> head(0,0);
	pair<int, int> tail(0,0);
	visited.insert(tail);

	char direction;
	int steps;

	while (cin >> direction >> steps) {
		// perform these calculations 'step' number of times
		while (steps--) {
			// calculate the next position of the head
			if (direction == 'U') head.y++;
			else if (direction == 'D') head.y--;
			else if (direction == 'L') head.x--;
			else if (direction == 'R') head.x++;

			// we only move the tail if their chebyshev distance > 1
			if (!is_adjacent(head, tail)) {
				if (head.x - tail.x > 0) tail.x++;
				else if (head.x - tail.x < 0) tail.x--;

				if (head.y - tail.y > 0) tail.y++;
				else if (head.y - tail.y < 0) tail.y--;

				// since we moved the tail, we add it into the visited list
				visited.insert(tail);
			}
		}

	}

	cout << visited.size();
}
