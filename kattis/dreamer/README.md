# [Dreamer](https://open.kattis.com/problems/dreamer)

Bash just woke up from his sweetest dream ever.  In his dream, he became the
best Pokenom trainer---like no one ever was.  It was on the date…

Unfortunately, Bash forgot the exact date.  He only remembered that the date was
written in format `DD MM YYYY` with exactly $8$ digits.  He also remembers these
$8$ digits (but he does not remember their order).  Of course, the date must be
a valid date.

Since Bash was born on January 1<sup>st</sup>, 2000, he knows that the date was
on or after January 1<sup>st</sup>, 2000. (Note that the date can be January
1<sup>st</sup>, 2000---it means Bash is destined to be the best Pokenom trainer
since he was born!).

Bash really wants to know the date when he become the best Pokenom trainer.  How
many possible valid dates could there be?  What is the earliest valid date that
Bash could become the best Pokenom trainer?

## Notes

On a leap year, February has $29$ days.  Following are the rules for determining
leap years:

* A year divisible by $400$ is a leap year,

* A year divisible by $100$ but not by $400$ is NOT a leap year,

* A year divisible by $4$ but not by $100$ is a leap year,

* A year not divisible by $4$ is NOT a leap year.

## Input

* The first line contains one integer---the number of test cases.

* Each of the next  lines describes one test case, contains eight digits in the
  format `XX XX XXXX` (eight digits, separated by two blank spaces).  Note that
	the input might not represent a valid date.

Note that the first month of the year is represented by $01$, and the first day
of the month by $01$.

## Output

For each test case, output a single line containing the number of possible dates
and the earliest date which Bash could become the best Pokenom trainer, in the
format `DD MM YYYY`.  If there are no valid dates, print a single line
containing `0` (zero) instead.

### Sample Input 1

```
3
04 11 2018
23 45 6789
01 01 0002
```

### Sample Output 1

```
524 18 11 2004
0
4 01 01 2000
```
