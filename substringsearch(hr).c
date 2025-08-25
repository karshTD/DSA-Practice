#include <stdio.h>
#include <string.h>

int isSubstring(const char *text, const char *pat) {
    if (strlen(pat) == 0) {
        return 1; // Empty pattern is always a substring
    }
    if (strlen(pat) > strlen(text)) {
        return 0; // Pattern longer than text can't be a substring
    }
    return strstr(text, pat) != NULL;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char text[100001];
        char pat[100001];
        scanf("%s", text);
        scanf("%s", pat);
        printf(isSubstring(text, pat) ? "YES\n" : "NO\n");
    }
    return 0;
}