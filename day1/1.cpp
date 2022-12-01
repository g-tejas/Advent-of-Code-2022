#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str_num;
	int sum, num, biggest = 0;

	while (getline(cin, str_num)) {
		if (str_num != "") {
			num = stoi(str_num);
			sum += num;
		} else {
			cout << sum << endl;
			// this is when we reach a break point
			biggest = max(biggest, sum);
			sum = 0; // need to reset to 0
		}
		
	}
	cout << biggest << endl;
}