#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

void rules(int& computer_points, int& player_points) {
    std::string player_move; 
    int computer_move = rand() % 3; 

    do {
        std::cout << "What is your next move? \n";
        std::cout << "Choose P for paper \n"; 
        std::cout << "Choose R for rock \n"; 
        std::cout << "Choose S for scissors \n"; 
        std::cin >> player_move;
            
        if (!player_move.empty()) {
            player_move[0] = tolower(player_move[0]);
        }

        if (player_move != "r" && player_move != "p" && player_move != "s") {
            std::cout << "Invalid input, please try again.\n";
            continue; 
        }

        if ((player_move == "r" && computer_move == 2) ||
            (player_move == "p" && computer_move == 0) ||
            (player_move == "s" && computer_move == 1)) {
            std::cout << "You win this round! +1 point!\n";
            player_points += 1;
        } else if ((player_move == "r" && computer_move == 1) ||
                   (player_move == "p" && computer_move == 2) ||
                   (player_move == "s" && computer_move == 0)) {
            std::cout << "It's a draw! No points.\n";
        } else {
            std::cout << "Computer wins this round! +1 point.\n";
            computer_points += 1;
        }
        break;
    } while (true);
}

int main() {
    srand(time(0));
    int computer_points = 0; 
    int player_points = 0;
    int choice;

    do {
        std::cout << "\n******** Rock Paper Scissors game ************ \n";
        std::cout << "Choose action \n 1. Play \n 2. Exit \n: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                while (player_points < 3 && computer_points < 3) {
                    rules(computer_points, player_points);
                    std::cout << "Score: Player " << player_points << " - Computer " << computer_points << "\n";
                }
                if (player_points == 3) {
                    std::cout << "Congratulations! You won the game!\n";
                } else if (computer_points == 3) {
                    std::cout << "Computer wins the game! Better luck next time!\n";
                }
                break;
            case 2:
                std::cout << "Goodbye! \n";
                break;
            default:
                std::cout << "Invalid choice! Try again \n";
                break;
        }

        std::cout << "Score: Player " << player_points << " - Computer " << computer_points << "\n";

    } while (choice != 2 && player_points < 3 && computer_points < 3);
    
    std::cout << "\n******** You closed the app ************ \n";
    std::cout << "Final Score: Player " << player_points << " - Computer " << computer_points << "\n";
        
    return 0;
}
