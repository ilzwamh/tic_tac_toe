#include <iostream>
#include <limits>
#include <ctime> 
using namespace std;

//���������� ������� �����
void PlayingBoard(char board[3][3]) {
    cout << "    1   2   3 \n";
    cout << "  -------------\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " | ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n  -------------\n";
    }
}

//����������� ����������
bool Win(char board[3][3], char player) {
    //�������� ���������� � �����������
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    //�������� ����������
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

void Computer(char board[3][3]) {
    bool flag = false, flag1 = false;
    //������� ������������
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == ' ' && flag1 == false) {
            board[i][2] = 'O';
            flag1 = true;
        }
        else if (board[i][0] == 'O' && board[i][2] == 'O' && board[i][1] == ' ' && flag1 == false) {
            board[i][1] = 'O';
            flag1 = true;
        }
        else if (board[i][1] == 'O' && board[i][2] == 'O' && board[i][0] == ' ' && flag1 == false) {
            board[i][0] = 'O';
            flag1 = true;
        }
    }
    //�������� ����������
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == 'O' && board[1][j] == 'O' && board[2][j] == ' ' && flag1 == false) {
            board[2][j] = 'O';
            flag1 = true;
        }
        else if (board[0][j] == 'O' && board[2][j] == 'O' && board[1][j] == ' ' && flag1 == false) {
            board[1][j] = 'O';
            flag1 = true;
        }
        else if (board[1][j] == 'O' && board[2][j] == 'O' && board[0][j] == ' ' && flag1 == false) {
            board[0][j] = 'O';
            flag1 = true;
        }
    }
    //�������� ����������
    if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == ' ' && flag1 == false) {
        board[2][2] = 'O';
        flag1 = true;
    }
    else if (board[0][0] == 'O' && board[2][2] == 'O' && board[1][1] == ' ' && flag1 == false) {
        board[1][1] = 'O';
        flag1 = true;
    }
    else if (board[1][1] == 'O' && board[2][2] == 'O' && board[0][0] == ' ' && flag1 == false) {
        board[0][0] = 'O';
        flag1 = true;
    }

    if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == ' ' && flag1 == false) {
        board[2][0] = 'O';
        flag1 = true;
    }
    else if (board[0][2] == 'O' && board[2][0] == 'O' && board[1][1] == ' ' && flag1 == false) {
        board[1][1] = 'O';
        flag1 = true;
    }
    else if (board[1][1] == 'O' && board[2][0] == 'O' && board[0][2] == ' ' && flag1 == false) {
        board[0][2] = 'O';
        flag1 = true;
    }
    if (flag1 == false) {
        //�������� ������������
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == ' ' && flag == false) {
                board[i][2] = 'O';
                flag = true;
            }
            else if (board[i][0] == 'X' && board[i][2] == 'X' && board[i][1] == ' ' && flag == false) {
                board[i][1] = 'O';
                flag = true;
            }
            else if (board[i][1] == 'X' && board[i][2] == 'X' && board[i][0] == ' ' && flag == false) {
                board[i][0] = 'O';
                flag = true;
            }
        }
        //�������� ����������
        for (int j = 0; j < 3; j++) {
            if (board[0][j] == 'X' && board[1][j] == 'X' && board[2][j] == ' ' && flag == false) {
                board[2][j] = 'O';
                flag = true;
            }
            else if (board[0][j] == 'X' && board[2][j] == 'X' && board[1][j] == ' ' && flag == false) {
                board[1][j] = 'O';
                flag = true;
            }
            else if (board[1][j] == 'X' && board[2][j] == 'X' && board[0][j] == ' ' && flag == false) {
                board[0][j] = 'O';
                flag = true;
            }
        }
        //�������� ����������
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == ' ' && flag == false) {
            board[2][2] = 'O';
            flag = true;
        }
        else if (board[0][0] == 'X' && board[2][2] == 'X' && board[1][1] == ' ' && flag == false) {
            board[1][1] = 'O';
            flag = true;
        }
        else if (board[1][1] == 'X' && board[2][2] == 'X' && board[0][0] == ' ' && flag == false) {
            board[0][0] = 'O';
            flag = true;
        }

        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == ' ' && flag == false) {
            board[2][0] = 'O';
            flag = true;
        }
        else if (board[0][2] == 'X' && board[2][0] == 'X' && board[1][1] == ' ' && flag == false) {
            board[1][1] = 'O';
            flag = true;
        }
        else if (board[1][1] == 'X' && board[2][0] == 'X' && board[0][2] == ' ' && flag == false) {
            board[0][2] = 'O';
            flag = true;
        }
    }
    //��������� ���, ���� ��� ���������� ��� �������, ���� ������
    if (flag == false && flag1 == false) {
        int row, column;
        srand(time(0));
        do {
            row = rand() % 3;
            column = rand() % 3;
        } while (board[row][column] != ' ');

        board[row][column] = 'O';
    }
}