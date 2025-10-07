#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;
    s.pop(); 

    cout << "Now top: " << s.top(); 
}


//– LIFO (Last In, First Out)
