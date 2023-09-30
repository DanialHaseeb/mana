# [Graduation](https://open.kattis.com/problems/skolavslutningen)

The school administration has encountered a problem with the upcoming school
graduation, a problem which they hope you can help them resolve.  During the
graduation ceremony, students will stand in $N$ rows with $M$ students in each
row.  The administration wants the graduation to be as colorful as possible and
will therefore hand out hats in different colors for the students.

For the lineup to look good, it’s important that all the students in the same
column have the same color of hat.  So that no one feels left out, it is also
important that all students in the same class have the same hat color.  The row
and column for each student has already been decided, but not the hat color.
The administration needs your help with assigning hat colors to the students so
that the graduation is as colorful as possible.

Write a program that, given how the students will be lined up, calculates the
maximum number of unique hat colors that can be assigned to the students.

## Input

The first line contains three integers $N$, $M$ ($1 \le N, M \le 700$), and $K$
($1 \le K \le 26$)---the number of lines, the number of columns, and the number
of classes.

Then $N$ lines follow, each with $M$ characters, describing how the students
will be lined up in the graduation.  The character in row $i$ and column $j$ is
an uppercase letter between `A` and the $K$<sup>th</sup> letter of the
alphabet---the class to which the student in row $i$, column $j$ belongs.  It is
guaranteed that each class has at least one student.

## Output

Print an integer---the maximum number of unique hat colors that can be be
assigned to the students so that all the students in the same column have the
same hat color, and also all students in the same class have the same hat color.

### Explanation of Sample Cases

In the first sample case, the second column has one student from class `A` and
one student from class `B`.  Since both of these students must have the same hat
color, everyone in class `A` must have the same color hat as everyone in class
`B`.  The conclusion is that all students must have the same color, so the
answer is $1$.

In the second sample case, classes `A` and `B` must have the same color, as
there is a student from each of these two classes in the first column. 	Class
`C`, on the other hand, can use a different color on their hats.  Therefore, the
answer is $2$.

In the third sample case, we can give each class its own color, since there are
no two students from different classes in the same column.  Thus, the answer is
$3$.

In the last sample case, we can assign one color to all students from classes
`A`, `B`, and `C`, and a different color to all students from classes `D` and
`E`.  So the answer is $2$.

### Sample Input 1

```
2 3 2
AAB
ABB
```

### Sample Output 1

```
1
```

### Sample Input 2

```
2 2 3
AC
BC
```

### Sample Output 2

```
2
```

### Sample Input 3

```
2 3 3
ABC
ABC
```

### Sample Output 3

```
3
```

### Sample Input 4

```
3 5 5
ABECE
BCDAE
CADBD
```

### Sample Output 4

```
2
```
