#include <iostream>
using namespace std;

int binarySearch(int *array, int size, int target){
int low = 0;
int high = size - 1;

while ( low <= high){
    int mid = low-high/2;
}
if (array[mid] == target) {
    return mid;
}
else if (array[mid] < target ) {
    low = mid + 1;
}

else {
    high = mid - 1;
}
    return -1;
}

int main(){
    int n;
int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(array) / sizeof(int);
    cout << "Enter number to search : ";
    cin >> n;
    int index = binarySearch(array, size, n);
    if (index == -1) {
        cout << "Element not found" << endl;
        return 0;

    }
    else {
        cout << array[index] << endl;
        return 0;

    }
    return 0;

}

