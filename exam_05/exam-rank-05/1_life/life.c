#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SETUP 1024

typedef struct {
	int *map1;
	int *map2;
	int iterations;
	int width;
	int height;
	char *setup;
} Life;

void init_map(Life *life) {
	int i = 0;
	int x = 0;
	int y = 0;
	int draw = 0;

	while (life->setup[i]) {
		switch (life->setup[i]) {
			case 'w': y--; break;
			case 's': y++; break;
			case 'a': x--; break;
			case 'd': x++; break;
			case 'x': draw = !draw; break;
			default: break;
		}
		if (draw && x >= 0 && x < life->width && y >= 0 && y < life->height)
			life->map1[y * life->width + x] = 1;
		i++;
	}
}

void init_life(Life *life, char *setup, char **argv) {
	life->width = atoi(argv[1]);
	life->height = atoi(argv[2]);
	life->iterations = atoi(argv[3]);
	if (life->width <= 0 || life->height <= 0 || life->iterations < 0)
		exit(1);
	life->setup = setup;
	life->map1 = calloc(life->width * life->height, sizeof(int));
	life->map2 = calloc(life->width * life->height, sizeof(int));
	init_map(life);
}

void free_life(Life *life) {
	free(life->map1);
	free(life->map2);
	free(life);
}

void print_map(Life *life) {
	for (int y = 0; y < life->height; y++) {
		for (int x = 0; x < life->width; x++) {
			int cell = life->map1[y * life->width + x];
			putchar(cell ? '0' : ' ');
		}
		putchar('\n');
	}
}

void check_boundaries_count(Life *life, int x, int y, int *count) {
	if (x >= 0 && x < life->width && y >= 0 && y < life->height)
		if (life->map1[y * life->width + x])
			(*count)++;
}

int count_neighbors(Life *life, int x, int y) {
	int count = 0;
	for (int ny = y - 1; ny <= y + 1; ny++)
		for (int nx = x - 1; nx <= x + 1; nx++)
			if (!(ny == y && nx == x))
				check_boundaries_count(life, nx, ny, &count);
	return count;
}

void grow_life(Life *life) {
	for (int i = 0; i < life->iterations; i++) {
		for (int y = 0; y < life->height; y++) {
			for (int x = 0; x < life->width; x++) {
				int neighbors = count_neighbors(life, x, y);
				int alive = life->map1[y * life->width + x];
				life->map2[y * life->width + x] =
					(alive && (neighbors == 2 || neighbors == 3)) ||
					(!alive && neighbors == 3);
			}
		}
		int *temp = life->map1;
		life->map1 = life->map2;
		life->map2 = temp;
	}
}

int main(int argc, char **argv) {
	if (argc != 4)
		return 1;

	char setup[MAX_SETUP];
	int b_s = read(0, setup, MAX_SETUP - 1);
	if (b_s <= 0) return 1;
	setup[b_s] = '\0';

	Life *life = calloc(1, sizeof(Life));
	init_life(life, setup, argv);
	grow_life(life);
	print_map(life);
	free_life(life);
	return 0;
}
