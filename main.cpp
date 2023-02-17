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
    void AZattributes(int numofzom);
    void commands(int rows, int columns, int zombie);
    void changesetting(int rows, int columns, int numofzombie);
    void gameboard2(int rows,int columns,int numofzombie); 
    
private:
    vector<vector<char>>field;
    int rows, columns;
};

void help()
{
    //display user guide
    cout<<"----------------------"<<endl;
    cout<<"Command"<<endl;
    cout<<"--------"<<endl;
    cout<<"1) up => Move up"<<endl;cout<<"2) down => Move down"<<endl;cout<<"3) left => Move left"<<endl;cout<<"4) right => Move right"<<endl;
    cout<<"5) help => Show the user's command"<<endl;cout<<"6) save => Save the game"<<endl;cout<<"7) load => Load the game"<<endl;cout<<"8) quit=> Quit the game"<<endl;
    cout<<"----------------------"<<endl;
}

//To display the gameboard
void board::gameboard2(int rows,int columns,int zombie)
{
    cout<<endl;
    
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
    cout <<"   ";
    for (int i = 1; i <= rows; ++i)
    {
        int colnum;
        colnum=(i)/10;
        cout<<" ";
        if (colnum==0)
            cout<<"0";
        else
            cout << colnum;
    }
    cout<<endl;
    cout <<"   ";
    for(int p=1;p<=rows;++p)
    {

        int m;
        m=p%10;
        cout<<" "<<m;
    }
    cout<<endl;
}

//to assign value to gameboard
void board::gameboard(int rows, int columns, int numofzom)
{
    srand(time(NULL));
    char characters[] = {' ', '^', 'v', '>', '<', 'h', 'p', 'r', ' '};

    //calculate the middle row and column
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
            char c = characters[rand() % 8];
            field[i][j] = c;
            if (i == middleRow && j == middleColumn)
            {
                field[i][j] = 'A';
            }
            for (int k = 0; k < numofzom; k++)
            {
                if (i == zombiesX[k] && j == zombiesY[k])
                {
                    field[i][j] = k + 1 + '0';
                }
            }
        }
        
    }
    board::gameboard2(rows,columns,numofzom);
}

void board::AZattributes(int numofzom)
{
    cout << endl;
    int alienhp=100;
    int alienattack=0;
    int zombielife;
    int zombieattack;
    int range;
    //Create some array to store data of zombie
    int nameofzom[numofzom];
    int lifeofzom[numofzom];
    int attackofzom[numofzom];
    int rangeofzom[numofzom];
    cout << "-------------------------------------------------" << endl;
    cout << "Alien:" << setw(12) << "Life=> " << alienhp << "  Attack=> " << alienattack << endl;
    for (int m = 1; m < numofzom + 1; ++m)
    {
        //Randomly assign zombie life,attack and range
        zombielife = rand() % 200 + 100;
        zombieattack = rand() % 15 + 5;
        range = rand() % 5 + 1;
        cout << "-------------------------------------------------" << endl;
        //Display zombie number of life,attack and range
        cout << "Zombie" << m << ":  "
             << "Life=> " << zombielife << setw(12) << "Attack=> " << zombieattack << setw(12) << "Range=> " << range << endl;
       //Save the data in array
        nameofzom[m] = {m};
        lifeofzom[m] = {zombielife};
        attackofzom[m] = {zombieattack};
        rangeofzom[m] = {range};
    }
}

void board::commands(int rows, int columns, int zombie)
{
    cout << "--------------------------------------------------" << endl;
    string command;
    cout << "Please enter command => ";
    cin >> command;
    int posx, posy;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
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
        AZattributes(zombie);
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
        string filename;
        cout << "Enter the file name to save the current game => ";
        cin >> filename;
        ofstream saveFile(filename);
        saveFile << rows << " " << columns << " " << zombie << endl;
        saveFile.close();
        cout << "-----------------------" << endl;
        cout << "Game saved successfully" << endl;
        cout << "-----------------------" << endl;
        cout << "Please enter to continue..." << endl;
        cin.ignore();
        cin.ignore();
        gameboard2(rows, columns, zombie);
        AZattributes(zombie);
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
            saveFile >> rows >> columns >> zombie;
            saveFile.close();
            cout << "------------------------" << endl;
            cout << "Game loaded successfully" << endl;
            cout << "------------------------" << endl;
            cout << "Please enter to continue..." << endl;
            cin.ignore();
            cin.ignore();
            gameboard(rows, columns, zombie);
            AZattributes(zombie);
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
        gameboard2(rows, columns, zombie);
        AZattributes(zombie);
        cout << endl;
        commands(rows, columns, zombie);
    }
    else if (command == "down" && posx < rows - 1)
    {
        swap(field[posx][posy], field[posx + 1][posy]);
        gameboard2(rows, columns, zombie);
        AZattributes(zombie);
        cout << endl;
        commands(rows, columns, zombie);
    }
    else if (command == "left" && posy > 0)
    {
        swap(field[posx][posy], field[posx][posy - 1]);
        gameboard2(rows, columns, zombie);
        AZattributes(zombie);
        cout << endl;
        commands(rows, columns, zombie);
    }
    else if (command == "right" && posy < columns - 1)
    {
        swap(field[posx][posy], field[posx][posy + 1]);
        gameboard2(rows, columns, zombie);
        AZattributes(zombie);
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

void board::changesetting(int rows, int columns, int numofzombie)
{
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
        AZattributes(zombie);
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
    if (finaldeci == 'n')
    {
        rows = 7;
        columns = 7;
        int zombie = 5;

        r1.gameboard(rows, columns, zombie);
        r1.AZattributes(zombie);

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
