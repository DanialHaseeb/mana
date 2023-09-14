# [Calculating Dart Scores](https://open.kattis.com/problems/calculatingdartscores)

In a game of darts a player throws darts at a board consisting of $20$ different
sections labelled $1$ to $20$.  When the dart hits section $i$ the player scores
$i$ points.  Each section also contains a _double_ area and a _triple_ area.
When the dart hits the _double_ area of section $i$, the player scores $2i$
points, and when the dart hits the _triple_ area, the player scores $3i$ points,
instead of $i$ points.  When throwing three darts, the player can therefore
score a total of at most $180$ points by throwing all three darts in the triple
area of section $20$.

Given a target score, output at most three throw scores such that their sum is
equal to the given target score.  Note that the centre of the dartboard, which
is usually called _bullseye,_ is not taken into account is this problem.

## Input

The input consists of a single integer $n$ ($1 \le n \le 180$), the target
score.

## Output

If the target score can be achieved, output at most three lines, each of the
form `"single` $d$`"`, `"double` $d$`"`, or `"triple` $d$`"`, where $d$ is an
integer between $1$ and $20$ (inclusive), such that the sum of these scores is
equal to $n$.  Otherwise, output `impossible`.  If there are multiple valid
answers you may output any of them.

### Sample Input 1

```
180
```

### Sample Output 1

```
triple 20
triple 20
triple 20
```

### Sample Input 2

```
96
```

### Sample Output 2

```
triple 19
double 15
single 9
```

### Sample Input 3

```
27
```

### Sample Output 3

```
triple 9
```
