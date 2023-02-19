// *********************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Year: Trimester 1, 2022/23 (T2215)
// Lab: T10L
// Names: MUHAMMAD RINO FRAWIDYA BIN SUHERI | LING CHEE XIANG | SIDDIQ FERHAD BIN KHAIRIL ANUAL
// IDs: 1211103423 | 1201102548 | 1211103095
// Emails: 1211103423@student.mmu.edu.my | 1201102548@student.mmu.edu.my | 1211103095@student.mmu.edu.my
// Phones: 011-2336 8808 | 011-2003 4667 | 016-7493662
// *********************************************************

#include <iostream>
#include <iomanip>
#include <cctype>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class board
{
public:
    void gameboard(int rows, int columns, int zombie);
    void commands(int rows, int columns, int zombie);
    void changesetting(int rows, int columns, int numofzombie);
    void gameboard2(int rows, int columns, int numofzombie);
    void movement(int posx, int posy);
    void obsRock();
    void pod(int rows, int columns, int numofzom);
    // void zombieDies();
    void randTrail(int rows, int columns);
    int alienX, alienY;
    int numofobj;
    void saveGame(int posx, int posy, int numofzom);
    void changearrowdirection();

private:
    vector<vector<char>> field;
    int rows, columns;
};

int posx, posy;
int zombielabell[9];
int zombiehp[9];
int zombieattackk[9];
int zombierangee[9];
int zombiesX[10], zombiesY[10];
int numofzom;
int zombnum;
int alienhp = 100;
int alienattackk = 0;
int num = 1;
class alien
{
public:
    void alienattributes();
    void alienhealth();
    void alienatk();
};

class zombies
{
public:
    void zombieattributes(int numofzom);
    void updatezombies(int numofzom);
    void zombieMove(int rows, int columns, int numofzom);
    // void zombieDies();
private:
    int zombielabel, zombielife, zombieattack, zombierange;
};

void alien::alienattributes()
{
    cout << "-------------------------------------------------" << endl;
    cout << "Alien:" << setw(12) << "Life=> " << alienhp << "  Attack=> " << alienattackk << endl;
}

void board::saveGame(int posx, int posy, int numofzom)
{
    string filename;
    cout << "Enter the file name to save the current game => ";
    cin >> filename;
    ofstream outfile;
    outfile.open(filename);
    outfile << posx << " " << posy << " " << numofzom << endl;
    // Save the alien attributes
    outfile << alienhp << " " << alienattackk << endl;
    // Save the zombie attributes
    for (int i = 0; i < numofzom; i++)
    {
        outfile << zombielabell[i] << " " << zombiehp[i] << " " << zombieattackk[i] << " " << zombierangee[i] << endl;
    }
    outfile.close();
    cout << "-----------------------" << endl;
    cout << "Game saved successfully" << endl;
    cout << "-----------------------" << endl;
    cout << "Please enter to continue..." << endl;
    cin.ignore();
    cin.ignore();
}

