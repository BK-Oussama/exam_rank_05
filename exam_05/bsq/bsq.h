#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_bsq
{
	int x1;
	int y1;
	int x2;
	int y2;
	int size;
}				t_bsq;

typedef struct s_data
{
	int lines;
	int length;
	char empty;
	char obstacle;
	char fill;
	char **map;
}				t_data;

void free_tab(char **tab);
int free_line(char *line);
char *ft_strdup(char *str);
int ft_atoi(char *str);
int is_digit(char c);
size_t ft_strlen(char *str);
size_t ft_strlen_without_n(char *str);
void bsq(t_data data);
int ft_tablen(char **tab);

#endif