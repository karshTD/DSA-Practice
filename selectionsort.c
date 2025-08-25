#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int m, loc, temp;
    for (i = 0; i < n; i++) {
        m = a[i];
        loc = i;
        for ( int j = i+1; j < n; j++) {
            if ( m > a[j]) {
                m = a[j];
                loc = j;

            }
        }
        if ( a[loc] < a[i]) {
            temp = a[loc];
            a[loc] = a[i];
            a[i] = temp;
        }

    }

    printf("The sorted array is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }


    return 0;
}