void board::movement(int posx, int posy)
{
    alien a;
    zombies b;
    if (field[posx][posy] == '^')
    {
        field[posx][posy] = '.';
        swap(field[posx - 1][posy], field[posx - 2][posy]);
        field[posx][posy] = '.';
        alienattackk += 20;
        cout << "Alien have add 20 attack" << endl;
        a.alienatk();
        cout << "Please enter to continue..." << endl;
        cin.ignore();
    }
    else if (field[posx][posy] == 'v')
    {
        field[posx][posy] = '.';
        swap(field[posx + 1][posy], field[posx + 2][posy]);
        field[posx][posy] = '.';
        alienattackk += 20;
        cout << "Alien have add 20 attack" << endl;
        a.alienatk();
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        cin.ignore();
    }
    else if (field[posx][posy] == '<')
    {
        field[posx][posy] = '.';
        swap(field[posx][posy - 1], field[posx][posy - 2]);
        field[posx][posy] = '.';
        alienattackk += 20;
        cout << "Alien have add 20 attack" << endl;
        a.alienatk();
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        cin.ignore();
    }
    else if (field[posx][posy] == '>')
    {
        field[posx][posy] = '.';
        swap(field[posx][posy + 1], field[posx][posy + 2]);
        field[posx][posy] = '.';
        alienattackk += 20;
        cout << "Alien have add 20 attack" << endl;
        a.alienatk();
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        cin.ignore();
    }
    else if (field[posx][posy] == 'h')
    {
        field[posx][posy] = '.';
        a.alienatk();
        a.alienhealth();
    }
    else if (field[posx][posy] == 'p')
    {
        field[posx][posy] = '.';
        a.alienatk();
        pod(rows, columns, numofzom);
    }
    else if (field[posx][posy] == 'r')
    {
        field[posx][posy] = '.';
        obsRock();
        a.alienatk();
    }
    else if (field[posx][posy] == ' ')
    {
        field[posx][posy] = '.';
        a.alienatk();
    }
    else if (field[posx][posy] == '1')
    {
        zombiehp[0] = zombiehp[0] -= alienattackk;
        a.alienatk();
        if (zombiehp[0] <= 0)
        {
            cout << "Zombie 1 has been defeated" << endl;
            zombiehp[0] = 0;
            field[posx][posy] = ' ';
        }
    }
    else if (field[posx][posy] == '2')
    {
        zombiehp[1] = zombiehp[1] -= alienattackk;
        a.alienatk();
        if (zombiehp[1] <= 0)
        {
            cout << "Zombie 2 has been defeated" << endl;
            zombiehp[1] = 0;
            field[posx][posy] = ' ';
        }
    }
    else if (field[posx][posy] == '3')
    {
        zombiehp[2] = zombiehp[2] -= alienattackk;
        a.alienatk();
        if (zombiehp[2] <= 0)
        {
            cout << "Zombie 3 has been defeated" << endl;
            zombiehp[2] = 0;
            field[posx][posy] = ' ';
        }
    }
    else if (field[posx][posy] == '4')
    {
        zombiehp[3] = zombiehp[3] -= alienattackk;
        a.alienatk();
        if (zombiehp[3] <= 0)
        {
            cout << "Zombie 4 has been defeated" << endl;
            zombiehp[3] = 0;
            field[posx][posy] = ' ';
        }
    }

    else if (field[posx][posy] == '5')
    {
        zombiehp[4] = zombiehp[4] -= alienattackk;
        a.alienatk();
        if (zombiehp[4] <= 0)
        {
            cout << "Zombie 5 has been defeated" << endl;
            zombiehp[4] = 0;
            field[posx][posy] = ' ';
        }
    }
    else if (field[posx][posy] == '6')
    {
        zombiehp[5] = zombiehp[5] -= alienattackk;
        a.alienatk();
        if (zombiehp[5] <= 0)
        {
            cout << "Zombie 6 has been defeated" << endl;
            zombiehp[5] = 0;
            field[posx][posy] = ' ';
        }
    }
    else if (field[posx][posy] == '7')
    {
        zombiehp[6] = zombiehp[6] -= alienattackk;
        a.alienatk();
        {
            cout << "Zombie 7 has been defeated" << endl;
            zombiehp[6] = 0;
            field[posx][posy] = ' ';
        }
    }
    else if (field[posx][posy] == '8')
    {
        zombiehp[7] = zombiehp[7] -= alienattackk;
        a.alienatk();
        if (zombiehp[7] <= 0)
        {
            cout << "Zombie 8 has been defeated" << endl;
            zombiehp[7] = 0;
            field[posx][posy] = ' ';
        }
    }
    else if (field[posx][posy] == '9')
    {
        zombiehp[8] = zombiehp[8] -= alienattackk;
        a.alienatk();
        if (zombiehp[8] <= 0)
        {
            cout << "Zombie 9 has been defeated" << endl;
            zombiehp[8] = 0;
            field[posx][posy] = ' ';
        }
    }
}

