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
  for (i = n; i > 0; i--) {
      for (int j = i - 1; j < n; j++) {
          if (a[i] > a[j]) {
              int t = a[i];
              a[i] = a[j];
              a[j] = t;

          }
      }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
