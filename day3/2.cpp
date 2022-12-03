#include <iostream>
#include <set>
using namespace std;

string find_common_characters(string s1, string s2) {
	set<char> set1;
	for (int i = 0; i < s1.size(); i++) {
		set1.insert(s1[i]);
	}

	set<char> set2;
	for (char c : s2){
		set2.insert(c);
	}

	set<char> intersection;
  	// Find the intersection of the two sets
  	// std::set<char> intersection;
  	std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(),
                        std::inserter(intersection, intersection.begin()));

  	// Create a string from the intersection set
 	string result;
  	for (char c : intersection) {
    	result += c;
  	}
  	return result;
}

int main() {
	string r1, r2, r3;
	int sum_priority = 0;

	while(cin >> r1 >> r2 >> r3) {
		string temp;
		char error;
		temp = find_common_characters(r1, r2);
		error = find_common_characters(temp, r3)[0];
		// cout << common << endl;

		if (islower(error)) {
			sum_priority += (int) error - 96;
		} else {
			sum_priority += (int) error - 38;
		}
	}
	cout << sum_priority << endl;
}