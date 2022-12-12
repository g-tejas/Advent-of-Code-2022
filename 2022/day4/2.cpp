#include <iostream>
#include <sstream>
#include <string>
using namespace std;
 
int main() {
    string line;
    int num_overlapping_pairs = 0;

    while (getline(cin, line)) {
    	stringstream line_ss(line);
    	int a, b, c, d;
    	line_ss >> a >> b >> c >> d;
    	
    	if ((a <= d) && (c <= b)) {
    		num_overlapping_pairs++;
    		// cout << "yes" << endl;
    	} else {
    		// cout << "no" << endl;
    	}
    }

    cout << num_overlapping_pairs;
}