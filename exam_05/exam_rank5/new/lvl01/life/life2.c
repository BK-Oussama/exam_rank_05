#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac != 4 )
		return 1;

	int width = atoi(av[1]), height = atoi(av[1]), iter = atoi(av[3]);
	char board[height][width];

	for (int i = 0; i < height ; i++)
		for (int j = 0; j < height ; j++)
			board[i][j] = 0;
	
	char c;
	int pen =0 , x = 0 , y = 0;
	while(read(0, &c, 1))
	{
		if (c == 'w' && y > 0)
			y--;
		else if (c == 's' && y < height - 1)
			y++;
		else if (c == 'a' && x > 0)
			x--;
		else if (c == 'd' && x < width - 1)
			x++;
		else if (c == 'x' && pen)
			pen = 0;
		else if (c == 'x' && !pen)
			pen = 1;
		if (pen)
			board[y][x] = 1;
	}

	int n = 0;
	char new_b[height][width];
	for (int it = 0; it < iter; it++)
	{
		for (y = 0; y < height; y++)
		{
			for (x = 0; x < width; x++)
			{
				n = 0;
				for (int yy = -1; yy <= 1; yy++)
					for (int xx = -1; xx <= 1; xx++)
						if ((xx || yy) 
						&& x + xx >= 0 && x + xx < width 
						&& y + yy >= 0 && y + yy < height)
							n += board[y + yy][x + xx];
				if (board[y][x] && (n == 2 || n == 3))
					new_b[y][x] = 1;
				else if (!board[y][x] && n == 3)
					new_b[y][x] = 1;
				else
					new_b[y][x] = 0;
			}
		}
		for (int i = 0; i < height ; i++)
			for (int j = 0; j < width ; j++)
				board[i][j] = new_b[i][j];
	}

	for (int i = 0; i < height ; i++){
		for (int j = 0; j < width ; j++)
			putchar(board[i][j] ? '0' : ' ');
		putchar('\n');
	}
}