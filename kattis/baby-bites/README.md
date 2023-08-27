# [Baby Bites](https://open.kattis.com/problems/babybites)

Arild just turned 1 year old, and is currently learning how to count.  His
favorite thing to count is how many mouthfuls he has in a meal: every time he
gets a bite, he will count it by saying the number out loud.  Unfortunately,
talking while having a mouthful sometimes causes Arild to mumble
incomprehensibly, making it hard to know how far he has counted.  Sometimes you
even suspect he loses his count!  You decide to write a program to determine
whether Arild's counting makes sense or not.

## Input

The first line of input contains an integer $N$ ($1 \leq N \leq 1\,000$), the
number of bites Arild receives.  The second line contains $N$ space-separated
words spoken by Arild, the $i$<sup>th</sup> of which is either a non-negative
integer $i$ ($1 \leq i \leq N$) or the string "mumble".

## Output

If Arild's counting might make sense, print the string `makes sense`.
Otherwise, print the string `something is fishy`.

### Sample Input 1

```
5
1 2 3 mumble 5
```

### Sample Output 1

```
makes sense
```

### Sample Input 2

```
8
1 2 3 mumble mumble 7 mumble 8
```

### Sample Output 2

```
something is fishy
```

### Sample Input 3

```
3
mumble mumble mumble
```

### Sample Output 3

```
makes sense
```
