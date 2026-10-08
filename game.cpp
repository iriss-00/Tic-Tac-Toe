#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Board print করার function
void printBoard()
{
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  "
         << board[0][1] << "  |  "
         << board[0][2] << "\n";

    cout << "-----+-----+-----\n";

    cout << "  " << board[1][0] << "  |  "
         << board[1][1] << "  |  "
         << board[1][2] << "\n";

    cout << "-----+-----+-----\n";

    cout << "  " << board[2][0] << "  |  "
         << board[2][1] << "  |  "
         << board[2][2] << "\n";

    cout << "     |     |     \n";
}


// Winner check করার function
bool checkWinner()
{
    // Row check
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2])
        {
            return true;
        }
    }

    // Column check
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i])
        {
            return true;
        }
    }

    // Diagonal check
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2])
    {
        return true;
    }

    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0])
    {
        return true;
    }

    return false;
}


// Draw check
bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != 'X' &&
                board[i][j] != 'O')
            {
                return false;
            }
        }
    }

    return true;
}


int main()
{
    char player = 'X';
    int choice;

    cout << "========================\n";
    cout << "      TIC TAC TOE\n";
    cout << "========================\n";

    while (true)
    {
        printBoard();

        cout << "\nPlayer " << player << "'s turn";
        cout << "\nEnter position (1-9): ";
        cin >> choice;

        // Position অনুযায়ী row এবং column
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        // Invalid position
        if (choice < 1 || choice > 9)
        {
            cout << "Invalid position! Try again.\n";
            continue;
        }

        // Already occupied কিনা
        if (board[row][col] == 'X' ||
            board[row][col] == 'O')
        {
            cout << "This position is already taken!\n";
            continue;
        }

        // Player-এর mark বসানো
        board[row][col] = player;

        // Winner check
        if (checkWinner())
        {
            printBoard();

            cout << "\n🎉 Player " << player << " wins!\n";
            break;
        }

        // Draw check
        if (checkDraw())
        {
            printBoard();

            cout << "\nIt's a Draw!\n";
            break;
        }

        // Player change
        if (player == 'X')
        {
            player = 'O';
        }
        else
        {
            player = 'X';
        }
    }

    return 0;
}