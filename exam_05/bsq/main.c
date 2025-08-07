#include "bsq.h"

static int set_characters(char *line, t_data *data)
{
	int i;

	i = 0;
	if (!i && !is_digit(line[i]))
		return (0);
	data->lines = ft_atoi(line);
	if (data->lines <= 0)
		return (0);
	while (line[i] && is_digit(line[i]))
		i++;
	i++;
	if (ft_strlen(&line[i]) != 6)
		return (0);
	data->empty = line[i];
	data->obstacle = line[i + 2];
	data->fill = line[i + 4];
	if (data->empty == data->fill || data->fill == data->obstacle || data->empty == data->obstacle)
		return (0);
	return (1);
}

static int fill_data(FILE *file, t_data *data)
{
	size_t line_length = 0;
	int i = 0;
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0;

	data->map = NULL;
	data->lines = 0;
	data->empty = 0;
	while (bytes_read != -1)
	{
		bytes_read = getline(&line, &len, file);
		if (bytes_read <= 0)
			break;
		if (!data->empty)
		{
			if (!set_characters(line, data))
				return (free_line(line));
			data->map = calloc(data->lines + 1, sizeof(char *));
			if (!data->map)
				return (free_line(line));
			continue;
		}
		else
		{
			if (i >= data->lines && ft_strlen(line) != 1 && line[0] != '\n')
				return (free_line(line));
			else if (i == data->lines && ft_strlen(line) == 1 && line[0] == '\n')
				continue;
			data->map[i] = ft_strdup(line);
			if (!data->map[i])
				return (free_line(line));
			if (i == 0)
			{
				line_length = ft_strlen_without_n(data->map[i]);
				data->length = line_length;
			}
			else if (line_length != ft_strlen_without_n(data->map[i]))
				return (free_line(line));
			i++;
		}
	}
	if (line)
		free(line);
	if (ft_tablen(data->map) != data->lines)
		return (0);
	return (1);
}

int main(int ac, char *av[])
{
	int	i;
	t_data data;

	i = 0;
	while (i < ac)
	{
		if (ac == 1)
		{
			if (!fill_data(stdin, &data))
			{
				fprintf(stderr, "map error\n");
				return (1);
			}
			bsq(data);
			if (data.map)
				free_tab(data.map);
			break;
		}
		else
		{
			if (!i)
				i++;
			FILE *file = fopen(av[i], "r");
			if (!file)
			{
				fprintf(stderr, "map error\n");
				i++;
				continue;
			}
			if (!fill_data(file, &data))
			{
				if (data.map)
					free_tab(data.map);
				fprintf(stderr, "map error\n");
				fclose(file);
				i++;
				continue;
			}
			bsq(data);
			if (data.map)
				free_tab(data.map);
			fclose(file);
			i++;
			if (i < ac)
				fprintf(stdout, "\n");
		}
	}
}
