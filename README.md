# Alien vs. Zombie

Alien vs. Zombie is a simplified, text-based version program that was inspired from the game Alien Path with several modifications of our own. In this program, the user navigates an alien on a path to destroy zombies. It combines several elements of role-playing game, path-planning, puzzle, and strategy. 

[Video Demo] part 1=(https://youtu.be/Jzz_fhH3CvA).
             part 2=(https://youtu.be/2Yp9cdy-eII)

## Compilation Instructions

To compile and build the program into an executable program, type:

```
g++ main.cpp 

```

## User Manual
First, open the program.After that, press Enter to continue and default game settings will be shown. the game default setting is shown. User also have an option whether the user want to change the setting. Press ‘y’ for yes and ‘n’ for no. If user chose ‘y’, user must input custom rows, columns and zombies. Note that only odd number that larger than 1 rows and columns accepted. The number of zombies must not more than 8. f user chose ‘n’, the rows and columns with default settings will be shown. Then a gameboard based on rows and columns chose by user will be shown. All alien and zombies attributes will also appear. User required to put commands to play the game. to help the user with all the commands, user can type help in the command section. then all of the commands to play the game will appear. Press Enter to get back to the command section. For alien movement, there are commands ‘up’, ‘down’, ‘right’, ‘left’ which will move the alien to the intended direction. For example here we move the alien to the right using ‘right’ command. After that zombies will have their own turn. We don’t need to move the zombie because we only play as the alien. Then user can start playing the game as they intended. For command ‘arrow’, user can switch the direction of an arrow object in the game board. User will be asked to enter the row and column of the arrow object to switch, followed by the direction of the arrow object to switch to. For example, in row 7 column 7, the direction is up (<). We will change the direction to down (^).The zombie’s and alien’s turns take place until all zombies or the alien dies. Which the game will end.For each objects in the board, the objects has its own function as shown below. User can also save their current game by using command ‘save’ and user is required to name the file to store all the user’s game data.User can also load their saved game by using command ‘load’. To quit the game, user can type ‘quit’ command and user will exit from the game instantly.
Refer UserManual.pdf for detailed information with images





## Progress Log

- [Part 1](PART1.md)
- [Part 2](PART2.md)

## Contributors

- MUHAMMAD RINO FRAWIDYA BIN SUHERI
- LING CHEE XIANG
- SIDDIQ FERHAD BIN KHAIRIL ANUAL
