#include <stdio.h>
#include <stdlib.h>

typedef struct s_map
{
    char **lines;
    int num_lines;          // Actual lines read
    int declared_lines;     // Lines declared in first line
    char empty;
    char obstacle;
    char full;
} t_map;

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
    while (i < map->num_lines)
    {
        printf("%s", str[i]);
        i++;
    }
}

// Validate that the three characters are distinct
int validate_characters(char empty, char obstacle, char full)
{
    if (empty == obstacle || empty == full || obstacle == full)
        return -1;
    return 0;
}

// Validate map structure after reading
int validate_map_structure(t_map *map)
{
    // Check if declared line count matches actual
    if (map->declared_lines != map->num_lines)
        return -1;
    
    // Check if we have at least one line
    if (map->num_lines < 1)
        return -1;
    
    // Get length of first line for comparison
    if (map->num_lines == 0)
        return -1;
    
    size_t first_line_len = 0;
    char *first_line = map->lines[0];
    while (first_line[first_line_len] && first_line[first_line_len] != '\n')
        first_line_len++;
    
    if (first_line_len == 0)
        return -1;
    
    // Check all lines have same length and valid characters
    int i = 0;
    while (i < map->num_lines)
    {
        char *line = map->lines[i];
        size_t line_len = 0;
        int j = 0;
        
        // Count length and validate characters
        while (line[j] && line[j] != '\n')
        {
            if (line[j] != map->empty && line[j] != map->obstacle)
                return -1;  // Invalid character
            line_len++;
            j++;
        }
        
        // Check length consistency
        if (line_len != first_line_len)
            return -1;
        
        i++;
    }
    
    return 0;  // Valid map
}

int process_file(const char *filename, t_map *map)
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
    
    // Parse first line with fscanf
    if (fscanf(file, "%d %c %c %c\n", &map->declared_lines, &map->empty, &map->obstacle, &map->full) != 4)
    {
        if (filename && file != stdin)
            fclose(file);
        fprintf(stderr, "map error\n");
        return -1;
    }
    
    // Validate characters are distinct
    if (validate_characters(map->empty, map->obstacle, map->full) == -1)
    {
        if (filename && file != stdin)
            fclose(file);
        fprintf(stderr, "map error\n");
        return -1;
    }
    
    // Read remaining lines
    size_t len = 0;
    char *line = NULL;
    int line_count = 0;
    
    while (getline(&line, &len, file) != -1)
    {
        char **tmp = realloc(map->lines, (line_count + 1) * sizeof(char *));
        if (!tmp)
        {
            free(line);
            if (filename && file != stdin)
                fclose(file);
            return -1;
        }
        map->lines = tmp;
        map->lines[line_count] = line;
        line = NULL;
        line_count++;
    }
    map->num_lines = line_count;
    free(line);
    if (filename && file != stdin)
        fclose(file);
    
    // Validate complete map structure
    if (validate_map_structure(map) == -1)
    {
        fprintf(stderr, "map error\n");
        return -1;
    }
    
    return 0;
}

void initialize_map(t_map *map)
{
    map->lines = NULL;
    map->num_lines = 0;
    map->declared_lines = 0;
    map->empty = '.';       // Default values, will be overwritten
    map->obstacle = 'o';
    map->full = 'x';
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
        
        if (process_file(NULL, map) == 0)
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
            
            if (process_file(argv[i], map) == 0)
            {
                print_map(map);
                if (i < argc - 1)
                    printf("\n");
            }
            
            ft_free(map);
            free(map);
            i++;
        }
    }
    return 0;
}
