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
				string dir_path;

				for (auto s : cwd) {
					dir_path += s;
					dir_sizes[dir_path] += stol(first_term);
				}
			}
		}
	}

	long used_space; used_space = dir_sizes["/"];
	long unused_space; unused_space = 7e7 - used_space;
	long min_dir_size = LONG_MAX;

	for (auto p : dir_sizes) {
		if (p.second + unused_space > 3e7) {
			min_dir_size = min(min_dir_size, p.second);
		} 
	}
	cout << min_dir_size;
}