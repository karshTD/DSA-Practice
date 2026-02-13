#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, int> map;

    map[5] = 100;
    map[2] = 200;

    cout << map[5] << endl;

    if(map.find(2) != map.end())
    {
        cout << "2 exists";
    }
}
