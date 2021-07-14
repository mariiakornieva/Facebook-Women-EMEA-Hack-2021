# Problem
You’re trying to find where the swag is kept in the Facebook office and, as expected, all the best stuff is hidden in hard to reach places. Fortunately, you manage to make your way to one of the screens on the wall that shows you the map of the floor and the location of the most coveted swag (a Wayfinder).

Since swag is such a valuable commodity at Facebook, a number of doors, D, stand between you and your goal. Doors are opened using tokens and luckily for you, the map also shows you where they have been left in the office.

Your task is to determine whether it is possible to reach your goal (the swag) by using tokens to open the doors in your way, in each of the N maps in your input.

Your office consists of a W×H grid, filled with the following elements:
  - Empty space, represented by .
  - Walls, represented by #
  - Doors, represented by D
  - Tokens, represented by T
  - Your starting position, represented by S
  - Your goal (the swag!), represented by G

Each map has at most **one door** and **one token**. The token can be picked up by walking into it, and the door can be unlocked by walking into it while holding the token.  You can move orthogonally (up, down, left or right) but not diagonally, and you can’t walk into a wall at any point, or the locked door unless you are holding the token.

## Constraints
 - Each map will contain exactly one starting position and goal
 - Each map will contain at most one door and token
 - 500 ≤ W ≤ 50
 - 500 ≤ H ≤ 50
 - 1000 ≤ N ≤ 100
 - 10 ≤ D ≤ 1

## Input
Your input file consists of N, W×H maps, separated by blank lines, and encoded using the characters described above (., #, D, T, S, G).

## Output
Your output should be a file containing a single line consisting of N characters, separated by spaces:
O_0\;O_1\;\ldots\;O_{N-1}
![\Large O_0\;O_1\;\ldots\;O_{N-1}]

where O_i should be **P if it is possible** to reach the swag in the i-th map and **I otherwise**.

## Explanation of Sample
  - In the first map, it is possible to walk to the token, then to the door to unlock it, gaining access to the room containing the swag.
  - In the second example, the swag is already in the room you started in, so it is possible to access without opening any doors.
  - In the last example, there is no way for you to unlock the door as your access to the token is also blocked by the door it is meant to open!

## Sample Input
```
..........
..........
..........
.......G..
..........
..........
####D#####
..........
....S.....
.........T

..........
..........
..........
.......T..
..........
..........
####D#####
..........
....S.....
.........G

..........
..G.......
..........
.......T..
..........
..........
####D#####
..........
....S.....
..........
```

## Sample Output
```
P P I
```
