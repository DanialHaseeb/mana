# [Hraðgreining](https://open.kattis.com/problems/hradgreining)

Most Icelanders have found it hard to miss how many COVID tests have been
performed in their country to figure out whether people have COVID or not.  At
designated testing locations, samples are taken from both the nose and mouth.
They are then put into a DNA sequencer which returns a DNA string.  This string
consists of the letters _ACGTOV_.  This has made it significantly easier to
diagnose whether people have COVID, since one only has to check whether the DNA
string contains the substring _COV_.  Could you help the employees at the
testing location in figuring out whether the DNA string contains the substring
_COV_?

## Input

A single line containing the DNA string.

## Output

If the DNA string contains the substring `COV` then print `Veikur!`, otherwise
print `Ekki veikur!`.

### Sample Input 1

```
COV
```

### Sample Output 1

```
Veikur!
```

### Sample Input 2

```
COOOV
```

### Sample Output 2

```
Ekki veikur!
```
