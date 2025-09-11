
#include <stdio.h>

static int min3(int a, int b, int c)
{
    int m = a;
    if (b < m)
        m = b;
    if (c < m)
        m = c;
    return m;
}

static t_square solve_bsq_dp_2d(const t_map *map)
{
    t_square best;
    best.size = 0;
    best.top = 0;
    best.left = 0;

    if (map == NULL || map->lines == NULL || map->num_lines <= 0 || map->line_length <= 0)
        return best;

    int rows = map->num_lines;
    int cols = map->line_length;

    int dp[rows][cols];

    int i = 0;
    while (i < rows)
    {
        int j = 0;
        while (j < cols)
        {
            if (map->lines[i][j] == map->obstacle)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 || j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
            }

            if (dp[i][j] > best.size)
            {
                best.size = dp[i][j];
                best.top = i - dp[i][j] + 1;
                best.left = j - dp[i][j] + 1;
            }

            j++;
        }
        i++;
    }

    return best;
}
