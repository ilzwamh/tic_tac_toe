#include <iostream>
#include <limits>
#include <ctime> 
#include "func.h"
using namespace std;

int main()
{
    setlocale(0, "");
    char board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    char player = 'X';
    int row, column;
    int step;
    float choice;
    cout << "Добро пожаловать в игру 'Крестики - Нолики'!" << endl;
    cout << "С кем хотите поиграть? (1 - компьютер, 2 - второй игрок): ";

    cin >> choice;
    
    while (cin.fail() || choice != 1 && choice != 2) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Неверный противник, попробуйте еще раз (1 - компьютер, 2 - второй игрок): ";
        cin >> choice;
    }
    system("cls");

    cout << "Начнем игру!" << endl;

    //Игра с вторым игроком
    if (choice == 2) {
        for (step = 0; step < 9; step++) {
            PlayingBoard(board);

            cout << "Игрок " << player << ", выберите ячейку (строка от 1 до 3 и столбец от 1 до 3): " << endl;
            cin >> row >> column;
            //Проверка на дурака
            while (cin.fail() || row < 1 || row > 3 || column < 1 || column > 3 || board[row - 1][column - 1] != ' ') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                PlayingBoard(board);
                cout << "Неверный ввод ячейки, необходимо выбрать строку (от 1 до 3) и столбец (от 1 до 3): " << endl;
                cin >> row >> column;
            }

            board[row - 1][column - 1] = player;

            system("cls");

            if (Win(board, player) == true) {
                PlayingBoard(board);
                cout << "Игрок " << player << " выиграл!" << endl;
                step = 9;
            }
            else {
                if (player == 'X') {
                    player = 'O';
                }
                else {
                    player = 'X';
                }
            }
        }
    }
    //Игра с компьютером
    else {
        for (step = 0; step < 9; step++) {
            PlayingBoard(board);
            //Ход игрока
            if (step % 2 == 0) {
                cout << "Игрок, выберите ячейку (строка от 1 до 3 и столбец от 1 до 3): " << endl;
                cin >> row >> column;
                //Проверка на дурака
                while (cin.fail() || row < 1 || row > 3 || column < 1 || column > 3 || board[row - 1][column - 1] != ' ') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("cls");
                    PlayingBoard(board);
                    cout << "Неверный ввод ячейки, необходимо выбрать строку (от 1 до 3) и столбец (от 1 до 3): " << endl;
                    cin >> row >> column;
                }

                board[row - 1][column - 1] = 'X';

                if (Win(board, 'X') == true) {
                    system("cls");
                    PlayingBoard(board);
                    cout << "Игрок выиграл!" << endl;
                    step = 9;
                }
            }
            //Ход компьютера
            else {
                system("cls");

                Computer(board);

                if (Win(board, 'O') == true) {
                    PlayingBoard(board);
                    cout << "Компьютер выиграл!" << endl;
                    step = 9;
                }
            }
        }
    }
    if (!Win(board, 'X') && !Win(board, 'O')) {
        system("cls");
        PlayingBoard(board);
        cout << "Ничья!";
    }
    return 0;
}