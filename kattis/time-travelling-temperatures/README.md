# [Time Travelling Temperatures](https://open.kattis.com/problems/temperature)

Hello from the future.  I am a time traveller.  You would think that in the
future we have agreed to use a single scale for measuring temperature.  This is
not so.  In fact, we have all sorts of scales now.  All the big brands have made
their own.  This is a bit confusing.  Please help me figure it out.  In my day
to day work I have to relate to two different scales, $A$ and $B$.  Help me find
a temperature where the two scales are the same, so I don’t have to worry about
it.

## Input

Input consists of two space-separated integers, $X$ and $Y$. $X$ is the point on
$B$ where $A$ is zero. $Y$ is the number of degrees in $B$ that equal a change
of a single degree in $A$.

## Output

Output the temperature where both scales are the same.  This number must have an
absolute or relative error of at most $10^{-6}$.  If no such temperature exists,
output `IMPOSSIBLE` instead.  If more than one such point exists, output `ALL
GOOD` instad.

## Limits

* $-100 \le X \le 100$
* $1 \le Y \le 100$

### Sample Input 1

```
32 2
```

### Sample Output 1

```
-32
```

### Sample Input 2

```
1 3
```

### Sample Output 2

```
-0.500000000
```
