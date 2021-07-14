# Problem A2: Keymaster
You’re trying to find where the swag is kept in the Facebook office and, as expected, all the best stuff is hidden in hard to reach places.  Fortunately, you manage to make your way to one of the screens on the wall that shows you the map of the floor and the location of the most coveted swag (a Wayfinder).

Since swag is such a valuable commodity at Facebook, a number of doors, DD, stand between you and your goal.  Doors are opened using tokens and luckily for you, the map also shows you where they have been left in the office.

Your task is to determine whether it is possible to reach your goal (the swag) by using tokens to open the doors in your way, in each of the NN maps in your input.

Your office consists of a W×H grid, filled with the following elements:
  - Empty space, represented by .
  - Walls, represented by #
  - Doors, represented by a number between 1 and 9, inclusive: the number of tokens required to open it
  - Tokens, represented by T
  - Your starting position, represented by S
  - Your goal (the swag!), represented by G

The swag was getting too easy to find, so there are now more doors and more tokens.  Doors can now require **between 1 and 9 (inclusive) tokens to unlock**, but you can re-use tokens as many times as you want (doors do not consume tokens).  As before, tokens are picked up by walking into them, and doors are unlocked by walking into them while holding the requisite number of tokens.   Walking into a door to unlock it does not reduce the number of tokens in your hand.  You can move orthogonally (up, down, left or right) but not diagonally, and you can’t walk into walls at any point, or a locked door unless you are holding enough tokens to unlock it.

## Constraints
 - Each map will contain exactly one starting position and goal
 - 0 ≤ W ≤ 50
 - 0 ≤ H ≤ 50
 - 0 ≤ N ≤ 100
 - 0 ≤ D ≤ 10

## Input
Your input file consists of N, W×H maps, separated by blank lines, and encoded using the characters described above (., #, 1, 2, ..., 9, T, S, G).

## Output
Your output should be a file containing a single line consisting of N characters, separated by spaces:
![\Large O_0\\ O_1\\ \ldots\\ O_{N-1}](https://latex.codecogs.com/gif.latex?O_0%5C%20O_1%5C%20%5Cldots%5C%20O_%7BN-1%7D)

where O_i should be **P if it is possible** to reach the swag in the i-th map and **I otherwise**.

## Explanation of Sample
  - In the first map, you are able to open the first door with the token from your starting room, this gains you access to another token, which combined with the token already in your hand, opens the door to the room containing the swag.
  - In the second map, although you can open the only door out of the starting room, all subsequent doors require at least two tokens to open, so you are stuck: it is not possible to reach the swag.
  - In the last map, you are able to open the door at the apex of the two diagonal walls with a token nearby.  This gives you access to two additional rooms on either side of the room you started in.  You are able to collect a token from each of these rooms, making a total of three in your hand.  These open the door in the horizontal wall.  Because tokens are not consumed by unlocking doors, you also have enough tokens to unlock the door that costs two tokens, in the vertical wall to reach the swag.

## Sample Input
```
..........
.....G....
..........
..........
####2#####
.T........
####1#####
..........
....S.....
.........T

.G....#...
......#...
###2###...
......#T..
......#...
......2...
####1#####
..........
....S..T..
..........

..#.......
..2.......
G.#.......
..#.......
########3#
.....1....
....#.#..T
T..#...#..
..#.S...#.
.#...T...#
```

## Sample Output
```
P I P
```
