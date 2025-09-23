

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4)
        return 1;

    int width = atoi(argv[1]), height = atoi(argv[2]), iterations = atoi(argv[3]);

    if (width <= 0 || height <= 0 || iterations < 0)
        return 1;

    char board[height][width];
    char new_board[height][width];

    int y;
    int x = 0;
    while (x < height)
    {
        y = 0;
        while (y < width)
        {
            board[x][y] = 0;
            y++;
        }
        x++;
    }

    char c;
    int pen = 0;
    y = 0, x = 0;
    while (read(0, &c, 1))
    {
        if (c == 'w' && x > 0)
            x--;
        else if (c == 's' && x < height - 1)
            x++;
        else if (c == 'a' && y > 0)
            y--;
        else if (c == 'd' && y < width - 1)
            y++;
        else if (c == 'x')
            pen = !pen;

        if (pen)
            board[x][y] = 1;
    }

    int i = 0;
    while (i < iterations)
    {
        x = 0;
        while (x < height)
        {
            y = 0;
            while (y < width)
            {
                int density = 0;
                int xx = -1;
                while (xx <= 1)
                {
                    int yy = -1;
                    while (yy <= 1)
                    {
                        if ((yy || xx) && (xx + x) >= 0 && (xx + x) < height && (yy + y) >= 0 && (yy + y) < width)
                            density = density + board[x + xx][y + yy];
                        yy++;
                    }
                    xx++;
                }

                if (board[x][y] && (density == 2 || density == 3))
                    new_board[x][y] = 1;
                else if (!board[x][y] && density == 3)
                    new_board[x][y] = 1;
                else
                    new_board[x][y] = 0;

                y++;
            }
            x++;
        }

        x = 0;
        while (x < height)
        {
            y = 0;
            while (y < width)
            {
                board[x][y] = new_board[x][y];
                y++;
            }
            x++;
        }
        i++;
    }

    x = 0;
    while (x < height)
    {
        y = 0;
        while (y < width)
        {
            if (board[x][y])
                putchar('0');
            else
                putchar(' ');
            y++;
        }
        putchar('\n');
        x++;
    }

    return 0;
}