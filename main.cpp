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
using namespace std;
#include <iomanip>
#include <cctype>

void gameboard(int rows, int columns, char characters[8])
{
    // calculate the middle row and column
    int middleRow = rows / 2 + 1;
    int middleColumn = columns / 2 + 1;

    // Seed the random number generator
    srand(time(0));

    // Print top row of "+" and "-"
    cout << setw(4) << " ";
    for (int i = 1; i <= columns; i++)
    {
        cout << "+" << " - ";
    }
    cout << "+" << endl;

    // Print the grid with your specified characters
    for (int i = 1; i <= rows; i++)
    {
        cout << setw(4) << i;
        for (int j = 1; j <= columns; j++)
        {
            //modulo operator to cycle through the characters array
            char c = characters[rand() % 8];
            if ( i== middleRow && j== middleColumn)
            {
                c = 'A';
            }
            cout << "|" << " " << c << " ";
        }
        cout << "|" << endl;

        // Print row of "+" and "-"
        cout << setw(5) << "+";
        for (int j = 1; j <= columns; j++)
        {
            cout << " - " << "+";
        }
        cout << endl;
    }

    // Print column numbers below grid
    cout << setw(5) << " ";
    for (int i = 1; i <= columns; i++)
    {
        cout << setw(2) << i << setw(2) << ' ';
    }
    cout << endl;
}

void changesetting(int rows,int columns,char characters[8])
{
    cout<<endl;
    cout <<  "-------------------------------------------"<<endl;
    cout << "Please enter the odd number that larger than 1 for row and column that prefered!!!"<< endl;
    cout <<  "-------------------------------------------"<<endl;
    cout<< "Number of row=>";
    cin>>rows;
    cout<<"Number of column=>";
    cin>>columns;
    if (rows%2==0||columns%2==0)
    {
        cout<<endl<<"*Please enter again:(Take note: Only enter odd number that larger than 1)"<<endl;
        changesetting(rows, columns, characters);
    }    
    else
    {
        cout<<endl;
        gameboard(rows,columns,characters);
    }
}
int main()
{
    cout<<endl;
    cout << "|>>>>>>>>>>>>>>>>>>AvsZ<<<<<<<<<<<<<<<<<<|"<<endl;
    cout << "|                                        |"<<endl;
    cout << "<-------Welcome to Alien Vs Zombie------->"<<endl;
    cout << "|                                        |"<<endl;
    cout << "|>>>>>>>>>>>>>>>>>>>__<<<<<<<<<<<<<<<<<<<|"<<endl<<endl;
    cout << "Press Enter To Continue . . . .";
    cin.ignore();
    cout <<"--------------------"<<endl;
    cout<< "Default game setting"<<endl;
    cout<< "--------------------"<<endl;
    int rows,columns;
    char deci;
    cout<<"Rows=>7"<<endl;
    cout<<"Columns=>7"<<endl;
    cout<<"Do you want to change the settings (y or n)?=>";
    cin>> deci;
    // tolower() to convert input to lowercase
    char finaldeci=tolower(deci);
    //define array of characters
    char characters[8] = {'^', 'v', '>', '<', 'h', 'p', 'r', ' '};
    if (finaldeci=='n')
    {
        rows=7;
        columns=7;
        gameboard(rows,columns,characters);
    }
    else if (finaldeci=='y')
    {
        changesetting(rows,columns,characters);
    }
    else
    {
        cout<<"Please enter correctly!!!"<<endl;
        main();
    }

    
    //pf::Pause();
}