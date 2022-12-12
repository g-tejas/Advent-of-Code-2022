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

	int m[3][3] = {{0, -1, 1}, {1, 0, -1}, {-1, 1, 0}};

	map<int, int> outcomes;
	outcomes.insert(pair<int, int>(-1, 0));
	outcomes.insert(pair<int, int>(0, 3));
	outcomes.insert(pair<int, int>(1, 6));

	map<char, int> shapes;
	shapes.insert(pair<char, int>('X', 1)); // rock
	shapes.insert(pair<char, int>('Y', 2)); // paper
	shapes.insert(pair<char, int>('Z', 3)); // scissors

	// algo starts here

	char opp, me;
	int total_score = 0;
	
	while (cin >> opp >> me) {
		int score = 0;

		score += shapes[me] + outcomes[m[c2i[me]][c2i[opp]]];
		total_score += score;
	}
	cout << total_score << endl;

}