# Alien vs. Zombie

Alien vs. Zombie is a text-based game inspired by *Alien Path*, with custom modifications. The game combines elements of role-playing, path-planning, puzzles, and strategy. Players control an alien navigating a path to destroy zombies.

## 🎥 Video Demo
- [Part 1](https://youtu.be/Jzz_fhH3CvA)
- [Part 2](https://youtu.be/2Yp9cdy-eII)

## 🛠️ Compilation Instructions
To compile and build the program, run:
```sh
g++ main.cpp -o AlienVsZombie
```

## 📖 User Manual
1. **Start the Game**: Run the program and press Enter to continue. The default game settings will be displayed.
2. **Customize Settings**: Choose `y` to set custom values for rows, columns, and zombies, or `n` to use the default settings.
   - Rows & columns must be odd numbers greater than 1.
   - The number of zombies must not exceed 8.
3. **Game Board Display**: A game board based on user selection appears, along with attributes for the alien and zombies.
4. **Game Commands**:
   - `help` → Displays all available commands.
   - **Movement**: Use `up`, `down`, `left`, `right` to move the alien.
   - **Arrow Control**: Use `arrow` to change an arrow object’s direction by specifying its row, column, and new direction.
   - **Saving & Loading**: Use `save` to store progress, and `load` to resume a saved game.
   - **Quit Game**: Use `quit` to exit instantly.
5. **Gameplay**:
   - The game alternates turns between the alien and zombies.
   - The game ends when either all zombies or the alien are eliminated.

📄 *Refer to `UserManual.pdf` for detailed gameplay and images.*

## 📜 Progress Log
- [Part 1](PART1.md)
- [Part 2](PART2.md)

## 👥 Contributors
- **MUHAMMAD RINO FRAWIDYA BIN SUHERI**
- **LING CHEE XIANG**
- **SIDDIQ FERHAD BIN KHAIRIL ANUAL**

---
🚀 *Enjoy the game and feel free to contribute!*

