# [Battleship](https://open.kattis.com/problems/battleship)

When playing battleship, players take turns trying to sink the other players
navy.  Each player may take shots at one coordinate at once. If he hits one of
his enemy’s ships and the enemy has any other ships left, he may continue.
Else, the other player may take shots.  After hitting a ship at one coordinate,
shooting at that coordinate again counts as a miss.

The game is finished when every part of every ship of a navy of one player has
been hit.  The first player starts, and every player gets the same number of
turns.  That means, that the second player might get another turn even if all
his ships have been sunk.

The game ends with a draw if both navies are completely sunk, or if there are
still ships left after all shots have been fired.

Tom the little spy watches a game of battleships between two fleet admirals.  As
he has successfully tapped the communication wires, he can intercept the shot
orders.  However, he was unable to determine which admiral ordered what shot to
be fired.

After the game, he successfully breaks into the super secret game management
facility, and manages to secure the fleet deployment maps.  As he wants to
determine which fleet admiral is more dangerous, he wants to know which admiral
won.

He transmits the deployment maps and the shot orders, and wants you to determine
which admiral won.

## Input

Input starts with one line, containing the number of test cases, $t$
($0 < t \le 20$).

Every test case starts with a line, containing three integers $w$, $h$, and $n$
($1 \le w$, $h \le 30$; $1 \le n \le 2\,000$), describing the width and height
of the fleet deployment maps, and the number of shots.

The next $h$ lines contain the deployment map for player one.  Each line
contains $w$ field descriptions, where `_` means “water” and `#` means “ship”.
Then follow $h$ lines containing the deployment map for player two.

The following $n$ lines contain the shot orders; each order consists of two
integers, the $x$- and $y$-coordinate of the shot.  The $x$-coordinate indicates
the column of the shot, running from $0$ to $w - 1$, with $0$ meaning the
left-most column.  The $y$-coordinate indicates the line of the shot, running
from $0$ to $h - 1$, with $0$ meaning the last line and $h - 1$ meaning the
first line of the respective map.

Please note that there may be more shot orders than needed to end the game.

## Output

For every test case, print one of `player one wins`, `player two wins` or
`draw`, on a line.

### Sample Input 1

```
2
4 4 5
____
____
#___
____
#___
___#
____
____
0 0
1 1
0 3
0 2
0 1
2 2 5
_#
#_
#_
#_
1 0
0 0
0 0
1 1
0 1
```

### Sample Output 1

```
player two wins
draw
```
