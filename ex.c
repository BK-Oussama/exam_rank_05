#include <stdio.h>

int main() {
    FILE *file = fopen("data.txt", "r");
    if (!file) return 1;

    int num;
    char c1, c2, c3;
    if (fscanf(file, "%d %c %c %c", &num, &c1, &c2, &c3) == 4) {
        printf("Num: %d, Chars: %c %c %c\n", num, c1, c2, c3);
    }

    fclose(file);
    return 0;
}