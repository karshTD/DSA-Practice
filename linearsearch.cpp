#include <iostream>
using namespace std;

int linearSearch( int a[], int size , int target){
for ( int i = 0 ; i < size ; i++){
if ( a[i] == target ){
return i;}
}
return -1;
}

int main() {
int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = sizeof(array) / sizeof(int);
int target;
cout << "Enter number to search : ";
cin >> target;
int index = linearSearch(array, size, target);
if (index == -1){
cout << "Element not found";
} else {
cout << "Element found at index " << index;
 }
return 0;
}



