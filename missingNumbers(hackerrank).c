#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int arr[200000], brr[200000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d", &brr[i]);

    int countA[10100] = {0}, countB[10100] = {0};
    for (int i = 0; i < n; i++) countA[arr[i]]++;
    for (int i = 0; i < m; i++) countB[brr[i]]++;

    int res[100], idx = 0;
    for (int i = 0; i < 10100; i++) {
        if (countB[i] > countA[i]) res[idx++] = i;
    }

    for (int i = 0; i < idx - 1; i++) {
        for (int j = i + 1; j < idx; j++) {
            if (res[i] > res[j]) {
                int t = res[i];
                res[i] = res[j];
                res[j] = t;
            }
        }
    }

    for (int i = 0; i < idx; i++) printf("%d ", res[i]);
    return 0;
}

