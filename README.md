# Alien vs. Zombie

**Alien vs. Zombie** is a **C++ text-based game** built entirely with standard C++ libraries. Inspired by *Alien Path*, this game combines role-playing, path-planning, puzzle-solving, and strategy into a grid-based battle where players control an Alien tasked with defeating Zombies.

## 🎥 Video Demo

* [Part 1](https://youtu.be/Jzz_fhH3CvA)
* [Part 2](https://youtu.be/2Yp9cdy-eII)

## 🛠️ Compilation Instructions

To compile and build the program:

```sh
g++ main.cpp
```

* No external libraries are required.
* The game runs fully in the console.

## 📖 User Manual

### 1. Game Setup

* When the game starts, default settings are displayed:

  * Rows = 7, Columns = 7, Zombies = 5
* You can choose to **change settings** or use the **default**:

  * Rows & Columns → Must be **odd numbers greater than 1**.
  * Number of Zombies → Must be **between 1 and 9**.

### 2. Game Board Symbols

| Symbol    | Meaning                                 |
| --------- | --------------------------------------- |
| `A`       | The Alien (Player)                      |
| `1-9`     | Zombies                                 |
| `^ v < >` | Arrows (change direction, +20 Attack)   |
| `h`       | Health Pack (+20 HP, max 100)           |
| `p`       | Pod (deals 10 damage to nearest Zombie) |
| `r`       | Rock (reveals object, blocks Alien)     |

### 3. Game Commands

* `help` → Display the guide.
* `up`, `down`, `left`, `right` → Move the Alien.
* `arrow` → Change an arrow's direction by entering its row, column, and new direction (`up`, `down`, `left`, `right`).
* `save` → Save the game to a file.
* `load` → Load a saved game from a file.
* `quit` → Exit the game.

### 4. Game Flow

* The game alternates turns:

  * **Alien's Turn** → Slide until stopped by a wall, rock, or zombie. Attack damage is **accumulated temporarily** and resets after the turn.
  * **Zombies' Turn** → Each living zombie moves one step and attacks if the Alien is within range.
* **Zombie attack range** is **dynamic**: it scales with the board size to ensure fair challenge.
* The game ends when:

  * All Zombies are defeated → **You win!**
  * The Alien's HP reaches zero → **You lose!**

## 📜 Progress Log

* [Part 1](PART1.md)
* [Part 2](PART2.md)

## 👥 Contributors

* **SIDDIQ FERHAD BIN KHAIRIL ANUAL**
* **MUHAMMAD RINO FRAWIDYA BIN SUHERI**
* **LING CHEE XIANG**

---

🚀 *Enjoy the game and feel free to contribute!*
