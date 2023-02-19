# Alien vs. Zombie

Alien vs. Zombie is a simplified, text-based version program that was inspired from the game Alien Path with several modifications of our own. In this program, the user navigates an alien on a path to destroy zombies. It combines several elements of role-playing game, path-planning, puzzle, and strategy. 

[Video Demo](https://youtu.be/Jzz_fhH3CvA).

## Compilation Instructions

To compile and build the program into an executable program, type:

```
g++ main.cpp 

```

## User Manual

When user run the program, user will be shown with an interface saying "Welcome to Alien Vs Zombie". To proceed to the next part, press "Enter". User will be shown with the default game setting which says rows are 7 and columns are 7. If user wants to change the values, press "y" and then "Enter". Put your new values for row and column. If user wants to stick with the default values, press "n" and then "Enter". After that, user will be shown with a two-dimensional gameboard containing game objects such as alien, zombies, rock, pod, health and arrows. Take note that the positioning of the game objects are at random except for the alien. After display the gameboard,user can enter a commant to play the game.If user enter 'help', it will display all of the command words that user can enter.User can even save and load the game by enter their filename. If user want to quit the game,he/she can enter 'quit' to quit the game. To let the 'A' which represent alien moves,user can only enter 'up' to let alien moves up one column,'down' to let alien moves down one column,'left' to let alien moves left one row,'right' to let alien moves right one row.For game object which represent by 'h','p','r' will give some benefit to alien,For example,if alien go to 'h' location its life will add 20 but if alien life is 100 it can't be added because already full. When alien reach 'p' which is pod location,the pod will attack the zombie will 10 attack power that nearest to the pod.When alien hit the 'r' which is rock it may blocks the alien for moving and reveals the hidden game object when hit by Alien. If alien reach these arrows location:'^','v','<','>' alien will add 20 attack power to itself.During the game,there will be t 


## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

- MUHAMMAD RINO FRAWIDYA BIN SUHERI
- LING CHEE XIANG
- SIDDIQ FERHAD BIN KHAIRIL ANUAL
