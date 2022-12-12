#include <bits/stdc++.h>
using namespace std;

bool test(int idx, int worry) {
	int tests[8] = {7,11,13,3,17,2,5,19};
	return worry % tests[idx] == 0;
}

int op(int idx, int worry) {
	switch (idx) {
		case 0: {
			return worry * 11;
		}
		case 1: {
			return worry + 1;
		}
		case 2: {
			return worry * 7;
		}
		case 3: {
			return worry + 3;
		}
		case 4: {
			return worry + 6;
		} 
		case 5: {
			return worry + 5;
		}
		case 6: {
			return worry * worry;
		}
		case 7: {
			return worry + 7;
		}
		default:
			return worry;
	}
}

int main() {
	vector<queue<int>> m_items;
	queue<int> m0;
	m0.push(63); m0.push(57);
	queue<int> m1;
	m1.push(82); m1.push(66); m1.push(87);
	m1.push(78); m1.push(77); m1.push(92); m1.push(83);
	queue<int> m2;
	m2.push(97); m2.push(53); m2.push(53); m2.push(85);
	m2.push(58); m2.push(54);
	queue<int> m3;
	m3.push(50);
	queue<int> m4;
	m4.push(64); m4.push(69); m4.push(52); m4.push(65);
	m4.push(73);
	queue<int> m5;
	m5.push(57); m5.push(91); m5.push(65);
	queue<int> m6;
	m6.push(67); m6.push(91); m6.push(84); m6.push(78);
	m6.push(60); m6.push(69); m6.push(99); m6.push(83);
	queue<int> m7;
	m7.push(58); m7.push(78); m7.push(69); m7.push(65);
	m_items.push_back(m0); m_items.push_back(m1);
	m_items.push_back(m2); m_items.push_back(m3);
	m_items.push_back(m4); m_items.push_back(m5);
	m_items.push_back(m6); m_items.push_back(m7);

	// matrix for who to add to
	int m[4][2]; // 1 is pass, 0 is fail
	m[0][0] = 2; m[0][1] = 6;
	m[1][0] = 0; m[1][1] = 5;
	m[2][0] = 3; m[2][1] = 4;
	m[3][0] = 7; m[3][1] = 1;
	m[4][0] = 7; m[4][1] = 3;
	m[5][0] = 6; m[5][1] = 0;
	m[6][0] = 4; m[6][1] = 2;
	m[7][0] = 1; m[7][1] = 5;

	int ic[8] = {0,0,0,0,0,0,0,0};
	for (int rd = 0; rd < 20; rd++) {
		for (int i = 0; i < m_items.size(); i++) {
			// for each monkey, conduct inspection
			while (!m_items[i].empty()) {
				ic[i]++;
				// do this while its not empty
				int item = op(i, m_items[i].front()) / 3;
				m_items[i].pop();
				int next_monkey = m[i][test(i, item)];
				m_items[next_monkey].push(item);
			}
		}
	}
	
	int n = sizeof(ic) / sizeof(ic[0]);
	// Sort the array in descending order
    sort(ic, ic + n, greater<int>());
	for (int i : ic) {
		cout << i << " ";
	}
}
