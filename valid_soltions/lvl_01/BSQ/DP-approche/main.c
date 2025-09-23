typedef struct s_map
{
    char **lines;
    int declared_lines;
    int num_lines;
    int line_length;

    char full;
    char empty;
    char obstacle;

} t_map;

typedef struct s_square
{
    int size;
    int top_x;
    int left_y;
} t_square;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>

void initi_map(t_map *map)
{
    map->lines = 0;

    map->declared_lines = 0;
    map->num_lines = 0;
    map->line_length = 0;

    map->empty = 0;
    map->full = 0;
    map->obstacle = 0;
}

int is_printable(char c)
{
    if (c == '\n' || c < 32)
        return -1;
    else
        return 0;
}

int parse_header(char *line, t_map **map)
{
    int len = strlen(line);

    if (line[len - 1] != '\n' || len < 5)
        return -1;

    (*map)->empty = line[len - 4];
    (*map)->obstacle = line[len - 3];
    (*map)->full = line[len - 2];

    if (is_printable((*map)->empty) != 0 || is_printable((*map)->obstacle) != 0 || is_printable((*map)->full) != 0)
        return -1;

    if ((*map)->empty == (*map)->obstacle || (*map)->empty == (*map)->full || (*map)->full == (*map)->obstacle)
        return -1;

    line[len - 4] = '\0'; // null terminate on the last char.

    long num = 0;
    int i = 0;
    while (line[i])
    {
        char c = line[i];
        if (c < '0' || c > '9')
            return -1;
        num = num * 10 + (c - '0');
        if (num > INT_MAX)
            return -1;
        i++;
    }

    if (num <= 0)
        return -1;

    (*map)->declared_lines = num;

    return 0; // success
}

int parse_map_lines(t_map **map)
{
    int i = 0;
    int j = 0;

    while ((*map)->lines[0][j])
        j++;

    (*map)->line_length = j;

    while (i < (*map)->declared_lines)
    {
        j = 0;
        while ((*map)->lines[i][j])
        {
            if ((*map)->lines[i][j] != (*map)->empty && (*map)->lines[i][j] != (*map)->obstacle)
                return -1;
            j++;
        }
        if (j != (*map)->line_length)
            return -1;
        i++;
    }
    return 0;
}

int process_file(char *filename, t_map **map)
{
    FILE *file;

    if (filename == 0)
        file = stdin;
    else
    {
        file = fopen(filename, "r");
        if (!file)
            return -1;
    }

    size_t len = 0;
    char *line = NULL;
    getline(&line, &len, file);

    if (parse_header(line, map) != 0) // error
    {
        free(line);
        return -1;
    }

    // starting reading the file but alocat one batch double array;
    (*map)->lines = calloc((*map)->declared_lines, sizeof *(*map)->lines);
    if (!(*map)->lines)
        return -1;

    int i = 0;
    int n_read;
    while ((n_read = getline(&line, &len, file)) != -1)
    {
        if (line[n_read - 1] == '\n')
            line[--n_read] = '\0';
        else
            return -1;
        (*map)->lines[i] = strdup(line);
        i++;
    }
    if (i != (*map)->declared_lines)
        return -1;

    if (parse_map_lines(map) != 0)
        return -1;

    return 0;
}

void print_map(t_map *map)
{
    int i = 0;

    char **str = map->lines;

    while (i < map->declared_lines)
    {
        printf("%s\n", str[i]);
        i++;
    }
}

int min3(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

t_square solve_bsq_dp(t_map *map)
{
    t_square best;
    best.left_y = 0, best.top_x = 0, best.size = 0;

    int height = map->declared_lines;
    int width = map->line_length;

    int dp[height][width];

    int i = 0;
    while (i < height)
    {
        int j = 0;
        while (j < width)
        {
            if (map->lines[i][j] == map->obstacle)
                dp[i][j] = 0;
            else if (i == 0 || j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);

            if (dp[i][j] > best.size)
            {
                best.size = dp[i][j];
                best.top_x = i - dp[i][j] + 1;
                best.left_y = j - dp[i][j] + 1;
            }
            j++;
        }
        i++;
    }
    return best;
}

void apply_square(t_map *map, t_square sq)
{
    if (sq.size <= 0)
        return;

    int x = 0;
    while (x < sq.size)
    {
        int y = 0;
        while (y < sq.size)
        {
            int xx = sq.top_x + x;
            int yy = sq.left_y + y;
            map->lines[xx][yy] = map->full;

            y++;
        }
        x++;
    }
}

int main(int argc, char **argv)
{

    if (argc == 2)
    {
        t_map *map = malloc(sizeof(t_map));
        if (!map)
            return -1;
        initi_map(map);
        if (process_file(argv[1], &map) == 0)
        {
            t_square best = solve_bsq_dp(map);
            apply_square(map, best);
            print_map(map);
        }
        else
            fprintf(stderr, "map error\n");
    }

    return 0;
}
