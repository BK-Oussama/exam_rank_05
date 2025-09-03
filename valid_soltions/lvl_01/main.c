
#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    char **lines;
    int num_lines;
    int declared_line;
    char empty;
    char obstacle;
    char full;

} t_map;

void initialize_map(t_map *map)
{
    map->lines = NULL;
    map->num_lines = 0;
    map->empty = '.';
    map->obstacle = 'o';
    map->full = 'x';
}

void cleanup_maps(t_map *maps, int n_maps)
{
    int i = 0;
    while (i < n_maps)
    {
        ft_free(&maps[i]);
        i++;
    }
    free(maps);
}

void ft_free(t_map *map)
{
    int i = 0;
    while (i < map->num_lines)
    {
        free(map->lines[i]);
        i++;
    }
    free(map->lines);
}

void print_map(t_map *map)
{
    int i = 0;

    char **str = map->lines;

    printf("---------> %d\n", map->num_lines);
    while (i < map->num_lines)
    {
        printf("%s", str[i]);
        i++;
    }
}

int process_file(const char *filename, t_map **map)
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
            return 1; // FIXED: Don't exit, just return to continue with other files
        }
    }

    if (fscanf(file, "%d %c %c %c\n", (*map)->declared_line, (*map)->empty, (*map)->obstacle, (*map)->full) != 4)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }

    // validate characters
    if ((*map)->empty == (*map)->obstacle || (*map)->empty == (*map)->full || (*map)->full == (*map)->obstacle)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }

    size_t len = 0;
    char *line = NULL;
    int line_count = 0;

    while (getline(&line, &len, file) != -1)
    {
        char **tmp = realloc((*map)->lines, (line_count + 1) * sizeof(char *));
        if (!tmp)
        {
            free(line);
            ft_free(*map);
            if (filename && file != stdin)
                fclose(file);
            free(*map); // to clean up the struct.
            exit(1);
        }

        (*map)->lines = tmp;
        (*map)->lines[line_count] = line;
        line = NULL;
        line_count++;
    }

    (*map)->num_lines = line_count; // validate map lines
    if ((*map)->num_lines != (*map)->declared_line)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }
 
    free(line);
    if (filename && file != stdin)
        fclose(file);
    return 0;
}

void validate_map_structure(t_map **map)
{
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        t_map *map = malloc(sizeof(t_map));
        if (!map)
        {
            fprintf(stderr, "map error\n");
            return 1;
        }
        initialize_map(map);
        if (process_file(NULL, &map) == 0)
            print_map(map);
        ft_free(map);
        free(map);
    }
    else
    {
        int i = 1;
        while (i < argc)
        {
            t_map *map = malloc(sizeof(t_map));
            if (!map)
            {
                fprintf(stderr, "map error\n");
                return 1;
            }

            initialize_map(map);
            if (process_file(argv[i], &map) == 0)
            {
                validate_map_structure(&map);
                print_map(map);
                if (i < argc - 1) // Print newline between maps
                    printf("\n");
            }

            ft_free(map);
            free(map);
            i++;
        }
    }
    return 0;
}