#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	vector<string> cwd;
	map<string, long> dir_sizes;

	while(getline(cin, line)) {
		stringstream ss(line);
		string first_term;
		ss >> first_term;

		if (first_term == "$") {
			string command;
			ss >> command;

			// no need for handling $ ls
			if (command == "cd") {
				string dir_name;
				ss >> dir_name;

				if (dir_name == "..") {
					cwd.pop_back();
				} else {
					cwd.push_back(dir_name);
				}
			}
		} else  {
			// encountered a file
			if (first_term != "dir") {
				// There could be nested directories with the same name
				// so you need to concatenate the strings
				string dir_path;

				for (auto s : cwd) {
					dir_path += s;
					dir_sizes[dir_path] += stol(first_term);
				}
			}
		}
	}

	long total = 0;
	for (auto p : dir_sizes) {
		if (p.second <= 100000) {
			total += p.second;
		}
	}
	cout << total;
}