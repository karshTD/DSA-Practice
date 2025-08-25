#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    char *num1 = *(char **)a;
    char *num2 = *(char **)b;

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (len1 != len2)
        return len1 - len2;

    return strcmp(num1, num2);
}

int main() {
    int n;
    scanf("%d", &n);

    char **arr = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(10240 * sizeof(char));
        scanf("%s", arr[i]);
    }

    qsort(arr, n, sizeof(char *), compare);

    for (int i = 0; i < n; i++)
        printf("%s\n", arr[i]);

    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);

    return 0;
}
//
// Created by utkar on 8/1/2025.
//