void board::obsRock()
{
    alien a;
    char objects[] = {'h', 'p', ' '};
    int noofobj = sizeof(objects) / sizeof(objects[0]);

    srand(time(NULL));

    char objnew = objects[rand() % noofobj];

    if (objnew == 'h')
    {
        cout << "Alien found a health pack" << endl;
        a.alienhealth();
    }
    else if (objnew == 'p')
    {
        cout << "Alien found a pod" << endl;
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        pod(rows, columns, numofzom);
    }
    else
    {
        cout << "Nothing under the rock" << endl;
    }
}

void board::pod(int rows, int columns, int numofzom)
{
    int i, minDistance = 99, minDisIndex = 0, distance;
    for (i = 0; i < numofzom; i++)
    {
        distance = (abs(zombiesX[i] - rows) + abs(zombiesY[i] - columns));
        if (minDistance > distance)
        {
            minDistance = distance;
            minDisIndex = i;
        }
    }

    if (minDisIndex != -1)
    {
        cout << "Zombie " << minDisIndex + 1 << " is closest to the pod. It receives 10 damage.\n\n";
        zombiehp[minDisIndex] -= 10;
    }
    else
    {
        cout << "No zombie found near the pod.\n\n";
    }
}

void board::randTrail(int rows, int columns)
{
    char randObj[] = {'r', 'h', 'p', '<', '>', 'v', '^', ' '};
    int numofobj = 8;
    char c = randObj[rand() % numofobj];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (field[i][j] == '.')
            {
                field[i][j] = c;
            }
        }
    }
}

void alien::alienhealth()
{
    cout << "Alien found a health pack" << endl;

    if (alienhp + 20 > 100)
    {
        cout << "Alien already full of life" << endl;
        cout << "No changes!!" << endl;
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        alienhp = 100;
    }
    else
    {
        alienhp = alienhp + 20;
        cout << "Alien have add 20 life" << endl;
        cout << "Please enter to continue..." << endl;
        cin.ignore();
    }
}

void alien::alienatk()
{
    cout << "Alien have been attacked!" << endl;
    if (alienhp - 10 < 0)
    {
        cout << "Alien is dead!" << endl;
        cout << "<< GAME OVER >>" << endl;
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        exit(0);
    }
    else
    {
        alienhp = alienhp - 10;
        cout << "Alien has lost 10 life." << endl;
    }
}

void zombies::updatezombies(int numofzom)
{
    alien a;
    a.alienattributes();
    for (int n = 0; n < numofzom; ++n)
    {
        cout << "Zombie" << zombielabell[n] << ":  "
             << "Life=> " << zombiehp[n] << setw(12) << "Attack=> " << zombieattackk[n] << setw(12) << "Range=> " << zombierangee[n] << endl;
    }
    cout << "-------------------------------------------------" << endl;
}

void zombies::zombieattributes(int numofzom)
{
    cout << endl;
    for (int m = 0; m < numofzom; ++m)
    {
        // Randomly assign zombie life,attack and range
        zombielabel = m + 1;
        zombielife = rand() % 200 + 100;
        zombieattack = rand() % 15 + 5;
        zombierange = rand() % 5 + 1;
        zombielabell[m] = zombielabel;
        zombiehp[m] = zombielife;
        zombieattackk[m] = zombieattack;
        zombierangee[m] = zombierange;
    }
    updatezombies(numofzom);
}

