/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hime <mel-hime@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:22:46 by mel-hime          #+#    #+#             */
/*   Updated: 2025/08/27 19:29:18 by mel-hime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
 
typedef struct  s_map_info
{
    int rows;
    char empty;
    char obstacle;
    char full;
    int cols;
    char **map;
}               t_map_info;


int min3(int a, int b, int c)
{
    int min = a;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

void    find_biggest_square(t_map_info *info, int *best_i, int *best_j, int *sq_size)
{
    int cols = info->cols;
    int rows = info->rows;

    int **dp = calloc(rows, sizeof(int *));
    for (int i = 0; i < rows; i++)
        dp[i] = calloc(cols, sizeof(int));
    
    for (int i = 0; i < rows; i++)
    {
        if (info->map[i][0] == info->empty)
            dp[i][0] = 1;
    }
    for (int i = 0; i < cols; i++)
    {
        if (info->map[0][i] == info->empty)
            dp[0][i] = 1;
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (info->map[i][j] == info->empty)
            {
                dp[i][j] = 1 + min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                if (dp[i][j] > *sq_size)
                {
                    *sq_size = dp[i][j];
                    *best_i = i;
                    *best_j = j;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++)
        free(dp[i]);
    free(dp);
}

void    fill_square(t_map_info *info, int best_i, int best_j, int sq_size)
{
    for (int i = best_i - sq_size + 1; i <= best_i; i++)
    {
        for (int j = best_j - sq_size + 1; j <= best_j; j++)
        {
            info->map[i][j] = info->full;
        }
    }
}

void    print_map(t_map_info *info)
{
    for (int i = 0; i < info->rows; i++)
    {
        fputs(info->map[i], stdout);
        fputs("\n", stdout);
    }
}

size_t ft_strlen(char *str)
{
    size_t i = 0;
    while (str[++i]);
    return i;
}

int ft_atoi(char *num)
{
    int i = 0;
    int sign = 1;
    int final_num = 0;

    while((num[i] >= 9 && num[i] <= 13) || num[i] == 32)
        i++;
    if (num[i] == '-' || num[i] == '+')
    {
        if (num[i] == '-')
            sign = -1;
        i++;
    }
    while(num[i] >= '0' && num[i] <= '9')
    {
        final_num = final_num * 10 + (num[i] - '0');
        i++;
    }
    return final_num * sign;
}


char *ft_strdup(char *str)
{
    size_t str_len = 0;
    char *new_str = NULL;
    int i = 0;

    str_len = ft_strlen(str);
    new_str = calloc(str_len + 1, sizeof(char));
    if (!new_str)
        return (NULL);
    while(str[i])
    {
        new_str[i] = str[i];
        i++;
    }
    return (new_str);
}


void    free_map(t_map_info *info)
{
    if (!info->map)
        return;
    for (int i = 0; i < info->rows; i++)
    {
        if (info->map[i])
            free(info->map[i]);
    }
    free(info->map);
    info->map = NULL;
}



int valid_map(t_map_info *info)
{
    for (int i = 0; i < info->rows; i++)
    {
        for (int j = 0; j < info->cols; j++)
        {
            char c = info->map[i][j];
            if (c != info->empty && c != info->obstacle)
                return 0;
        }
    }
    return 1;
}



int read_map_lines(FILE *file, t_map_info *info)
{
    char *line = NULL;
    size_t line_len = 0;
    ssize_t read;
    int count = 0;

    info->map = calloc(info->rows, sizeof(char *));
    if (!info->map)
        return 0;
    while ((read = getline(&line, &line_len, file)) != -1)
    {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        }

        if (count == 0)
            info->cols = read; // Save expected width
        else if (read != info->cols) {
            free(line);
            return 0; // Inconsistent line length
        }

        info->map[count] = ft_strdup(line);
        if (!info->map[count]) {
            free(line);
            return 0;
        }
        count++;
    }
    free(line);
    return count == info->rows;
}


int parse_header(char *line, t_map_info *info)
{
    size_t len = ft_strlen(line);
    if (len < 4)
        return (0);
    info->full = line[len - 1];
    info->obstacle = line[len - 2];
    info->empty = line[len - 3];
    line[len - 3] = '\0';

    if (info->full == info->empty || info->full == info->obstacle || info->empty == info->obstacle)
        return 0;
    info->rows = ft_atoi(line);
    return info->rows > 0;
}

void    process_map(FILE *file)
{
    t_map_info map_info = {0};
    char *line = NULL;
    size_t line_len = 0;
    ssize_t read;

    // read the first line of the map and parse it 
    read = getline(&line, &line_len, file);
    if (read == -1)
    {
        fprintf(stderr, "map error\n");
        free(line);
        return;
    }

    if (line[read - 1] == '\n')
        line[--read] = '\0';

    if (!parse_header(line, &map_info))
    {
        fprintf(stderr, "map error\n");
        free(line);
        return;
    }
    free(line);


    // read all the lines of the map and parse them 
    if (!read_map_lines(file, &map_info) || !valid_map(&map_info))
    {
        fprintf(stderr, "map error\n");
        free_map(&map_info);
        return;
    }
    // solve the bsq
    int best_i = 0;
    int best_j = 0;
    int sq_size = 0;
    find_biggest_square(&map_info, &best_i, &best_j, &sq_size);
    fill_square(&map_info, best_i, best_j, sq_size);
    // print the map with the solved bsq
    print_map(&map_info);
}

int main(int ac, char **av)
{
    if (ac == 1)
        process_map(stdin);
    else
    {
        for (int i = 1; i < ac; i++)
        {
            FILE *file = fopen(av[i], "r");
            if (!file)
            {
                fprintf(stderr, "map error\n");
                continue;
            }
            process_map(file);
            fclose(file);
            if (i < ac - 1)
                fprintf(stdout, "\n");
        }
    }
    return 0;
}