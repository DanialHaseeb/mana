# [Take Two Stones](https://open.kattis.com/problems/twostones)

Alice and Bob are playing a new game of stones.  There are $N$ stones placed on
the ground, forming a sequence.  The stones are labeled from $1$ to $N$.

Alice and Bob in turns take exactly two consecutive stones on the ground until
there are no consecutive stones on the ground.  That is, each player can take
stone $i$ and stone $i + 1$, where $1 \le i \le N-1$.  If the number of stones
left is odd, Alice wins.  Otherwise, Bob wins.

Assume both Alice and Bob play optimally and Alice plays first, do you know who
the winner is?

## Input

The input contains an integer $N$ ($1 \le N \le 10\,000\,000), the number of
stones.

## Output

Output the winner, `Alice` or `Bob`, on a line.

### Sample Input 1

```
1
```

### Sample Output 1

```
Alice
```

### Sample Input 2

```
2
```

### Sample Output 2

```
Bob
```

### Sample Input 3

```
5
```

### Sample Output 3

```
Alice
```
