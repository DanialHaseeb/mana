# [Bit by Bit](https://open.kattis.com/problems/bitbybit)

A brand new Ultra-CISC microprocessor has a collection of instructions for
manipulating individual bits of one of its 32-bit registers.  The instructions
work as described in the following table.  In all cases, bit zero is the
low-order bit and bit 31 is the high-order bit.  The representation of the
instruction set makes it impossible to try to manipulate bits outside this
range.
* `CLEAR` $i$\
	Put a zero into bit $i$.
* `SET` $i$\
	Put a one into bit $i$.
* `OR` $i$ $j$\
	Store in bit $i$ the logical OR of the contents of bits $i$ and $j$.
* `AND` $i$ $j$\
	Store in bit $i$ the logical AND of the contents of bits $i$ and $j$.

Your job is to determine the contents of the register after a sequence of these
operations.  Unfortunately, you don’t know anything about what was in the
register before the instructions.

## Input

Input consists of multiple instruction sequences, each beginning with a positive
integer $n \le 100$.  This is followed by $n$ lines, each giving a legal bit
manipulation instruction.  All bits referenced are in the range $0$ – $31$
(inclusive).  The end of input is marked with a value of $0$ for $n$.

Each instruction sequence in the input is to be interpreted independently.  You
should assume nothing about the contents of the register before each instruction
sequence.

## Output

For each instruction sequence, print out a line giving the final contents of the
register.  Print your result in binary, with the most significant bit on the
left.  Since you don’t know anything about what was in the register before the
sequence, you may not be able to determine the values of some bits.  Just print
a question mark for these bits.

### Sample Input 1

```
3
SET 0
CLEAR 1
AND 2 2
6
SET 31
SET 30
CLEAR 29
AND 29 30
OR 29 30
AND 30 28
0
```

### Sample Output 1

```
??????????????????????????????01
1?1?????????????????????????????
```
