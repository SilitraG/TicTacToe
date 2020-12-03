// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int matrix[3][3], check = 0;
char User1Character, User2Character;
string name1, name2;

int WinCheck()
{
    //check for lines

    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == 1 && matrix[i][1] == 1 && matrix[i][2] == 1)
            return 1;
        else
            if (matrix[i][0] == 10 && matrix[i][1] == 10 && matrix[i][2] == 10)
                return 2;
    }

    //check for column

    for (int j = 0; j < 3; j++)
    {
        if (matrix[0][j] == 1 && matrix[1][j] == 1 && matrix[2][j] == 1)
            return 1;
        else
            if (matrix[0][j] == 10 && matrix[1][j] == 10 && matrix[2][j] == 10)
                return 2;
    }

    //check for both diagonal

    if (matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1)
        return 1;
    else
        if (matrix[0][0] == 10 && matrix[1][1] == 10 && matrix[2][2] == 10)
            return 2;
        else
            if (matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1)
                return 1;
            else
                if (matrix[0][2] == 10 && matrix[1][1] == 10 && matrix[2][0] == 10)
                    return 2;

    //check for tie

    for (int i = 0;i < 3;i++)
    {
        for (int j = 0;j < 3;j++)
        {
            if (matrix[i][j] == 0)
                return 0;
        }
    }

    return 3;
}
void ModelDraw()
{
    int ok = 1;

    cout << "During the game, you will have a matrix model in which you can see the positions available for the placement of " << User1Character << ".\n\n";
    cout << "Patience is the key to anything.\nChoose wisely!\n\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
                cout << ok;
            else
                cout << char(255);

            ok++;

            if (j < 2)
                cout << char(179);
        }
        if (i < 2)
            cout << "\n" << char(196) << char(197) << char(196) << char(197) << char(196);
        cout << "\n";
    }
}

void Draw()
{
    if(WinCheck() != 2 || WinCheck() != 1 || WinCheck() != 3)
        ModelDraw();

    cout << "\n\nThe whole action is below, don't miss it!\n\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == 0)
                cout << char(255);
            else
                if (matrix[i][j] == 1)
                    cout << User1Character;
                else
                    cout << User2Character;
            if (j < 2)
                cout << char(179);
        }
        if (i < 2)
            cout << "\n" << char(196) << char(197) << char(196) << char(197) << char(196);
        cout << "\n";
    }
}

