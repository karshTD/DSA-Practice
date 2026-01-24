#include <iostream>
#include <vector>
using namespace std;

int main() {
vector<int> numbers;
numbers.push_back(10);
numbers.push_back(20);
numbers.push_back(30);


cout << "Vector elements: ";
for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
}
cout << endl;

numbers.pop_back();

cout << "After pop_back: ";
for (int num : numbers) {
    cout << num << " ";
}
cout << endl;

numbers.insert(numbers.begin() + 1, 15);

cout << "After insert: ";
for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    cout << *it << " ";
}
cout << endl;

cout << "First element: " << numbers.front() << endl;
cout << "Last element: " << numbers.back() << endl;
cout << "Vector size: " << numbers.size() << endl;

numbers.clear();
if (numbers.empty()) {
    cout << "Vector is empty" << endl;
}

return 0;
}

