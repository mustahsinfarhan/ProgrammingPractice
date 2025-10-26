#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main()
{
    char playAgain;

    do
    {
        char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
        char player = ' ';
        char computer = ' ';
        bool running = true;

        do
        {
            std::cout << "Choose your marker -> X or O: ";
            std::cin >> player;
            player = std::toupper(player);

        } while (player != 'X' && player != 'O');

        if (player == 'X')
        {
            computer = 'O';
        }
        else
        {
            computer = 'X';
        }

        std::cout << "You chose marker: " << player << std::endl;

        drawBoard(spaces);

        while (running)
        {
            playerMove(spaces, player);
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer))
            {
                running = false;
                break;
            }
            else if (checkTie(spaces))
            {
                running = false;
                break;
            }

            computerMove(spaces, computer);
            drawBoard(spaces);
            if (checkWinner(spaces, player, computer))
            {
                running = false;
                break;
            }
            else if (checkTie(spaces))
            {
                running = false;
                break;
            }
        }

        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> playAgain;
        playAgain = std::toupper(playAgain);

    } while (playAgain == 'Y');

    std::cout << "Thanks for playing!" << std::endl;
       
    return 0;
}

void drawBoard(char *spaces)
{
    std::cout << "\n";
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "\n";

}

void playerMove(char *spaces, char player)
{
    int number;
    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
        
    }while(!number > 0 || !number < 8);

}

void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));

    while(true)
    {
        number = rand() % 9;
        if(spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}

bool checkWinner(char *spaces, char player, char computer)
{
    char winner = ' ';
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
    {
        winner = spaces[0];
    }
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
    {
        winner = spaces[3];
    }
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
    {
        winner = spaces[6];
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
    {
        winner = spaces[0];
    }
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
    {
        winner = spaces[1];
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
    {
        winner = spaces[2];
    }
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
    {
        winner = spaces[0];
    }
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
    {
        winner = spaces[2];
    }
    else
    {
        return false;
    }

    winner == player ? std::cout << "YOU WIN! \n" : std::cout << "YOU LOSE! \n";
    return true;
}

bool checkTie(char *spaces)
{
    for(int i = 0; i < 9; i++)
    {
        if(spaces[i] == ' ')
        {
            return false;
        }
    }

    std::cout << "IT'S A TIE!" << std::endl;
    return true;
}
