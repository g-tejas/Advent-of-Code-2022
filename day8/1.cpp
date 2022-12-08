#include <bits/stdc++.h>
using namespace std;

int main() {
	int scenic_score = INT_MIN;
	vector<vector<int>> forest;
	string line;
	while(getline(cin, line)) {
		vector<int> temp;
		for (int i = 0; i < line.size(); ++i) {
			temp.push_back(line[i] - '0');
		}
		forest.push_back(temp);
	}

	int nR = forest.size(), nC = forest.size();
	int count = 0;

	for (int row = 0; row < forest.size(); ++row) {
		for (int col = 0; col < forest.size(); ++col) {
			int up, down, left, right;
			up = row;
			down = nR - row - 1;
			left = col;
			right = nC - col - 1;

			if (up == 0 || down == 0 || left == 0 || right == 0) {
				count++;
			} else {
				// in the up direction, we need to check if
				// the number of trees of height < current tree == 
				// its position
				int temp = up, up_count = 0;
				for (int i = 0; i < temp + 1; ++i) {
					if (forest[i][col] < forest[row][col]) {
						up_count++;
					}
				}
				if (up_count == row) {
					count++;
					continue;
				}

				// in the down direction, we need to check the same thing
				int down_count = 0;
				for (int i = row + 1; i < nR; i++) {
					if (forest[i][col] < forest[row][col]) {
						down_count++;
					}
				}
				if (down_count == nR - row - 1) {
					count++;
					continue;
				}

				// in the left direction, check the same thing
				int left_count = 0;
				for (int i = 0; i < col; i++) {
					if (forest[row][i] < forest[row][col]) {
						left_count++;
					}
				}
				if (left_count == col) {
					count++;
					continue;
				}

				// in the right direction, check the same thing
				int right_count = 0;
				for (int i = col + 1; i < nC; i++) {
					if (forest[row][i] < forest[row][col]) {
						right_count++;
					}
				}
				if (right_count == nC - col - 1) {
					count++;
					continue;
				}
			}
		}
	}
	cout << count;
}