void PutCharInMatrix(char MoveIndex, bool option)
{
    int ok = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (ok == int(MoveIndex) - 48)
            {
                if (matrix[i][j] == 0)
                {
                    if (option == 0)
                        matrix[i][j] = 1;
                    else
                        matrix[i][j] = 10;
                }
                else
                {
                    check = 1;
                }
            }

            ok++;
        }
    }
}
int AvoidMistakeMove(int option)
{
    for (int i = 0; i < 3; i++)
    {
        if ((matrix[i][0] + matrix[i][1] + matrix[i][2]) == option * 2)
        {
            if (matrix[i][0] == 0)
                return i * 3 + 1;
            else
                if(matrix[i][1] == 0)
                    return i * 3 + 2;
                else
                    if(matrix[i][2] == 0)
                        return i * 3 + 3;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        if ((matrix[0][j] + matrix[1][j] + matrix[2][j]) == option * 2)
        {
            cout << "*";
            if (matrix[0][j] == 0)
                return 0 * 3 + j + 1;
            else
                if (matrix[1][j] == 0)
                    return 1 * 3 + j + 1;
                else
                    if (matrix[2][j] == 0)
                        return 2 * 3 + j + 1;
        }
    }

    if ((matrix[0][0] + matrix[1][1] + matrix[2][2]) == option * 2)
    {
        if (matrix[0][0] == 0)
            return 1;
        else
            if (matrix[1][1] == 0)
                return 5;
            else
                if (matrix[2][2] == 0)
                    return 9;
    }
    else
    {
        if ((matrix[0][2] + matrix[1][1] + matrix[2][0]) == option * 2)
        {
            if (matrix[0][2] == 0)
                return 3;
            else
                if (matrix[1][1] == 0)
                    return 5;
                else
                    if (matrix[2][0] == 0)
                        return 7;
        }
    }
    return 0;
}

void PlayerMove()
{
    char MoveIndex[256];
    int ok = 1;
    cout << "\nInsert one number from 0 to 9 for your " << User2Character << " position.\n";

    cin >> MoveIndex;
    cin.get();

    system("cls");

    if ((int(MoveIndex[0]) < 49) || (int(MoveIndex[0]) > 57) || (strlen(MoveIndex) > 1))
    {
        cout << "\nYou insert the wrong character, try again!\n\n";

        system("pause");
        getchar();
        system("cls");

        Draw();
        PlayerMove();
    }
    else
        PutCharInMatrix(MoveIndex[0], 0);
}
void EasyComputerMove()
{
    int random;
    
    random = rand() % 8 + 49;

    PutCharInMatrix(random,1);

}
void HardComputerMove()
{
    int position;

    position = AvoidMistakeMove(10);
   // cout << '\n' << position <<" for win!" <<  '\n';
    if (position != 0)
        PutCharInMatrix(position + 48, 1);
    else
    {
        position = AvoidMistakeMove(1);
       // cout << '\n' << position << " for lose!" << '\n';
        if (position != 0)
        {
            PutCharInMatrix(position + 48, 1);
        }
    }
    
}
void SecondPlayerMove()
{
    char MoveIndex[256];
    int ok = 1;
    cout << "\nInsert one number from 0 to 9 for your " << User2Character << " position.\n";

    cin >> MoveIndex;
    cin.get();

    system("cls");

    if ((int(MoveIndex[0]) < 49) || (int(MoveIndex[0]) > 57) || (strlen(MoveIndex) > 1))
    {
        cout << "\nYou insert the wrong character, try again!\n\n";

        system("pause");
        getchar();
        system("cls");

        Draw();
        SecondPlayerMove();
    }
    else
        PutCharInMatrix(MoveIndex[0], 1);
}
void ChoseXorO()
{
    cout << "\nWhat character do you choose between 'X' and 'O'?\n";

    cin >> User1Character;
    system("cls");

    if (User1Character == 'X' || User1Character == 'x')
    {
        User1Character = 'X';
        User2Character = 'O';
    }
    else
    {
        if (User1Character == 'O' || User1Character == 'o')
        {
            User1Character = 'O';
            User2Character = 'X';
        }
        else
        {
            cout << "\nYou insert the wrong character, try again!\n\n";

            system("pause");
            getchar();
            system("cls");

            ChoseXorO();
        }
    }
}

void EasyMode()
{
    cout << "You select Single Player Easy.\nGood luck!\n\n";
    ChoseXorO();
    while (1)
    {
        Draw();
        PlayerMove();

        while (check == 1)
        {
            cout << "\nIt is already a character entered in that position, please try another.\n\n";

            system("pause");
            getchar();
            system("cls");

            check = 0;
            Draw();
            PlayerMove();
            
        }

        if (WinCheck() == 1)
        {
            cout << "\nCongratulations, you won this game!!\n";

            system("pause");
            getchar();
            system("cls");

            break;
        }
        else
        {
            if (WinCheck() == 3)
            {
                cout << "\nIt's a tie!!";

                system("pause");
                getchar();
                system("cls");

                break;
            }
        }

        EasyComputerMove();
        while (check == 1)
        {
            check = 0;
            EasyComputerMove();
        }

        if (WinCheck() == 2)
        {
            Draw();
            cout << "\nUnfortunately you lost this game...\n";

            system("pause");
            getchar();
            system("cls");

            break;
        }
        else
        {
            if (WinCheck() == 3)
            {
                cout << "\nIt's a tie!!\n";

                system("pause");
                getchar();
                system("cls");

                break;
            }
        }
    }
}

void HardMode()
{
    cout << "You select Single Player Hard.\nGood luck, you'll need this.\n\n";

    ChoseXorO();

    PutCharInMatrix('1', 1);
    Draw();

    PlayerMove();
    while (check == 1)
    {
        cout << "\nIt is already a character entered in that position, please try another.\n\n";

        system("pause");
        getchar();
        system("cls");

        check = 0;
        Draw();
        PlayerMove();

    }
    Draw();

    PutCharInMatrix('9', 1);
    if (check == 1)
    {
        check = 0;
        PutCharInMatrix('7', 1);
        Draw();

        PlayerMove();
        while (check == 1)
        {
            cout << "\nIt is already a character entered in that position, please try another.\n\n";

            system("pause");
            getchar();
            system("cls");

            check = 0;
            Draw();
            PlayerMove();

        }
        Draw();

        PutCharInMatrix('3', 1);
        if (check == 1)
        {
            check = 0;
            HardComputerMove();
        }
    }
    
    while (1)
    {
        Draw();
        PlayerMove();

        while (check == 1)
        {
            cout << "\nIt is already a character entered in that position, please try another.\n\n";

            system("pause");
            getchar();
            system("cls");

            check = 0;
            Draw();
            PlayerMove();

        }

        if (WinCheck() == 3)
        {
            cout << "\nIt's a tie!!";

            system("pause");
            getchar();
            system("cls");

            break;
        }

        HardComputerMove();
        while (check == 1)
        {
            check = 0;
            HardComputerMove();
        }

        if (WinCheck() == 2)
        {
            Draw();
            cout << "\nUnfortunately you lost this game...\n";

            system("pause");
            getchar();
            system("cls");

            break;
        }
        else
        {
            if (WinCheck() == 3)
            {
                cout << "\nIt's a tie!!\n";

                system("pause");
                getchar();
                system("cls");

                break;
            }
        }
    }
}

int Multiplayer()
{

    cout << "You select Multyplayer.\nGood luck for both of you\n\n";

    cout << "Insert Player1 nickname:\n";
    cin >> name1;
    cout << "\nInsert Player2 nickname:\n";
    cin.get();
    cin >> name2;
    cout << "\n";
    ChoseXorO();
    
    while (1)
    {
        Draw();

        cout << "\n" << name1 << "'s turn!";

        PlayerMove();

        while (check == 1)
        {
            cout << "\nIt is already a character entered in that position, please try another.\n\n";

            system("pause");
            getchar();
            system("cls");

            check = 0;
            Draw();
            PlayerMove();

        }

        Draw();

        if (WinCheck() == 1)
        {
            cout << "\nCongratulations "<< name1 <<", you won this game!!\n";

            system("pause");
            getchar();
            system("cls");

            return 1;

            break;
        }
        else
        {
            if (WinCheck() == 3)
            {
                cout << "\nIt's a tie!!\n";

                system("pause");
                getchar();
                system("cls");

                break;
            }
        }

        cout << "\n" << name2 << "'s turn!";

        SecondPlayerMove();
        while (check == 1)
        {
            cout << "\nIt is already a character entered in that position, please try another.\n\n";

            system("pause");
            getchar();
            system("cls");

            check = 0;
            Draw();
            SecondPlayerMove();
        }

        if (WinCheck() == 2)
        {
            Draw();
            cout << "\nCongratulations " << name2 << ", you won this game!!\n";

            system("pause");
            getchar();
            system("cls");

            return 0;

            break;
        }
        else
        {
            if (WinCheck() == 3)
            {
                cout << "\nIt's a tie!!\n";

                system("pause");
                getchar();
                system("cls");

                break;
            }
        }
    }
}

void GameMode()
{
    char val;
    cout << "Welcome! This is the main menu of the Tic Tac Toe game\nPress 'q' if you want to exit.\n";
    cout << "\n1.Single Player Easy\n";
    cout << "2.Single Player Hard\n";
    cout << "3.Multiplayer\n";
    cout << "\nPlease select which gamemode you want to play?\n";
    cout << "Insert '1' '2' or '3'\n";

    cin >> val;
    system("cls");
    switch (val)
    {
        case '1':
            EasyMode();
            break;
        case '2':
            HardMode();
            break;
        case '3':
            Multiplayer();
            break;
        case 'q':
            break;
        default:
            cout << "You insert the wrong number\n\n";

            system("pause");
            getchar();
            system("cls");

            GameMode();
            break;

    };
}

int main()
{
    char exit;
    while (1)
    {
        GameMode();
        system("cls");
        cout << "Do you want to leave this game?\n'Y' for Yes or any key for No.\n\n";
        cin >> exit;

        if (exit == 'Y' || exit == 'y')
            return 0;
        else
        {
            system("pause");
            getchar();
            system("cls");
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
