# Test file
## 1st Test

```
INPUT: LET F = 2X + 4
F = 2X+4
INPUT: PRINT F
F = 2X+4
INPUT: EVAL F(1/4)
F(1/4) = 9/2
INPUT: LET G = 3X^2
G = 3X^2+0
INPUT: PRINT G
G = 3X^2+0
INPUT: LET H = 4X^1/3
H = 4X^1/3+0
INPUT: A = G + H
INPUT: PRINT A
A = 3X^2+4X^1/3+0
INPUT: B = G - H
INPUT: PRINT B
B = 3X^2+4X^1/3+0
INPUT: C = G * H
INPUT: PRINT C
C = 12x^7/3+0x^2+0x^1/3+0
INPUT: D = G'
INPUT: PRINT D
D = 6x+0x^-1
INPUT: E = G''
INPUT: PRINT E
E = 6+0x^-2
INPUT: F = H'''
INPUT: PRINT F
F = 40/27x^-8/3+0x^-3
INPUT: LET I = 1/2
I = 1/2
INPUT: LET I = 1.2
I = 17/10
INPUT: LET I = 1.2
I = 29/10
INPUT: LET J = 1.2
J = 6/5
INPUT: LET J = 0
J = 6/5
INPUT: LET H = 3X
H = 3X+4X^1/3+0
INPUT: LET K = 3X
K = 3X+0
INPUT:
```
Problems: 

- [x] `algebra`: needs auto printing result
- [x] `expression::combineterms` : needs to auto delete when `coeff == 0`
- [x] `expression`: `-` operator: not working
- [x] `expression` string `setExp`: why is it being added to the expression?  should overwrite
- [x] `getCommand`: terminate when cin has only `\n`
