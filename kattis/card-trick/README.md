# [Card Trick](https://open.kattis.com/problems/cardtrick2)

The magician shuffles a small pack of cards, holds it face down and performs the
following procedure:
1. The top card is moved to the bottom of the pack.  The new top card is dealt
	 face up onto the table.  It is the Ace of Spades.
2. Two cards are moved one at a time from the top to the bottom.  The next card
   is dealt face up onto the table.  It is the Two of Spades.
3. Three cards are moved one at a time...
4. This goes on until the $n$<sup>th</sup> and last card turns out to be the $n$
   of Spades.

This impressive trick works if the magician knows how to arrange the cards
beforehand (and knows how to give a false shuffle).  Your program has to
determine the initial order of the cards for a given number of cards.

## Input

On the first line of the input is a single positive integer $T \le 13$, the
number of test cases to follow.  Each case consists of one line containing the
integer $n$ ($1 \le n \le 13$).

## Output

For each test case, output a line with the correct permutation of the values $1$
to $n$, space separated.  The first number showing the top card of the pack,
etc…

### Sample Input 1

```
2
4
5
```

### Sample Output 1

```
2 1 4 3
3 1 4 5 2
```
