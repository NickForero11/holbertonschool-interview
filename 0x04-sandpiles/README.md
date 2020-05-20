# 0x04. Sandpiles

## Description

A solution to the problem of sum two sandpiles in C language.

---

### [0. Sandpiles sum](./0-sandpiles.c)

Function that computes the sum of two sandpiles:

* Prototype: ```void sandpiles_sum(int grid1[3][3], int grid2[3][3]);```

* Both grid1 and grid2 must be individually stable.
* A sandpile is considered stable when none of its cells contains more than 3 grains.
* When the function is done, grid1 its stable.
* The function can't allocate memory dynamically
* grid1 will be printed before each toppling round, only if it's unstable (See example):

```C
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
```

---

## Author

* **Nicolas Forero Puello** - [NickForero11](https://github.com/NickForero11)