void zombies::zombieMove(int numofzom, int rows, int columns)
{
    cout << "------------------------------" << endl;
    cout << "Zombie " << num << " turn" << endl;
    for (int i = 0; i < numofzom; i++)
    {
        int direction = rand() % 4; // 0: up, 1: down, 2: left, 3: right
        int dx = 0;
        int dy = 0;
        if (direction == 0 && zombiesX[i] > 0) // up
        {
            dx = -1;
        }
        else if (direction == 1 && zombiesX[i] < rows - 1) // down
        {
            dx = 1;
        }
        else if (direction == 2 && zombiesY[i] > 0) // left
        {
            dy = -1;
        }
        else if (direction == 3 && zombiesY[i] < columns - 1) // right
        {
            dy = 1;
        }
        zombiesX[i] += dx;
        zombiesY[i] += dy;
    }
    cout << endl;
    cout << "Zombie " << num << " turn end" << endl;

    num = num + 1;
    if (num > 4)
    {
        num = 1;
    }
}

void help()
{
    // display user guide
    cout << "----------------------" << endl;
    cout << "Command" << endl;
    cout << "--------" << endl;
    cout << "1) up => Move up" << endl;
    cout << "2) down => Move down" << endl;
    cout << "3) left => Move left" << endl;
    cout << "4) right => Move right" << endl;
    cout << "5) arrow => Change any arrow's direction" << endl;
    cout << "6) help => Show the user's command" << endl;
    cout << "7) save => Save the game" << endl;
    cout << "8) load => Load the game" << endl;
    cout << "9) quit => Quit the game" << endl;
    cout << "----------------------" << endl;
}

// To display the gameboard
void board::gameboard2(int rows, int columns, int zombie)
{
    cout << endl;
    system("CLS");
    cout << setw(5);
    for (int i = 0; i < rows; ++i)
    {
        cout << "+-";
    }
    cout << "+" << endl;

    // Print the grid with your specified characters
    for (int i = 0; i < columns; ++i)
    {
        cout << setw(2) << i + 1 << setw(2);
        for (int j = 0; j < rows; ++j)
        {
            cout << "|";
            cout << field[i][j];
        }
        cout << "|" << endl
             << setw(5);

        for (int i = 0; i < rows; ++i)
        {
            cout << "+-";
        }
        cout << "+" << endl;
    }
    cout << "   ";
    for (int i = 1; i <= rows; ++i)
    {
        int colnum;
        colnum = (i) / 10;
        cout << " ";
        if (colnum == 0)
            cout << "0";
        else
            cout << colnum;
    }
    cout << endl;
    cout << "   ";
    for (int p = 1; p <= rows; ++p)
    {
        int m;
        m = p % 10;
        cout << " " << m;
    }
    cout << endl;
}

// to assign value to gameboard
void board::gameboard(int rows, int columns, int numofzom)
{
    srand(time(NULL));
    char characters[] = {' ', '^', 'v', '>', '<', 'h', 'p', 'r', ' '};

    // calculate the middle row and column
    int middleRow = (rows - 1) / 2;
    int middleColumn = (columns - 1) / 2;

    field.resize(columns);
    for (int i = 0; i < columns; ++i)
    {
        field[i].resize(rows); // resize each row
    }

    // array to store the coordinates of the zombies
    int zombiesX[10], zombiesY[10];

    // randomly assign the zombie on the board
    for (int i = 0; i < numofzom; i++)
    {
        zombiesX[i] = rand() % rows;
        zombiesY[i] = rand() % columns;
    }

    int numofobject = 9;
    // Print the grid with your specified characters
    for (int i = 0; i < columns; ++i)
    {

        for (int j = 0; j < rows; ++j)
        {
            int no = rand() % numofobject;
            // modulo operator to cycle through the characters array
            field[i][j] = characters[no];
            char c = characters[rand() % numofobject];
            field[i][j] = c;

            for (int k = 0; k < numofzom; k++)
            {
                if (i == zombiesX[k] && j == zombiesY[k])
                {
                    field[i][j] = k + 1 + '0';
                }
            }
        }
    }
    int m;
    int n;
    m = (rows - 1) / 2;
    n = (columns - 1) / 2;
    field[n][m] = 'A';
    board::gameboard2(rows, columns, numofzom);
}

