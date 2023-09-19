# [Magical Cows](https://open.kattis.com/problems/magicalcows)

Baxter Scott owns The Enlightened Dairy Co., a dairy company with magical cows.
Early each morning, he brushes his teeth, strolls outside, and finds that the
cows have doubled in number.  With double the number of cows, he can produce
double the quantity of milk.  While he is ecstatic that he has so many cows and
so much milk, the Dairy Regulator forces him to keep at most $C$ cows on any
given farm, which greatly complicates his business.

At The Enlightened Dairy Co., Baxter has access to an unlimited number of farms,
each with a maximum capacity of $C$ cows.  On each farm, cows reproduce at the
same rate: they always double in number when the clock strikes midnight.  To
stay within the Regulator’s rules, whenever a farm has strictly more than  cows,
Baxter selects half of the cows on that farm and moves them to an entirely new,
empty farm.  More precisely, if there are $D \le C$ cows on a farm, he leaves
all cows on the farm, but if there are $D > C$ cows on a farm, he leaves
$\left\lceil \frac{D}{2} \right\rceil$ cows on the farm and takes
$\left\lfloor \frac{D}{2} \right\rfloor$ cows to a new, empty farm.  He does
this early every morning, before the Regulator could possibly show up, so that
he can avoid paying hefty Moo Fees.

The Regulator needs to know how many farms she will be inspecting when she
visits The Enlightened Dairy Co.  The Regulator inspects every farm that has at
least one cow, and does not inspect any farm with zero cows.  Given the number
of cows on each farm with at least one cow on Day $0$, compute the number of
farms that need inspecting on any given day.

## Input

The first line of input contains three space-separated integers, $C$, $N$, and
$M$, where $C$ ($1 \le C \le 1\,000$) is the maximum number of cows allowed on
a farm, $N$ ($1 \le N \le 1\,000$) is the number of farms with at least one cow
on Day $0$, and $M$ ($1 \le M \le 50$) is the number of different days on which
the Regulator visits.  The following $N$ lines of input each have a single
integer, $c_i$ (1 \le c_i \le C), representing the number of cows on the
$i$<sup>th</sup> of the $N$ farms on Day $0$.  The final $M$ lines each have a
single integer, $d_j$ ($0 \le d_j \le 50$), representing a day when the
Regulator visits.  All $d_j$ are distinct.

## Output

For each $d_j$, output one line with a single integer: the number of farms the
Regulator will inspect on Day $d_j$.

### Sample Input 1

```
1 5 5
1
1
1
1
1
0
1
2
3
4
```

### Sample Output 1

```
5
10
20
40
80
```

### Sample Input 2

```
2 5 3
1
2
1
2
1
0
1
2
```

### Sample Output 2

```
5
7
14
```
