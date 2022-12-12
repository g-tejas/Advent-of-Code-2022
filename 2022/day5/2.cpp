#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// learnt about stacks and vectors
// only modified from 1st parts lightly by adding a temp stack to maintain order.
// the algo idea was easy af, simply didn't know c++ syntax enuf to code it faster
// im sure the container inputs can be automated tho but i couldnt be bothered

int main() {
    vector<stack<char>> containers;
    // Add some stacks to the array
    for (int i = 0; i < 10; i++) {
        containers.push_back(std::stack<char>());        
    }

    containers[1].push('G');
    containers[1].push('F');
    containers[1].push('V');
    containers[1].push('H');
    containers[1].push('P');
    containers[1].push('S');

    containers[2].push('G');
    containers[2].push('J');
    containers[2].push('F');
    containers[2].push('B');
    containers[2].push('V');
    containers[2].push('D');
    containers[2].push('Z');
    containers[2].push('M');

    containers[3].push('G');
    containers[3].push('M');
    containers[3].push('L');
    containers[3].push('J');
    containers[3].push('N');
    
    containers[4].push('N');
    containers[4].push('G');
    containers[4].push('Z');
    containers[4].push('V');
    containers[4].push('D');
    containers[4].push('W');
    containers[4].push('P');
    
    containers[5].push('V');
    containers[5].push('R');
    containers[5].push('C');
    containers[5].push('B');
    
    containers[6].push('V');
    containers[6].push('R');
    containers[6].push('S');
    containers[6].push('M');
    containers[6].push('P');
    containers[6].push('W');
    containers[6].push('L');
    containers[6].push('Z');
    
    containers[7].push('T');
    containers[7].push('H');
    containers[7].push('P');
    
    containers[8].push('Q');
    containers[8].push('R');
    containers[8].push('S');
    containers[8].push('N');
    containers[8].push('C');
    containers[8].push('H');
    containers[8].push('Z');
    containers[8].push('V');
    
    containers[9].push('F');
    containers[9].push('L');
    containers[9].push('G');
    containers[9].push('P');
    containers[9].push('V');
    containers[9].push('Q');
    containers[9].push('J');

    string instruction;
    int count, from, to;

    while(cin >> count >> from >> to) {
        stack<char> temp_stack;
        for (int i = 0; i < count; i++) {
            char temp = containers[from].top();
            containers[from].pop();
            temp_stack.push(temp);
        }
        for (int i = 0; i < count; i++) {
            char temp = temp_stack.top();
            temp_stack.pop();
            containers[to].push(temp);
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << containers[i].top();
    }
}