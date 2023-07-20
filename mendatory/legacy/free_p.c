#include "main.h"
/**
 * free_grid - a function that frees a 2 dimensional grid
 * previously created by your alloc_grid function.
 *
 * @grid: the return pointer from the function alloc_grid.
 * @height: the height of the array.
 *
 * Return: no return.
 */
void free_grid(char **grid, int height)
{
	int i = 0;

	for (; i < height; i++)
		free(grid[i]);
	free(grid);
}