void board::commands(int rows, int columns, int zombie)
{
    zombies z;
    alien a;
    cout << "--------------------------------------------------" << endl;
    string command;
    cout << "Please enter command => ";
    cin >> command;
    int posx, posy;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (field[i][j] == 'A')
            {
                posx = i;
                posy = j;
                break;
            }
        }
    }
    if (command == "help")
    {
        help();
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        cin.ignore();
        gameboard2(rows, columns, zombie);
        z.updatezombies(zombie);
        cout << endl;
        commands(rows, columns, zombie);
    }
    else if (command == "quit")
    {
        cout << "Thank you for playing the game. Bye Bye";
        // Terminate the game
        exit(0);
    }
    else if (command == "save")
    {
        saveGame(rows, columns, zombie);
        gameboard2(rows, columns, zombie);
        z.updatezombies(zombie);
        cout << endl;
        commands(rows, columns, zombie);
    }
    else if (command == "load")
    {
        int rows = 0, columns = 0, zombie = 0;
        string filename;
        cout << "Enter the file name to load => ";
        cin >> filename;
        ifstream saveFile(filename);
        if (saveFile.is_open())
        {
            saveFile >> rows >> columns >> zombie >> alienhp >> alienattackk;
            for (int i = 0; i < zombie; i++)
            {
                saveFile >> zombielabell[i] >> zombiehp[i] >> zombieattackk[i] >> zombierangee[i];
            }
            saveFile.close();
            cout << "------------------------" << endl;
            cout << "Game loaded successfully" << endl;
            cout << "------------------------" << endl;
            cout << "Please enter to continue..." << endl;
            cin.ignore();
            cin.ignore();
            gameboard(rows, columns, zombie);
            z.updatezombies(zombie);
            cout << endl;
            commands(rows, columns, zombie);
        }
        else
        {
            cout << "--------------------------------------------------" << endl;
            cout << "Oops! File doesn't exist." << endl;
            commands(rows, columns, zombie);
        }
    }
    else if (command == "up" && posx > 0)
    {
        swap(field[posx][posy], field[posx - 1][posy]);
        movement(posx, posy);
        gameboard2(rows, columns, zombie);
        randTrail(rows, columns);
        z.updatezombies(zombie);
        cout << endl;
        z.zombieMove(numofzom, rows, columns);
        cin.ignore();
        commands(rows, columns, zombie);
    }
    else if (command == "down" && posx < rows - 1)
    {
        swap(field[posx][posy], field[posx + 1][posy]);
        movement(posx, posy);
        gameboard2(rows, columns, zombie);
        randTrail(rows, columns);
        z.updatezombies(zombie);
        cout << endl;
        z.zombieMove(numofzom, rows, columns);
        cin.ignore();
        commands(rows, columns, zombie);
    }
    else if (command == "left" && posy > 0)
    {
        swap(field[posx][posy], field[posx][posy - 1]);
        movement(posx, posy);
        gameboard2(rows, columns, zombie);
        randTrail(rows, columns);
        z.updatezombies(zombie);
        cout << endl;
        z.zombieMove(numofzom, rows, columns);
        cin.ignore();
        commands(rows, columns, zombie);
    }
    else if (command == "right" && posy < columns - 1)
    {
        swap(field[posx][posy], field[posx][posy + 1]);
        movement(posx, posy);
        gameboard2(rows, columns, zombie);
        randTrail(rows, columns);
        z.updatezombies(zombie);
        cout << endl;
        z.zombieMove(numofzom, rows, columns);
        cin.ignore();
        commands(rows, columns, zombie);
    }
    else if (command == "arrow")
    {
        changearrowdirection();
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        cin.ignore();
        gameboard2(rows, columns, zombie);
        z.updatezombies(zombie);
        cout << endl;
        commands(rows, columns, zombie);
    }
    else
    {
        cout << "--------------------------------------------------" << endl;
        cout << "Please enter correctly!!!" << endl;
        commands(rows, columns, zombie);
    }
}

