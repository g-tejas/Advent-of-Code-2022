#include <iostream>
#include <map>
using namespace std;


int main() {
	map<char, int> c2i;
	c2i.insert(pair<char, int>('A', 0));
	c2i.insert(pair<char, int>('B', 1));
	c2i.insert(pair<char, int>('C', 2));
	c2i.insert(pair<char, int>('X', 0));
	c2i.insert(pair<char, int>('Y', 1));
	c2i.insert(pair<char, int>('Z', 2));

	int m[3][3] = {{2, 0, 1}, {0, 1, 2}, {1, 2, 0}};

	map<char, int> outcomes;
	outcomes.insert(pair<char, int>('X', 0));
	outcomes.insert(pair<char, int>('Y', 3));
	outcomes.insert(pair<char, int>('Z', 6));

	// algo starts here
	char opp, me;
	int total_score = 0;
	
	while (cin >> opp >> me) {
		int score = 0;

		score += m[c2i[opp]][c2i[me]] + 1 + outcomes[me];
		total_score += score;
	}
	cout << total_score << endl;

}