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
    {
        return a;
    }
    else
    {
        return b;
    }
}






// Returns 1 if every cell in the s×s block is empty; otherwise 0.
// Precondition: 0 <= top <= N - s, 0 <= left <= M - s, s >= 1.
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



// Naive search:
// - Start from largest possible size = min(N, M).
// - For each size s, scan top in [0..N-s], left in [0..M-s] (row-major).
// - Return the first valid square (tie-break satisfied).
t_square solve_bsq_naive(const t_map *map)
{
    t_square best;
    best.size = 0;
    best.top = 0;
    best.left = 0;

    if (map == NULL || map->lines == NULL || map->num_lines <= 0 || map->line_length <= 0)
        return best;





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
                    best.size = max_size;
                    best.top = top;
                    best.left = left;
                    return best; // first found at this size => correct tie-break
                }
                left++;
            }
            top++;
        }
        max_size--;
    }

    // If we reach here, no empty cells were found (all obstacles).
    // best.size stays 0; top/left can be 0.
    return best;
}





// Apply the square by writing m->full in-place.
// If size == 0, this is a no-op.
void apply_square(t_map *m, t_square sq)
{
    if (m == NULL || sq.size <= 0)
        return;

    int r = 0;
    while (r < sq.size)
    {
        int c = 0;
        while (c < sq.size)
        {
            int rr = sq.top + r;
            int cc = sq.left + c;
            m->lines[rr][cc] = m->full;
            c++;
        }
        r++;
    }
}