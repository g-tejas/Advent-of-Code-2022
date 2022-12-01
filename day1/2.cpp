#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string str_num;
	int sum, num, biggest = 0;
	vector<int> totals;

	while (getline(cin, str_num)) {
		if (str_num != "") {
			num = stoi(str_num);
			sum += num;
		} else {
			// cout << sum << endl;
			// this is when we reach a break point
			totals.push_back(sum);
			// biggest = max(biggest, sum);
			sum = 0; // need to reset to 0
		}
		
	}
	sort(totals.begin(), totals.end(), std::greater<int>());

	cout << totals[0] + totals[1] + totals[2] << std::endl;
}