# [Connect the Dots](https://open.kattis.com/problems/connectthedots)

Write a program to read in a visual description of a connect-the-dots puzzle,
then connect the dots and print the result.

## Input

Input contains up to $100$ images.  Each image is rectangular and has dots
indicated by the symbols `0`, `1`, …, `9`, `a`, `b`, …, `z`, `A`, `B`, …, `Z`.
It is guaranteed that if any dot appears, then all preceding dots in the above
sequence also appear.  So, for example, if the dot `b` occurs, then dots `0`
through `9` and `a` also occur.  Each dot appears at most once.  Non-dots are
indicated by periods.  Each image has $1$ to $100$ rows and $1$ to $100$
columns.  Input ends at end of file.

## Output

For each image, print out the dots-connected image, as illustrated in the sample
output.  Connected dots will always be vertically or horizontally related; there
are no diagonal lines.  The lines should not obscure any dots, and if two lines
cross, then indicate that as shown with a plus (`+`).  Do not connect the last
dot with the first dot.  Produce a blank line between each pair of images.

## Sample Input 1

```
.....0.......1
..............
..............
.....3.......2

..0.....4......
...............
...............
...............
..2.....3.....7
...............
...............
...............
..1.....5.....6

..0...............7...........8....d
......4................3............
....................................
....................................
...........a..................9.....
....................................
..1....................2............
....................................
......5...........6.................
....................................
...........b.......................c
```

## Sample Output 1

```
.....0-------1
.............|
.............|
.....3-------2

..0.....4......
..|.....|......
..|.....|......
..|.....|......
..2-----3.....7
..|.....|.....|
..|.....|.....|
..|.....|.....|
..1.....5-----6

..0...............7-----------8....d
..|...4-----------+----3......|....|
..|...|...........|....|......|....|
..|...|...........|....|......|....|
..|...|....a------+----+------9....|
..|...|....|......|....|...........|
..1---+----+------+----2...........|
......|....|......|................|
......5----+------6................|
...........|.......................|
...........b-----------------------c
```
