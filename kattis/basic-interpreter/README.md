# [`BASIC` Interpreter](https://open.kattis.com/problems/basicinterpreter?editsubmit=11568320)

The BASIC computer programming language has been popular for many years, and
there have been dozens of ‘dialects’ of the language.  It’s considered a
high-level language and is typically interpreted (rather than compiled).  For
this problem, write an interpreter for a restricted dialect of BASIC.  Here is a
description of the language.

Each input line contains one statement.  Each statement begins with a
non-negative integer, which we will call its label.  Following the label is a
single space and one of the following commands (with explanations following):

* `LET X = <ARITHMETIC_STATEMENT>`\
	Assign the result of the arithmetic statement to variable `X`.
* `IF <CONDITION> THEN GOTO L`
	If the boolean given is true, then go to the statement labeled `L`, where `L`
	is a valid label.  (If the condition is not true, continue execution to the
	statement with the next lowest label.)
* `PRINT <PRINT_STATEMENT>`\
	Produce output, without an appended newline.
* `PRINTLN <PRINT_STATEMENT>`\
	Produce output, with an appended newline.

Here are details on types, variables, and the terms `<ARITHMETIC_STATEMENT>`,
`<CONDITION>`, and `<PRINT_STATEMENT>` used above.

* All numeric values (in the input and for the variable representation) are
	signed $32$-bit integers.
* All variables are single uppercase characters (`A` through `Z`).  They are all
	global in scope, and are all initialised to zero before program execution
	begins.
* `<ARITHMETIC_STATEMENT>` is one of the following: `X`, `X + Y`, `X - Y`,
	`X * Y`, or `X / Y`.  Here, `X` and `Y` each indicate either a variable or an
	integer.
* `<CONDITION>` is one of the following: `X = Y`, `X > Y`, `X < Y`, `X <> Y`,
	`X <= Y`, or `X >= Y`.  Again, `X` and `Y` each indicate either a variable or
	an integer. Here, `<>` indicates inequality.
* `<PRINT_STATEMENT>` is either a variable name or a literal string delimited by
	double quotes.  Inside the quotes, the string contains only alphanumeric
	characters (`a`–`z`, `A`–`Z`, `0`–`9`) and spaces.

In the signed $32$-bit arithmetic, the usual rules of truncation towards zero
(for division) and overflow (for addition and multiplication) and underflow (for
subtraction) apply.  The following examples illustrate these conditions:

```
5/2 = 2
-1 / 2 = 0
2147483647 + 1 = -2147483648
-2147483648 - 1 = 2147483647
65536 * 32768 = -2147483648
-65536 * 32768 = -2147483648
-2147483648 * 2 = 0
2147483647 * 2 = -2
```

Further, division by zero will not occur.

Program execution begins with the statement having the smallest label, and
proceeds with the statement having the next smallest label. (Unless a `GOTO`
executes, in which case execution proceeds at the designated label.) The program
halts after it has completed the statement with the largest label (which is
guaranteed not to contain a `GOTO`).

## Input

Input consists of a single program.  Each line contains a single valid
statement.  Each pair of adjacent tokens in the input is separated by a single
space.  Integers in the input will all be in the range
$-2^{31}$ to $2^{31} + 1$.  Input ends at end of file.

## Output

Give the output (`PRINT` and `PRINTLN` statements) of the input program when it
is executed.

### Sample Input 1

```
10 LET A = 1
20 PRINT "HELLO THERE "
30 PRINTLN A
40 LET A = A + 1
50 IF A <= 5 THEN GOTO 20
60 PRINTLN "DONE"
```

### Sample Output 1

```
HELLO THERE 1
HELLO THERE 2
HELLO THERE 3
HELLO THERE 4
HELLO THERE 5
DONE
```

### Sample Input 2

```
40 PRINT P
180 PRINTLN "DONE"
130 PRINTLN " IS PRIME"
60 LET X = D * D
80 LET R = P / D
100 LET R = P - R
20 LET D = 1
140 IF 1 = 1 THEN GOTO 180
30 LET P = 111
150 PRINTLN " IS NOT PRIME"
170 PRINTLN " IS A DIVISOR"
50 LET D = D + 1
70 IF P < X THEN GOTO 130
120 IF 1 = 1 THEN GOTO 50
90 LET R = R * D
110 IF R = 0 THEN GOTO 150
10 PRINTLN "PRIME TESTER"
160 PRINT D
```

### Sample Output 2

```
PRIME TESTER
111 IS NOT PRIME
3 IS A DIVISOR
DONE
```
