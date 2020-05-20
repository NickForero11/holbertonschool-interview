#include "sandpiles.h"

/**
 * print_grid - Prints the content of a sandpile with a nice format.
 *
 * @grid: The sandpile that will be printed.
 *
 * Return: Always nothing (void).
 */
static void print_grid(int grid[3][3])
{
	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			if (x)
				printf(" ");
			printf("%d", grid[y][x]);
		}
		printf("\n");
	}
}

/**
 * check_stability	-	Checks if a sandpile is stable, which is
 *						when none of its cells contains more than 3 grains.
 *
 * @grid: The base sandpile that will be checked.
 *
 * Return: 1 if the sandpile is stable, 0 otherwise.
 */
int check_stability(int grid[3][3])
{
	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			if (grid[y][x] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * copy_sandpile - Copy the content of a 3x3 sandpile to another sandpile.
 *
 * @origin: The sandpile that will be copied.
 *
 * @destiny: The sandpile that will store the values of origin.
 *
 * Return: Always nothing (void).
 */
void copy_sandpile(int origin[3][3], int destiny[3][3])
{
	int x, y;

	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			destiny[y][x] = origin[y][x];
		}
	}
}

/**
 * check_neighbours	-	Checks if the neighbours of the current position
 *						would overflow it and in that case how much.
 *
 * @grid: The base sandpile that will be checked.
 *
 * @x: The x coordinate of the current position.
 *
 * @y: The y coordinate of the current position.
 *
 * Return: how much the neighbours of the current position will overflow it.
 */
int check_neighbours(int grid[3][3], int x, int y)
{
	int up, down, right, left, response;

	/*Set variables*/
	up = y - 1, down = y + 1, left = x - 1, right = x + 1, response = 0;

	/*Check neighbors if they exist and take in account*/
	/*if they will overflow in our position*/

	if (up >= 0 && grid[up][x] > 3)
		response++;
	if (down < 3 && grid[down][x] > 3)
		response++;
	if (left >= 0 && grid[y][left] > 3)
		response++;
	if (right < 3 && grid[y][right] > 3)
		response++;
	return (response);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 *
 * @grid1: The base sandpile.
 *
 * @grid2: The sandpile that will be added to @grid1.
 *
 * Return: Always nothing (void).
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int x, y;
	int aux[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};

	/*Do the the sum of every element*/
	for (y = 0; y < 3; y++)
	{
		for (x = 0; x < 3; x++)
		{
			grid1[y][x] += grid2[y][x];
		}
	}

	/*If the sandpile isn't stable then toppling it until it's stable*/
	while (!check_stability(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		copy_sandpile(grid1, aux);
		for (y = 0; y < 3; y++)
		{
			for (x = 0; x < 3; x++)
			{
				/*Overflow the value and check its neighbours*/
				grid1[y][x] = aux[y][x] > 3 ? aux[y][x] - 4 : aux[y][x];
				grid1[y][x] += check_neighbours(aux, x, y);
			}
		}
	}
}
