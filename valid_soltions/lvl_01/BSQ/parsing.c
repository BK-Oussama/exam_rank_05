#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define INITIAL_CAPACITY 16

typedef struct
{
    char **lines;
    size_t count;
    size_t capacity;
} file_content_t;

file_content_t *init_file_content(void)
{
    file_content_t *content = malloc(sizeof(file_content_t));
    if (!content)
        return NULL;

    content->lines = malloc(INITIAL_CAPACITY * sizeof(char *));
    if (!content->lines)
    {
        free(content);
        return NULL;
    }

    content->count = 0;
    content->capacity = INITIAL_CAPACITY;
    return content;
}

// Grow the lines array when needed
int grow_lines_array(file_content_t *content)
{
    size_t new_capacity = content->capacity * 2;
    char **new_lines = realloc(content->lines, new_capacity * sizeof(char *));
    if (!new_lines)
        return -1;

    content->lines = new_lines;
    content->capacity = new_capacity;
    return 0;
}

file_content_t *read_file_content(FILE *file)
{
    file_content_t *content = init_file_content();
    if (!content)
        return NULL;

    char *line = NULL;
    size_t len = 0;
    int read;

    while ((read = getline(&line, &len, file)) != -1)
    {
        // Grow array if needed
        if (content->count >= content->capacity)
        {
            if (grow_lines_array(content) == -1)
            {
                free(line);
                free_file_content(content);
                return NULL;
            }
        }

        // Store the line (getline allocates memory for us)
        content->lines[content->count] = line;
        content->count++;

        // Reset for next getline call
        line = NULL;
        len = 0;
    }

    // Clean up the last allocated line if getline failed
    if (line)
        free(line);

    return content;
}

// Free all memory associated with file content
void free_file_content(file_content_t *content)
{
    if (!content)
        return;

    // Free each line
    for (size_t i = 0; i < content->count; i++)
    {
        free(content->lines[i]);
    }

    // Free the lines array and structure
    free(content->lines);
    free(content);
}


typedef struct
{
    char **lines;
    size_t count;
    size_t capacity;
} file_content_t;

int process_file(const char *filename)
{
    FILE *file;

    if (!filename)
        file = stdin;
    else
    {
        file = fopen(filename, "r");
        if (!file)
        {
            fprintf(stderr, "map error\n");
            return -1;
        }
    }

    file_content_t *content = read_file_content(file);

    if (filename && file != stdin)
        fclose(file);

    if (!content)
    {
        fprintf(stderr, "map error\n");
        return -1;
    }

    // TODO: Steps 2-4 will process the content here
    printf("Successfully read %zu lines\n", content->count);

    free_file_content(content);
    return 0;
}


int main(int argc, char **argv)
{
    if (argc == 1)
        return process_file(NULL);
    else
    {
        for (int i = 1; i < argc; i++)
        {
            process_file(argv[i]);

            if (i < argc - 1)
                printf("\n"); // Line break between multiple files
        }
    }

    return 0;
}