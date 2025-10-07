#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << endl;
    q.pop(); 
    cout << "New Front: " << q.front(); 
return 0;

}

//first in first out 
