
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_map
{
    char **lines;
    int num_lines;
    int declared_line;
    int line_length;
    char empty;
    char obstacle;
    char full;

} t_map;

typedef struct s_square
{
    int size;
    int top;
    int left;
} t_square;


static int min_int(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

static int is_square_empty(const t_map *m, int top, int left, int size)
{
    int i = 0;
    while (i < size)
    {
        int r = top + i;
        int j = 0;
        while (j < size)
        {
            int c = left + j;
            if (m->lines[r][c] != m->empty)
                return 0;
            j++;
        }
        i++;
    }
    return 1;
}


static t_square solve_bsq_naive(const t_map *map)
{
    t_square best;
    best.size = 0;
    best.left = 0;
    best.top = 0;

    int rows = map->num_lines;
    int cols = map->line_length;

    int max_size = min_int(rows, cols);

    while (max_size >= 1)
    {
        int top = 0;
        while (top <= rows - max_size)
        {
            int left = 0;
            while (left <= cols - max_size)
            {
                if (is_square_empty(map, top, left, max_size) == 1)
                {
                    best.top = top;
                    best.left = left;
                    best.size = max_size;
                    return best;
                }
                left++;
            }
            top++;
        }
        max_size--;
    }
    return best;
}


static void apply_square(t_map *map, t_square sq)
{

    if (sq.size <= 0)
        return;

    int r = 0;
    while (r < sq.size)
    {
        int c = 0;
        while (c < sq.size)
        {
            int rr = sq.top + r;
            int cc = sq.left + c;

            map->lines[rr][cc] = map->full;

            c++;
        }
        r++;
    }
}

void initialize_map(t_map *map)
{
    map->lines = NULL;
    map->num_lines = 0;
    map->declared_line = 0;
    map->line_length = 0;
    map->empty = '.';
    map->obstacle = 'o';
    map->full = 'x';
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

// for debug!
void print_map_details(t_map *map)
{
    printf("Number of lines: %d\n", map->num_lines);
    printf("Declared lines: %d\n", map->declared_line);
    printf("Line length: %d\n", map->line_length);
    printf("Empty char: %c\n", map->empty);
    printf("Obstacle char: %c\n", map->obstacle);
    printf("Full char: %c\n", map->full);
    printf("Map contents:\n");

    for (int i = 0; i < map->num_lines; i++)
        printf("%s", map->lines[i]);
}

int validate_map_structure(const t_map *map)
{

    if (map->declared_line < 1)
        return 1;

    int i = 0;
    while (i < map->num_lines)
    {
        int j = 0;
        while (map->lines[i][j] && map->lines[i][j] != '\n')
        {
            if (map->lines[i][j] != map->empty && map->lines[i][j] != map->obstacle)
                return 1;
            j++;
        }
        if (j != map->line_length)
            return 1;
        i++;
    }
    return 0;
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
            return 1;
        }
    }

    if (fscanf(file, "%d %c %c %c ", &(*map)->declared_line, &(*map)->empty, &(*map)->obstacle, &(*map)->full) != 4)
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
            free(*map);
            exit(1);
        }

        (*map)->lines = tmp;
        (*map)->lines[line_count] = line;
        line = NULL;
        line_count++;
    }

    free(line);
    if (filename && file != stdin)
        fclose(file);

    (*map)->num_lines = line_count; // validate map lines
    if ((*map)->num_lines != (*map)->declared_line)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }

    // store first map line -> compare it later with all other lines
    int first_line_len = 0;
    while ((*map)->lines[0][first_line_len] && (*map)->lines[0][first_line_len] != '\n')
        first_line_len++;

    (*map)->line_length = first_line_len;
    if (first_line_len < 1)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }

    // check map characters ! only empty and obstacle characters are allowed inside the map.
    if (validate_map_structure(*map) != 0)
    {
        fprintf(stderr, "map error\n");
        return 1;
    }

    return 0;
}


// parsing not valid, NAIVE Approch valid
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
        {
            t_square ans = solve_bsq_naive(map);
            apply_square(map, ans);
            print_map(map);
        }

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
                t_square ans = solve_bsq_naive(map);
                apply_square(map, ans);
                print_map(map);
            }

            ft_free(map);
            free(map);
            i++;
        }
    }
    return 0;
}


