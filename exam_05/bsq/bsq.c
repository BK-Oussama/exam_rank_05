#include "bsq.h"

static void free_int_tab(int **tab, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

static int **hollow_copy(t_data data)
{
	int **new;
	int i;

	new = calloc(data.lines, sizeof(int *));
	if (!new)
		return (NULL);
	i = 0;
	while (i < data.lines)
	{
		new[i] = calloc(data.length, sizeof(int));
		if (!new[i])
		{
			free_int_tab(new, data.lines);
			return (NULL);
		}
		i++;
	}
	return (new);
}

static int select_min(int a, int b, int c)
{
	int tmp;

	tmp = a;
	if (tmp > b)
		tmp = b;
	if (tmp > c)
		tmp = c;
	return (tmp);
}

static void print_square(t_bsq values, t_data data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data.lines)
	{
		y = 0;
		while (y < data.length)
		{
			if (y >= values.x1 && y <= values.x2 && x >= values.y1 && x <= values.y2)
				fprintf(stdout, "%c", data.fill);
			else
				fprintf(stdout, "%c", data.map[x][y]);
			y++;
		}
		fprintf(stdout, "\n");
		x++;
	}
}

void bsq(t_data data)
{
	int **copy;
	int x;
	int y;
	t_bsq values;

	copy = hollow_copy(data);
	if (!copy)
		return;
	x = 0;
	values.size = 0;
	while (x < data.length)
	{
		y = 0;
		while (y < data.lines)
		{
			if (x == 0 && data.map[y][x] == data.obstacle)
				copy[y][x] = 0;
			else if (x == 0)
				copy[y][x] = 1;
			else if (y == 0 && data.map[y][x] == data.obstacle)
				copy[y][x] = 0;
			else if (y == 0)
				copy[y][x] = 1;
			else if (data.map[y][x] == data.obstacle)
				copy[y][x] = 0;
			else
				copy[y][x] = select_min(copy[y - 1][x], copy[y - 1][x - 1], copy[y][x - 1]) + 1;
			if (copy[y][x] > values.size)
			{
				values.x2 = x;
				values.y2 = y;
				values.size = copy[y][x];
			}
			y++;
		}
		x++;
	}
	values.x1 = values.x2 - values.size + 1;
	values.y1 = values.y2 - values.size + 1;
	print_square(values, data);
	free_int_tab(copy, data.lines);
}
