#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_bsq
{
	int lines;
	char empt;
	char obs;
	char full;
	int width;
	char **map;
} t_bsq;

#define ERROR "map error \n"

int ft_strlen(char *str)
{	
	int i = 0;

	for (; str[i]; i++)
		;
	return i;
}

void free_map(t_bsq *bsq, int i)
{
	for (int j = 0; j < i ; j++)
		free(bsq->map[j]);
	free(bsq->map);
}

int  min3(int a, int b, int c){
	if (a < b && a < c)
		return a;
	if (b < c)
		return b;
	return c;
}

void solve_bsq(t_bsq *bsq){
	int dp[bsq->lines][bsq->width];
	int max = 0, b_i = 0, b_j =0;
	for (int i = 0; i < bsq->lines; i++)
	{
		for (int j = 0; j < bsq->width; j++)
		{
			if (bsq->map[i][j] == bsq->obs)
				dp[i][j] = 0;
			else if (i == 0 || j == 0)
				dp[i][j] = 1;
			else
				dp[i][j] = min3(dp[i - 1][j], 
					dp[i][j - 1], dp[i - 1][j - 1]) + 1;
			if (dp[i][j] > max)
			{
				max = dp[i][j];
				b_i = i;
				b_j = j;
			}
		}
	}

	int st_i = b_i - max + 1;
	int st_j = b_j - max + 1;
	int f_i = st_i + max;
	int f_j = st_j + max;

	for (int i = st_i; i < f_i; i++)
		for (int j = st_j; j < f_j; j++)
			bsq->map[i][j] = bsq->full;
}

void check_map(t_bsq *bsq)
{
	for (int i = 0; i < bsq->lines ; i++)
		for (int j = 0; j < bsq->width ; j++)
			if (bsq->map[i][j] != bsq->empt && bsq->map[i][j] != bsq->obs)
				free_map(bsq, bsq->lines), fputs(ERROR, stdout), exit(1);
}

void close_on_error(t_bsq *bsq, char *av, FILE *file, int i){
	if (av)
		fclose(file);
	fputs(ERROR, stdout);
	if (i >= 0)
		free_map(bsq, i);
	exit (1);
}

void parse_bsq(t_bsq *bsq, char *av)
{
	FILE *file;

	if (av)
		file = fopen(av, "r");
	else
		file = stdin;

	if (!file)
		fputs(ERROR, stdout), exit(1);
	
	if (fscanf(file, "%d%c%c%c\n", &bsq->lines, &bsq->empt, 
	&bsq->obs, &bsq->full) != 4)
		close_on_error(bsq, av, file, -1);
	
	if (bsq->lines <= 0)
		close_on_error(bsq, av, file, -1);
	
	if (bsq->empt == bsq->full || bsq->empt == bsq->obs || bsq->obs == bsq->full)
		close_on_error(bsq, av, file, -1);
	
	bsq->map = malloc(sizeof(char *) * bsq->lines);

	for (int i = 0; i < bsq->lines ; i++)
	{
		char *new = NULL;
		size_t len = 0;
		int new_len;

		if (getline(&new, &len, file) == -1)
			close_on_error(bsq, av, file, i);
		
		new_len = ft_strlen(new);

		if (new_len > 0 && new[new_len - 1] == '\n') 
			new[new_len - 1] = '\0';
		else if (i < bsq->lines - 1 && new[new_len - 1] != '\n')
			close_on_error(bsq, av, file, i);
		
		new_len = ft_strlen(new);

		if (i == 0)
			bsq->width = new_len ;
		if (i != 0 && i < bsq->lines - 1 && bsq->width != new_len)
			close_on_error(bsq, av, file, i);
		
		bsq->map[i] = new;
	}
	fclose(file);
	check_map(bsq);
}

void print_bsq(t_bsq * bsq)
{
	for (int i = 0; i < bsq->lines ; i++)
		printf("%s\n",bsq->map[i]);
}

int main(int ac, char ** av)
{
	t_bsq bsq;
	if (ac == 1)
		parse_bsq(&bsq, NULL);
	else if(ac == 2)
		parse_bsq(&bsq, av[1]);
	else
		return (printf("error: wrong number of args"), 1);
	solve_bsq(&bsq);
	print_bsq(&bsq);
	free_map(&bsq, bsq.lines);
}