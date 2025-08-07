#include "bsq.h"

size_t ft_strlen_without_n(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

size_t ft_strlen(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int ft_atoi(char *str)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (str[i] && is_digit(str[i]))
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res);
}

char *ft_strdup(char *str)
{
	int i;
	char *new;

	if (!str)
		return (NULL);
	i = 0;
	new = calloc(ft_strlen(str) + 1, 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			break;
		new[i] = str[i];
		i++;
	}
	return (new);
}

void free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int ft_tablen(char **tab)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (!tab || !tab[0])
		return (-1);
	while (tab[i])
	{
		if ((ft_strlen(tab[i]) == 1 && tab[i][0] == '\n')  || ft_strlen(tab[i]) == 0)
		{
			i++;
			continue;
		}
		res++;
		i++;
	}
	return (res);
}

int free_line(char *line)
{
	if (line)
		free(line);
	return (0);
}
