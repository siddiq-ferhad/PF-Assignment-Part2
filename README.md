# Alien vs. Zombie

**Alien vs. Zombie** is a **C++ text-based game** developed using standard libraries only. Inspired by *Alien Path*, it combines elements of role-playing, path-planning, puzzles, and strategy. Players control an alien navigating a grid to destroy zombies.

## 🎥 Video Demo

* [Part 1](https://youtu.be/Jzz_fhH3CvA)
* [Part 2](https://youtu.be/2Yp9cdy-eII)

## 🛠️ Compilation Instructions

To compile and build the program, run:

```sh
g++ main.cpp
```

No external dependencies are required.

## 📖 User Manual

1. **Start the Game**: Run the program. The default game settings will be displayed:

   * Rows = 7, Columns = 7, Zombies = 5
2. **Customize Settings**: Choose `y` to set custom values for rows, columns, and number of zombies, or `n` to use default settings.

   * Rows & columns must be **odd numbers greater than 1**.
   * Number of zombies must be a **whole number between 1 and 9**.
3. **Game Board Display**: The board shows:

   * Rows and columns numbered for reference.
   * Symbols representing various game objects:

     * `A` → Alien (you)
     * `1-9` → Zombies
     * `^`, `v`, `<`, `>` → Arrows (boost Alien attack and change direction)
     * `h` → Health pack (+20 HP, max 100)
     * `p` → Pod (damages nearest Zombie)
     * `r` → Rock (reveals random object if hit)
4. **Game Commands**:

   * `help` → Displays the guide.
   * `up`, `down`, `left`, `right` → Move the Alien in that direction.
   * `arrow` → Change an arrow's direction by specifying row, column, and new direction.
   * `save` → Save your current game progress.
   * `load` → Load a previously saved game.
   * `quit` → Exit the game.
5. **Gameplay Overview**:

   * Alien moves first; Zombies follow.
   * Alien attack is temporary and resets after each move.
   * Zombie attack range scales with board size.
   * The game ends when the Alien dies (lose) or all Zombies are defeated (win).

## 📜 Progress Log

* [Part 1](PART1.md)
* [Part 2](PART2.md)

## 👥 Contributors

* **SIDDIQ FERHAD BIN KHAIRIL ANUAL**
* **MUHAMMAD RINO FRAWIDYA BIN SUHERI**
* **LING CHEE XIANG**

---

🚀 *Enjoy the game and feel free to contribute!*