void board::changearrowdirection()
{
    cout << "------------------------------------------------------------------" << endl;
    cout << "Please enter the row,column and direction(up,down,left,right)=>";
    int findrow, findcolumn;
    string changedirection;
    cin >> findrow;
    cin >> findcolumn;
    cin >> changedirection;

    if (changedirection == "up" || changedirection == "down" || changedirection == "left" || changedirection == "right")
    {
        cout << endl;
    }
    else
    {
        cout << "For direction,please only enter either up or down or left or right!!!";
        cout << "Please try it again" << endl
             << endl;
        changearrowdirection();
    }

    char kl = field[findcolumn - 1][findrow - 1];

    if (kl == '^' || kl == 'v' || kl == '<' || kl == '>')
    {
        cout << "The arrow is " << kl << endl;

        if (changedirection == "up")
        {
            field[findcolumn - 1][findrow - 1] = '^';
            cout << "The arrow after changes is " << '^' << endl;
        }
        else if (changedirection == "down")
        {
            field[findcolumn - 1][findrow - 1] = 'v';
            cout << "The arrow after changes is " << 'v' << endl;
        }
        else if (changedirection == "left")
        {
            field[findcolumn - 1][findrow - 1] = '<';
            cout << "The arrow after changes is " << '<' << endl;
        }
        else if (changedirection == "right")
        {
            field[findcolumn - 1][findrow - 1] = '>';
            cout << "The arrow after changes is " << '^' << endl;
        }
    }
    else
    {
        cout << "--------------------------------------------------------------------------------" << endl;
        cout << "The arrow doesn't exist at the row and column that you enter.Please try again!" << endl;
        board::changearrowdirection();
    }
}

void board::changesetting(int rows, int columns, int numofzombie)
{
    zombies z;
    cout << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Please enter the odd number that larger than 1 for row and column that prefered!!!" << endl;
    cout << "Please enter numbers of zombie less than 8 !!!" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Number of row => ";
    cin >> rows;
    cout << "Number of column => ";
    cin >> columns;
    int zombie;
    cout << "Number of zombie => ";
    cin >> zombie;
    if (rows % 2 == 0 || columns % 2 == 0 || zombie > 7)
    {
        cout << endl
             << "*Please enter again:(Take note: Only enter odd number that larger than 1 and enter number less than 8 for zombie)" << endl;
        changesetting(rows, columns, zombie);
    }
    else
    {
        cout << endl;
        gameboard(rows, columns, zombie);
        z.zombieattributes(zombie);
        commands(rows, columns, zombie);
    }
}

int main()
{
    cout << endl;
    cout << "|>>>>>>>>>>>>>>>>>>AvsZ<<<<<<<<<<<<<<<<<<|" << endl;
    cout << "|                                        |" << endl;
    cout << "<-------Welcome to Alien Vs Zombie------->" << endl;
    cout << "|                                        |" << endl;
    cout << "|>>>>>>>>>>>>>>>>>>>__<<<<<<<<<<<<<<<<<<<|" << endl
         << endl;
    cout << "Press Enter To Continue . . . .";
    cin.ignore();
    cout << "--------------------" << endl;
    cout << "Default game setting" << endl;
    cout << "--------------------" << endl;
    int rows, columns, zombie;
    char deci;
    cout << "Rows => 7" << endl;
    cout << "Columns => 7" << endl;
    cout << "Zombie => 5" << endl;
    cout << "Do you want to change the settings (y or n)?=> ";
    cin >> deci;
    // tolower() to convert input to lowercase
    char finaldeci = tolower(deci);
    // define array of characters

    board r1;
    zombies z;
    if (finaldeci == 'n')
    {
        rows = 7;
        columns = 7;
        int zombie = 5;

        r1.gameboard(rows, columns, zombie);
        z.zombieattributes(zombie);

        r1.commands(rows, columns, zombie);
    }
    else if (finaldeci == 'y')
    {
        r1.changesetting(rows, columns, zombie);
    }
    else
    {
        cout << "Please enter correctly!!!" << endl;
        main();
    }
}
