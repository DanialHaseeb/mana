# [Memory Match](https://open.kattis.com/problems/memorymatch)

You are playing the game “Memory Match”.

This game revolves around a set of $N$ picture cards. The cards are organised in
pairs: there are $\frac N 2$ different pictures, each picture occurring on
exactly two cards.

At the beginning of the game, the cards are shuffled and laid face down on the
table.  Players then take turns in guessing a pair of cards with the same
picture.  Each turn consists of picking a face-down card and turning it over to
reveal its picture, then picking another face-down card and turning that card
over as well.  If the pictures on the two turned cards are identical, the cards
remain face-up, the player scores a point and may take another turn.  If the
pictures are different, both cards are turned face-down again and the turn goes
to the next player.

It is now your turn!  Given a description of all previous actions in the game,
pick as many matching pairs as possible.

## Input

The first line contains an even integer $N$, the number of cards on the table
($2 \le N \le 1\,000$).

The second line contains an integer $K$, the number of turns played thus far in
the game ($0 \le K \le 1\,000$).

The following $K$ lines each describe a turn.  A turn is described by integers
$C_1$ and $C_2$ followed by words $P_1$ and $P_2$.  The numbers $C_1$ and $C_2$
refer to card positions on the table ($1 \le C_1$, $C_2 \le N$, and
$C_1 \ne C_2$).  The words describe the pictures on the two selected cards.
Each word consists of between $1$ and $20$ lowercase letters in range
$[\text{\texttt{a}}, \ldots, \text{\texttt{z}}]$.  If $P_1 = P_2$, the two cards
stay face-up and the corresponding positions, $C_1$ and $C_2$, may not be chosen
again.

The input is such that at least two cards are still in face-down position.

## Output

Output one line with an integer $S$, the number of matching pairs you can score
with certainty.

### Sample Input 1

```
8
5
1 3 earth sun
2 6 mars sun
6 3 sun sun
7 5 earth moon
2 7 mars earth
```

### Sample Output 1

```
3
```

### Sample Input 2

```
10
6
1 2 moon earth
9 10 venus sun
8 7 moon venus
1 8 moon moon
4 10 sun sun
9 6 venus mars
```

### Sample Output 2

```
3
```

### Sample Input 3

```
8
2
1 3 moon earth
2 6 sun earth
```

### Sample Output 3

```
1
```
