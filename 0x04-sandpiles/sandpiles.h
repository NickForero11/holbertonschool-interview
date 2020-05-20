#ifndef _SAND_PILES_H_
#define _SAND_PILES_H_
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int check_neighbours(int grid[3][3], int x, int y);
void copy_sandpile(int origin[3][3], int destiny[3][3]);
int check_stability(int grid[3][3]);
static void print_grid(int grid[3][3]);

#endif /* SAND_PILES_H */
