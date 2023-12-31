# [Golomb Rulers](https://open.kattis.com/problems/golombrulers)

A ‘Golomb ruler’ is a set of unique positive integers (called ‘marks’) which can
be used to measure distances by using the difference between pairs of marks.
Golomb rulers are useful in designing radio antennae and in cryptography.  It’s
helpful to think of the marks as being measurement marks on a real ruler.  For
example, $\{0, 1, 3\}$ is a Golomb ruler which can be used to measure distances
of $1$ (by using $1 - 0$), $2$ (by using $3 - 1$), and $3$ (by using $3 - 0$).
One extra constraint on a Golomb ruler is that there is at most one unique way
to measure a given distance. So $\{0, 1, 2\}$ is not a Golomb ruler, because
there are two ways to measure the distance $1$: $1 - 0 = 1$, and $2 - 1 = 1$.
Another Golomb ruler is $\{0, 1, 4, 6\}$, and the distances that it can measure
are
$$
1 = 1 - 0\\
2 = 6 - 4\\
3 = 4 - 1\\
4 = 4 - 0\\
5 = 6 - 1\\
6 = 6 - 0
$$

If a Golomb ruler can be used to measure all distances from $1$ to $n$ (where
$n$ is the largest mark), then it is called _perfect._ If the largest mark in a
Golomb ruler is as small as possible for all rulers with the same number of
marks, then the ruler is called _optimal._ The rulers above are each both
perfect and optimal.

For this problem, you need to determine whether some set of numbers make a
Golomb ruler, and if that Golomb ruler is perfect.

## Input

Each line of input contains a list of at least two but at most $25$
space-separated distinct integers in the range $[0, 2\,000]$.  Each list of
numbers includes $0$.  There are at most $1000$ lines of input.  Input ends at
the end of file.

## Output

For each input line, if the numbers given make a perfect Golomb ruler, output
`perfect`.  If they make a Golomb ruler that is not perfect, output `missing`
followed by a space-separated list of numbers that are missing from the ruler
in the range $1$ to the largest mark, in increasing order.  If the numbers do
not make a Golomb ruler, output `not a ruler`.

### Sample Input 1

```
0 1 2
0 3 1
0 5
0 1 4 9 10
0 1 4 9 11
```

### Sample Output 1

```
not a ruler
perfect
missing 1 2 3 4
not a ruler
missing 6
```
