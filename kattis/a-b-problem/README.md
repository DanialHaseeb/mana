# [$A + B$ Problem](https://open.kattis.com/problems/aplusb)

Given $N$ integers in the range $[-50\,000, 50\,000$, how many ways are there to
pick three integers, $a_i$, $a_j$, and $a_k$, such that $i$, $j$, and $k$ are
pairwise distinct and $a_i + a_j = a_k$?  Two ways are different if their
ordered triples, $(i, j, k)$, of indices are different.

## Input

The first line of input consists of a single integer,
$N$ ($1 \le N \le 200\,000$).  The next line consists of $N$ space-separated
integers, $a_1, a_2, \ldots, a_N$.

## Output

Output an integer representing the number of ways.

### Sample Input 1

```
4
1 2 3 4
```

### Sample Output 1

```
4
```

### Sample Input 2

```
6
1 1 3 3 4 6
```

### Sample Output 2

```
10
```
