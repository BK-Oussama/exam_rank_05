#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Y 100
#define MAX_X 200

enum cell_state
{
	EMPTY = 0,
	OBSTACLE = 1,
	FULL = 2
};

typedef struct
{
	int x, y, size;
} t_bsq;

typedef struct
{
	int x, y;
	t_bsq bsq;
	char empty, obstacle, full;
	int map[MAX_Y][MAX_X];
} t_data;

int min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	return c;
}

int read_map(FILE *file, t_data *data)
{
	if (fscanf(file, "%d %c %c %c\n", &data->y, &data->empty, &data->obstacle, &data->full) != 4 || data->y < 1)
		return 0;
	if (data->empty == data->obstacle || data->empty == data->full || data->obstacle == data->full)
		return 0;

	char *line = NULL;
	size_t len = 0;
	int y = 0, x = 0;

	while (y < data->y && getline(&line, &len, file) != -1)
	{
		int read_len = strlen(line);
		if (line[read_len - 1] == '\n')
			line[--read_len] = '\0';
		if (read_len == 0 || read_len > MAX_X)
		{
			free(line);
			return 0;
		}

		if (y == 0)
			data->x = read_len;
		else if (read_len != data->x)
		{
			free(line);
			return 0;
		}

		for (x = 0; x < data->x; x++)
		{
			if (line[x] == data->empty)
				data->map[y][x] = EMPTY;
			else if (line[x] == data->obstacle)
				data->map[y][x] = OBSTACLE;
			else
			{
				free(line);
				return 0;
			}
		}
		y++;
	}
	free(line);
	if (y != data->y)
		return 0;
	return 1;
}

void find_bsq(t_data *data)
{
	int dp[MAX_Y][MAX_X] = {0};

	for (int y = 0; y < data->y; y++)
	{
		for (int x = 0; x < data->x; x++)
		{
			if (data->map[y][x] == OBSTACLE)
				dp[y][x] = 0;
			else if (x == 0 || y == 0)
				dp[y][x] = 1;
			else
				dp[y][x] = 1 + min3(
								   dp[y - 1][x],
								   dp[y][x - 1],
								   dp[y - 1][x - 1]);
			if (dp[y][x] > data->bsq.size)
			{
				data->bsq.size = dp[y][x];
				data->bsq.x = x - dp[y][x] + 1;
				data->bsq.y = y - dp[y][x] + 1;
			}
		}
	}
	for (int j = 0; j < data->bsq.size; j++)
		for (int i = 0; i < data->bsq.size; i++)
			data->map[data->bsq.y + j][data->bsq.x + i] = FULL;
}

void print_map(t_data *data)
{
	for (int y = 0; y < data->y; y++)
	{
		for (int x = 0; x < data->x; x++)
		{
			if (data->map[y][x] == EMPTY)
				fputc(data->empty, stdout);
			else if (data->map[y][x] == OBSTACLE)
				fputc(data->obstacle, stdout);
			else
				fputc(data->full, stdout);
		}
		fputc('\n', stdout);
	}
}

void process_map(FILE *file)
{
	t_data data = {0};
	if (!read_map(file, &data))
	{
		fprintf(stderr, "map error\n");
		return;
	}
	find_bsq(&data);
	print_map(&data);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		process_map(stdin);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			FILE *file = fopen(argv[i], "r");
			if (!file)
			{
				fprintf(stderr, "map error\n");
				continue;
			}
			process_map(file);
			fclose(file);
			if (i != argc - 1)
				fputc('\n', stdout);
		}
	}
	return 0;
}
