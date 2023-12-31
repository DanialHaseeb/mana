# [Credit Card Payment](https://open.kattis.com/problems/creditcard)

Using credit cards for your purchases is convenient, but they have high interest
rates if you do not pay your balance in full each month.

The interest rate is commonly quoted in terms of “annual percentage rate” (APR)
which is then applied to the outstanding balance each month.  The APR can be
converted to a monthly interest rate $R$.  At the end of each month, the monthly
interest rate is applied to the outstanding balance and the interest is added to
the total balance.  Any payment made will be applied to the balance in the
following month.  The monthly interest is rounded to the nearest cent (rounding
up $0.5$ cent and above) in the calculations.

You have unfortunately accumulated an outstanding balance  at the end of the
month and you can only afford to pay up to some amount $M$ every month.  If you
do not make any more purchases with the credit card, what is the minimum number
of payments needed to completely eliminate the outstanding balance?  It is
possible that you cannot pay off the balance in $100$ years ($1\,200$ payments).

## Input

The input consists of multiple test cases.  The first line of input is a single
integer, not more than $1\,000$, indicating the number of test cases to follow.
Each of the following lines specify the input for one case.  Each line contains
three positive real numbers separated by single spaces: $R$, $B$, and $M$.  The
real numbers have two digits after the decimal point, satisfying $R \le 50.00$
and $B,\, M \le 50\,000.00$.  $R$ is the monthly interest rate and is specified
as a percentage.

## Output

For each case, display, on a line, the minimum number of payments needed to
eliminate the outstanding balance.  If this cannot be done in at most $1\,200$
payments, print instead `impossible`.

### Sample Input 1

```
11
2.00 100.00 105.00
2.00 100.00 102.00
2.00 100.00 100.00
2.00 100.00 4.00
2.00 100.00 3.00
2.00 100.00 1.00
2.00 100.00 2.00
9.56 5462.50 522.22
12.50 29876.44 33610.99
5.50 1.00 1.05
14.78 40181.09 46119.86
```

### Sample Output 1

```
1
1
2
36
56
impossible
impossible
impossible
2
2
1
```
