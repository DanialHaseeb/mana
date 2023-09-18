# [Knight Packing](https://open.kattis.com/problems/knightpacking)

On a $N \times N$ chess board, two players alternate placing a knight on the
board.  A knight can only be placed if there is no other knight which would be
either $1$ row and $2$ columns or $2$ rows and $1$ column away from it.  The
first player who cannot place a knight on the board loses.

Given the size of the board, compute if the first or second player wins.

## Input

The first line of input contains the integer $N$ ($1 \leq N \leq 1000$), the
size of the board.

## Output

Output `first` if the first player wins the game, or `second` if the second
player wins the game.

### Sample Input 1

```
1
```

### Sample Output 1

```
first
```

### Sample Input 2

```
2
```

### Sample Output 2

```
second
```

### Sample Input 3

```
3
```

### Sample Output 3

```
first
```
