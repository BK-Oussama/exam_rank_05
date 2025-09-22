
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    size_t len = 0;
    char *line = NULL;

    // while (1)
        getline(&line, &len, stdin);

    printf("--->%s\n--->%ld\n", line, strlen(line));
}