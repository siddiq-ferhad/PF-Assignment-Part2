#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <limits>
#include <iomanip>

using namespace std;

class GameObject {
public:
    char symbol;
    GameObject(char s = ' ') : symbol(s) {}
};

class Character {
public:
    int hp, attack, range;
    int row, col;
    bool isAlive;
    Character(int l = 0, int a = 0, int r = 0, int ro = 0, int co = 0)
        : hp(l), attack(a), range(r), row(ro), col(co), isAlive(true) {}
};

class GameBoard {
private:
    vector<vector<GameObject>> board;
    vector<Character> zombies;
    Character alien;
    int rows, cols, numZombies;
    bool alienTurn;

public:
    GameBoard() : rows(7), cols(7), numZombies(5), alienTurn(true) {
        initializeBoard();
    }

    void initializeBoard() {
        srand(time(0));
        board.assign(rows, vector<GameObject>(cols, GameObject(' ')));
        zombies.clear();
        
        // Place Alien at center
        alien = Character(100, 0, 0, rows / 2, cols / 2);
        board[alien.row][alien.col].symbol = 'A';

        // Place Zombies
        for (int i = 0; i < numZombies; ++i) {
            int zRow, zCol;
            do {
                zRow = rand() % rows;
                zCol = rand() % cols;
            } while (board[zRow][zCol].symbol != ' ' || (zRow == alien.row && zCol == alien.col));
            int maxDimension = max(rows, cols);
            int maxRange = max(1, maxDimension / 2);  // Range is at least 1, or half the board
            int zombieRange = 1 + rand() % maxRange;

            zombies.push_back(Character(50 + rand() % 51, 10 + rand() % 11, zombieRange, zRow, zCol));
            board[zRow][zCol].symbol = '1' + i;
        }

        // Place random game objects
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j].symbol == ' ' && rand() % 3 != 0) { // 66% chance to place an object
                    char objects[] = {'^', 'v', '<', '>', 'h', 'p', 'r'};
                    board[i][j].symbol = objects[rand() % 7];
                }
            }
        }
    }

    void setDimensions() {
        int r, c;
        do {
            cout << "\nEnter number of rows (odd > 1): ";
            cin >> r;
            if (cin.fail() || r % 2 == 0 || r <= 1) {
                cout << "Please enter a valid odd number greater than 1.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        } while (true);
        do {
            cout << "Enter number of columns (odd > 1): ";
            cin >> c;
            if (cin.fail() || c % 2 == 0 || c <= 1) {
                cout << "Please enter a valid odd number greater than 1.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        } while (true);
        rows = r;
        cols = c;
        do {
            cout << "Enter number of zombies (1-9): ";
            cin >> numZombies;

            if (cin.fail() || numZombies < 1 || numZombies > 9) {
                cout << "Please enter a valid number between 1 and 9.\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else break;
        } while (true);
        initializeBoard();
    }

    void displayBoard() {
        int rowLabelWidth = to_string(rows).length();

        // Top border
        cout << "\n" << string(rowLabelWidth + 1, ' ');
        for (int j = 1; j <= cols; ++j) {
            cout << "+---";
        }
        cout << "+\n";

        // Board rows with labels
        for (int i = 0; i < rows; ++i) {
            cout << setw(rowLabelWidth) << (i + 1) << " ";
            for (int j = 0; j < cols; ++j) {
                cout << "| " << board[i][j].symbol << " ";
            }
            cout << "|\n" << string(rowLabelWidth + 1, ' ');
            for (int j = 1; j <= cols; ++j) {
                cout << "+---";
            }
            cout << "+\n";
        }

        // Column numbers
        cout << string(rowLabelWidth + 1, ' ');
        for (int j = 1; j <= cols; ++j) {
            cout << setw(3) << j << " ";
        }
        cout << "\n";

        // Status display
        cout << "\nAlien: HP = " << alien.hp << "\n";
        for (int i = 0; i < numZombies; ++i) {
            if (!zombies[i].isAlive) continue;  // Skip defeated zombies
            cout << "Zombie " << (i + 1) << ": HP = " << zombies[i].hp
                << ", Attack = " << zombies[i].attack << ", Range = " << zombies[i].range
                << "\n";
        }
        cout << "\n";
    }

    bool moveAlien(const string& direction) {
        int dr = 0, dc = 0;
        if (direction == "up") dr = -1;
        else if (direction == "down") dr = 1;
        else if (direction == "left") dc = -1;
        else if (direction == "right") dc = 1;
        else return false;

        vector<pair<int, int>> trail;
        int r = alien.row, c = alien.col;
        trail.push_back({r, c});

        while (true) {
            r += dr;
            c += dc;

            if (r < 0 || r >= rows || c < 0 || c >= cols) {
                cout << "Alien hits the border!\n";
                break;
            }

            char cell = board[r][c].symbol;
            if (cell >= '1' && cell <= '9') {
                int zId = cell - '1';
                if (zombies[zId].isAlive) {
                    zombies[zId].hp -= alien.attack;
                    cout << "Alien attacks Zombie " << (zId + 1) << " for " << alien.attack << " damage.\n";
                    if (zombies[zId].hp <= 0) {
                        zombies[zId].isAlive = false;
                        zombies[zId].hp = 0;
                        cout << "Zombie " << (zId + 1) << " is defeated!\n";
                        board[r][c].symbol = ' ';
                        if (isGameOver()) return true; 
                    } else {
                        board[r][c].symbol = cell;
                        break;
                    }
                }
            } else if (cell == 'r') {
                cout << "Alien hits a rock!\n";
                char objects[] = {'^', 'v', '<', '>', 'h', 'p'};
                board[r][c].symbol = objects[rand() % 6];
                cout << "Rock reveals: " << board[r][c].symbol << "\n";
                break;
            } else if (cell == '^' || cell == 'v' || cell == '<' || cell == '>') {
                alien.attack += 20;
                cout << "Alien collects an arrow, attack +20! (Current Attack: " << alien.attack << ")\n";
                if (cell == '^') dr = -1, dc = 0;
                else if (cell == 'v') dr = 1, dc = 0;
                else if (cell == '<') dr = 0, dc = -1;
                else if (cell == '>') dr = 0, dc = 1;
            } else if (cell == 'h') {
                if (alien.hp < 100) {
                    alien.hp += 20;
                    if (alien.hp > 100) {
                        alien.hp = 100;
                        cout << "Alien collects HP, but HP is capped at 100.\n";
                    } else {
                        cout << "Alien collects HP, HP +20!\n";
                    }
                } else {
                    cout << "Alien collects HP, but HP is already full.\n";
                }
            } else if (cell == 'p') {
                int minDist = rows + cols, target = -1;
                for (int i = 0; i < numZombies; ++i) {
                    if (zombies[i].isAlive) {
                        int dist = abs(zombies[i].row - r) + abs(zombies[i].col - c);
                        if (dist < minDist) {
                            minDist = dist;
                            target = i;
                        }
                    }
                }
                if (target != -1) {
                    zombies[target].hp -= 10;
                    cout << "Pod inflicts 10 damage to Zombie " << (target + 1) << "!\n";
                    if (zombies[target].hp <= 0) {
                        zombies[target].isAlive = false;
                        zombies[target].hp = 0;
                        cout << "Zombie " << (target + 1) << " is defeated!\n";
                        board[zombies[target].row][zombies[target].col].symbol = ' ';
                        if (isGameOver()) return true;
                    }
                }
            }

            // Update the trail with '.' and move the alien
            for (auto &pos : trail) {
                board[pos.first][pos.second].symbol = '.';
            }
            // New Alien position
            board[r][c].symbol = 'A';
            alien.row = r;
            alien.col = c;
            trail.push_back({r, c});
        }

        // Reset trails at the end of the turn
        for (size_t i = 0; i < trail.size() - 1; ++i) { // Exclude the current position
            auto& pos = trail[i];
            if (board[pos.first][pos.second].symbol == '.') {
                if (rand() % 3 != 0) { // 66% chance to place an object
                    char objects[] = {'^', 'v', '<', '>', 'h', 'p', 'r'};
                    board[pos.first][pos.second].symbol = objects[rand() % 7];
                } else {
                    board[pos.first][pos.second].symbol = ' ';
                }
            }
        }

        alien.attack = 0; // Reset attack after turn
        alienTurn = false;
        return true;
    }

    void moveZombies() {
        // Skip zombie moves if Alien already dead
        if (alien.hp <= 0) return;

        for (int i = 0; i < numZombies; ++i) {
            if (!zombies[i].isAlive) continue;

            int r = zombies[i].row, c = zombies[i].col;
            char zSymbol = '1' + i;

            // Choose a legal direction, trying up to 4 options
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            int start = rand() % 4;
            bool moved = false;
            for (int t = 0; t < 4; ++t) {
                int dir = (start + t) % 4;
                int newR = r + directions[dir].first;
                int newC = c + directions[dir].second;

                if (newR >= 0 && newR < rows && newC >= 0 && newC < cols &&
                    board[newR][newC].symbol != 'A' &&
                    (board[newR][newC].symbol < '1' || board[newR][newC].symbol > '9')) {
                    // Perform the move
                    board[r][c].symbol = ' ';
                    zombies[i].row = newR;
                    zombies[i].col = newC;
                    board[newR][newC].symbol = zSymbol;
                    cout << "Zombie " << (i + 1) << " moves to ("
                        << (newR + 1) << ", " << (newC + 1) << ").\n";
                    moved = true;
                    break;
                }
            }
            if (!moved) {
                cout << "Zombie " << (i + 1) << " stays in place.\n";
            }

            // Attack after the move (if Alien in range)
            if (abs(zombies[i].row - alien.row) + abs(zombies[i].col - alien.col) <= zombies[i].range) {
                alien.hp -= zombies[i].attack;
                cout << "Zombie " << (i + 1) << " attacks Alien for " << zombies[i].attack << " damage.\n";
                if (alien.hp <= 0) {
                    alien.hp = 0;
                    cout << "Alien is defeated!\n";
                    break;  // Stop zombie attacks immediately
                }
            }
        }
        alienTurn = true;
    }

    bool isGameOver() {
        if (alien.hp <= 0) return true;
        bool allZombiesDefeated = true;
        for (const auto& z : zombies) {
            if (z.isAlive) {
                allZombiesDefeated = false;
                break;
            }
        }
        return allZombiesDefeated;
    }

    bool isAlienDead() {
        return alien.hp <= 0;
    }

    void switchArrow() {
        int r, c;
        cout << "Enter row and column of arrow to switch (e.g., 3 5): ";
        
        if (!(cin >> r >> c)) {  // Check for invalid (non-integer) input
            cout << "Invalid input! Please enter two numbers.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        r--; c--; // Convert to 0-based index

        // Check valid board position and that the cell is an arrow
        if (r < 0 || r >= rows || c < 0 || c >= cols ||
            (board[r][c].symbol != '^' && board[r][c].symbol != 'v' &&
            board[r][c].symbol != '<' && board[r][c].symbol != '>')) {
            cout << "Invalid arrow position.\n";
            return;
        }

        string dir;
        cout << "Enter new direction (up, down, left, right): ";
        cin >> dir;

        char newDir;
        if (dir == "up") newDir = '^';
        else if (dir == "down") newDir = 'v';
        else if (dir == "left") newDir = '<';
        else if (dir == "right") newDir = '>';
        else {
            cout << "Invalid direction. Valid options: up, down, left, right.\n";
            return;
        }

        board[r][c].symbol = newDir;
        cout << "Arrow at (" << (r + 1) << ", " << (c + 1) << ") switched to " << dir << ".\n";
    }

    void saveGame(const string& filename) {
        ofstream outFile(filename);
        if (!outFile) {
            cout << "Error saving game.\n";
            return;
        }
        outFile << rows << " " << cols << " " << numZombies << " " << alienTurn << "\n";
        outFile << alien.hp << " " << alien.attack << " " << alien.row << " " << alien.col << "\n";
        for (const auto& z : zombies) {
            outFile << z.hp << " " << z.attack << " " << z.range << " " << z.row << " " << z.col << " " << z.isAlive << "\n";
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                outFile << board[i][j].symbol << " ";
            }
            outFile << "\n";
        }
        outFile.close();
        cout << "Game saved to " << filename << ".\n";
    }

    bool loadGame(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "Error loading game.\n";
            return false;
        }

        inFile >> rows >> cols >> numZombies >> alienTurn;
        inFile >> alien.hp >> alien.attack >> alien.row >> alien.col;

        zombies.clear();
        for (int i = 0; i < numZombies; ++i) {
            int l, a, r, ro, co;
            bool alive;
            inFile >> l >> a >> r >> ro >> co >> alive;
            zombies.push_back(Character(l, a, r, ro, co));
            zombies.back().isAlive = alive;
        }
        board.assign(rows, vector<GameObject>(cols));

        inFile >> noskipws;
        char ch;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                do { inFile.get(ch); } while (ch == '\n' || ch == '\r');
                board[i][j].symbol = ch;
                inFile.get(ch);
            }
        }
        inFile >> skipws;
        inFile.close();

        cout << "Game loaded from " << filename << ".\n";
        return true;
    }

    void displayHelp() {
        cout << "=== Help Guide ===\n"
            "Commands:\n"
            "  up / down / left / right  -> Move Alien (slides)\n"
            "  arrow                     -> Change an arrow object (^ v < >)\n"
            "  save                      -> Save game\n"
            "  load                      -> Load game\n"
            "  help                      -> Show this guide\n"
            "  quit                      -> Exit the game\n\n"
            "Objects on board:\n"
            "  A        Alien (you)\n"
            "  1-9      Zombies\n"
            "  ^ v < >  Arrows (+20 attack & redirect)\n"
            "  h        Health (+20 HP, max 100)\n"
            "  p        Pod (10 dmg to nearest Zombie)\n"
            "  r        Rock (hides object, stops Alien)\n";
    }
};

string endMessage(GameBoard& game) {
    if (game.isAlienDead()) {
        return "The Alien has been defeated! You lose!";
    } else {
        return "All Zombies have been defeated! You win!";
    }
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}


int main() {
    GameBoard game;
    cout << " >>>>>>>>>>>>>>>>>_AvsZ_<<<<<<<<<<<<<<<<<" << endl;
    cout << "|                                        |" << endl;
    cout << "|       Welcome to Alien vs Zombie       |" << endl;
    cout << "|                                        |" << endl;
    cout << " >>>>>>>>>>>>>>>>>>>__<<<<<<<<<<<<<<<<<<<\n" << endl;

    cout << "Default Settings: Rows = 7, Cols = 7, Zombies = 5\n";
    string changeSettings;

    while (true) {
        cout << "Change settings? (y/n): ";
        cin >> changeSettings;

        if (changeSettings == "y" || changeSettings == "Y") {
            game.setDimensions();
            break;
        } else if (changeSettings == "n" || changeSettings == "N") {
            break;
        } else {
            cout << "Please enter a valid input.\n\n";
        }
    }
    string command;

    while (true) {
        if (!game.isGameOver()) {   // Only display if still playing
            game.displayBoard();
        }

        if (game.isGameOver()) {
            cout << "\n" << endMessage(game) << "\nPlay again? (y/n): ";
            string playAgain;
            cin >> playAgain;
            if (playAgain != "y" && playAgain != "Y") break;

            cout << "\nDefault Settings: Rows = 7, Cols = 7, Zombies = 5\n";
            string changeSettings;

            while (true) {
                cout << "Change settings? (y/n): ";
                cin >> changeSettings;

                if (changeSettings == "y" || changeSettings == "Y") {
                    game.setDimensions();
                    break;
                } else if (changeSettings == "n" || changeSettings == "N") {
                    game = GameBoard();
                    break;
                } else {
                    cout << "Please enter a valid input.\n\n";
                }
            }
            continue;
        }

        if (!game.isGameOver()) {
            cout << "Enter command (type 'help' if unsure): ";
            cin >> command;
            cout << "\n";

            if (command == "up" || command == "down" || command == "left" || command == "right") {
                cout << "========== Alien's Turn ==========\n";
                if (game.moveAlien(command)) {
                    if (!game.isGameOver()) {
                        cout << "\n========== Zombies' Turn ==========\n";
                        game.moveZombies();
                    }
                } else {
                    cout << "Invalid direction.\n";
                }
            } else if (command == "arrow") {
                game.switchArrow();
            } else if (command == "help") {
                game.displayHelp();
                waitForEnter();
            }
            else if (command == "save") {
                string filename;
                cout << "Enter filename to save: ";
                cin >> filename;
                game.saveGame(filename);
            } else if (command == "load") {
                string filename;
                cout << "Enter filename to load: ";
                cin >> filename;
                game.loadGame(filename);
            } else if (command == "quit") {
                break;
            } else {
                cout << "Invalid command. Type 'help' for a list of commands.\n";
            }
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}
