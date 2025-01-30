#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

bool isBoardFull(std::string game_table[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_table[i][j] == " ") return false;
        }
    }
    return true;
}

const int winning_combinations[8][3] = {
    {1, 2, 3}, {4, 5, 6}, {7, 8, 9},
    {1, 4, 7}, {2, 5, 8}, {3, 6, 9},
    {1, 5, 9}, {3, 5, 7}
};

bool checkWin(std::string game_table[3][3], std::string sign) {
    for (int i = 0; i < 8; i++) {  
        int row1 = (winning_combinations[i][0] - 1) / 3;
        int col1 = (winning_combinations[i][0] - 1) % 3;
        int row2 = (winning_combinations[i][1] - 1) / 3;
        int col2 = (winning_combinations[i][1] - 1) % 3;
        int row3 = (winning_combinations[i][2] - 1) / 3;
        int col3 = (winning_combinations[i][2] - 1) % 3;

        if (game_table[row1][col1] == sign && 
            game_table[row2][col2] == sign && 
            game_table[row3][col3] == sign) {
            return true;
        }
    }
    return false;
}

int main() {
    std::string computer_sign, player_sign;
    int move = 0;

    while (true) {
        std::cout << "Would you like to be X or 0? ";
        std::getline(std::cin, player_sign);

        if (player_sign == "X") { 
            computer_sign = "0";
            break;
        } else if (player_sign == "0") {
            computer_sign = "X";
            break;
        } else {
            std::cout << "Incorrect input. Please choose X or 0.\n";
        }
    }

    std::cout << "\nMove positions (preview):\n";
    std::cout << " 1 | 2 | 3 \n";
    std::cout << "---+---+---\n";
    std::cout << " 4 | 5 | 6 \n";
    std::cout << "---+---+---\n";
    std::cout << " 7 | 8 | 9 \n\n";

    std::string game_table[3][3] = {
        {" ", " ", " "},
        {" ", " ", " "},
        {" ", " ", " "},
    };

    while (true) {
        std::cout << "Where would you like to put your sign? Choose 1-9: ";
        std::cin >> move;

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (game_table[row][col] == " ") {
            game_table[row][col] = player_sign;
        } else {
            std::cout << "That space is already taken! Try again.\n";
            continue;
        }
        
        if (checkWin(game_table, player_sign)) {
            std::cout << "You won!\n";
            break;
        }

        srand(time(0));
        std::vector<int> possible_moves;

        for (int i = 1; i <= 9; i++) {
            int r = (i - 1) / 3;
            int c = (i - 1) % 3;
            if (game_table[r][c] == " ") {
                possible_moves.push_back(i);
            }
        }

        if (!possible_moves.empty()) {
            int computer_move = possible_moves[rand() % possible_moves.size()];
            int comp_row = (computer_move - 1) / 3;
            int comp_col = (computer_move - 1) % 3;
            game_table[comp_row][comp_col] = computer_sign;
        }

        if (checkWin(game_table, computer_sign)) {
            std::cout << "Computer won!\n";
            break;
        }

        if (isBoardFull(game_table)) {
            std::cout << "It's a draw!\n";
            break;
        }
        
        std::cout << "\nUpdated board:\n";
        for (int i = 0; i < 3; i++) {
            std::cout << " " << game_table[i][0] << " | " << game_table[i][1] << " | " << game_table[i][2] << " \n";
            if (i < 2) std::cout << "---+---+---\n";
        }
    }

    return 0;
}
