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

			if (row == 0 || row == nR - 1 || col == 0 || col == nC - 1) {
				// scenic score of any edge tree is zero,
				// since we are multiplying
				continue;
			} else {
				int up_viewable = 0; // even if its blocked it can 
				// see the blocked tree so start from 1
				for (int i = row - 1; i >= 0; --i) {
					if (forest[i][col] < forest[row][col]) {
						up_viewable++;
					} else {
						up_viewable++;
						break;
					}
				}


				// in the down direction, we need to check the same thing
				int down_viewable = 0;
				for (int i = row + 1; i < nR; i++) {
					if (forest[i][col] < forest[row][col]) {
						down_viewable++;
					} else {
						down_viewable++;
						break;
					}
				}
				

				// in the left direction, check the same thing
				int left_viewable = 0;
				for (int i = col - 1; i >= 0; i--) {
					if (forest[row][i] < forest[row][col]) {
						left_viewable++;
					} else {
						left_viewable++;
						break;
					}
				}
				
				// in the right direction, check the same thing
				int right_viewable = 0;
				for (int i = col + 1; i < nC; i++) {
					if (forest[row][i] < forest[row][col]) {
						right_viewable++;
					} else {
						right_viewable++;
						break;
					}
				}


				int current_score = down_viewable * up_viewable * right_viewable * left_viewable;
				scenic_score = max(scenic_score, current_score);
			}
		}
	}
	cout << scenic_score;
}
