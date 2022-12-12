#include <iostream>
#include <string>
#include <set>
using namespace std;

bool hasUniqueChars(const std::string& s) {
  // Create a set to store the characters in the string
  std::set<char> charSet;

  // Loop through all the characters in the string
  for (char c : s) {
    // Add the current character to the set
    charSet.insert(c);
  }

  // Check if the number of elements in the set is the same as the number of
  // characters in the string
  return charSet.size() == s.size();
}

int main() {
	string code;
	cin >> code;
	char a, b, c, d;
	for (int i = 0; i < code.size() - 13; i++) {
		string marker;
		marker = code.substr(i, 14);
		// cout << marker;
		if (hasUniqueChars(marker)) {
			cout << i + 14 << endl;
			break;
		} else {
			// cout << "false " << endl;
		}

	}
}
