#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_pen {
	int x;
	int y;
	int is_draw;
} t_pen;

char **new_tab(int width, int height)
{
	char **tab = malloc(sizeof(char *) * height);
	for (int i = 0; i < height; i++)
	{
		tab[i] = calloc(sizeof(char), width);
		for (int j = 0; j < width; j++)
			tab[i][j] = ' ';
	}
	return tab;
}

void print_tab(char **tab, int width, int height)
{
	for(int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			putchar(tab[i][j]);
		}
		putchar('\n');
	}
}

int count_voisins(char **tab, int x, int y, int width, int height)
{
	int count = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i == 0 && j == 0)
				continue;
			
			int new_y = y + i;
			int new_x = x + j;
			if (new_x >= 0 && new_x < width && new_y >= 0 && new_y < height)
				if (tab[new_y][new_x] == 'O')
					count++;
		}
	}
	return count;
}

void free_tab(char **tab, int height)
{
	for (int i = 0; i < height; i++)
		free(tab[i]);
	free(tab);
}

void iter_map(char **tab, int width, int height)
{
	char **n_tab = new_tab(width, height);
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int count = count_voisins(tab, x, y, width, height);
			if (tab[y][x] == 'O')
			{
				if (count == 2 || count == 3)
				{
					n_tab[y][x] = 'O';
				}
			}
			else
			{
				if (count == 3)
					n_tab[y][x] = 'O';
			}
		}
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			tab[i][j] = n_tab[i][j];
		}
	}
	free_tab(n_tab, height);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;

	int width = atoi(av[1]);
	int height = atoi(av[2]);
	int iter = atoi(av[3]);
	char **tab = new_tab(width, height);
	t_pen pen = {0,0,0};
	char command;

	while (read(0, &command, 1) > 0)
	{
		if (pen.is_draw)
			tab[pen.y][pen.x] = 'O';

		switch(command)
		{
			case 'w':
				if (pen.y > 0)
					pen.y--;
				break;
			case 's':
				if (pen.y < height - 1)
					pen.y++;
				break;
			case 'a':
				if (pen.x > 0)
					pen.x--;
				break;
			case 'd':
				if (pen.x < width - 1)
					pen.x++;
				break;
			case 'x':
				pen.is_draw = !pen.is_draw;
				break;
		}
	}
	print_tab(tab, width, height);
	for (int it = 0; it < iter; it++)
		iter_map(tab, width, height);
	print_tab(tab, width, height);
	free_tab(tab, height);
	return 0;
}