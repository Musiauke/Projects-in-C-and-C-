#include <iostream>

void deposit(int& balance){  
    do{
        int deposit;

        std::cout << "How much would you like to deposit?: "; 
        std::cin >> deposit;
            if(deposit > 0){
                balance += deposit;
                break;
            } else {
                std::cout << "Incorrect input please try again \n";
                }
            }while (true);
    
}

void withdrawal(int& balance){
    do{
        int withdrawal;

        std::cout << "How much would like to withdraw? ";
        std::cin >> withdrawal;
            if(withdrawal > 0 || withdrawal > balance){
                balance -= withdrawal;
                break;
            } else {
                std::cout << "Incorrect input please try again ";
                }
    }while (true);
}

void check_balance(int& balance){
    std::cout << "Your balance account is: " << balance << "\n";
}

int main(){
    int balance = 0;
    int choice;

    do {
        std::cout << "\n ******** Bank Account ************ \n";
        std::cout << "Choose action \n 1. Check account balance \n 2. Make a withdrawal \n 3. Make a deposit \n 4. Exit (1-4): ";
        std::cin >> choice;

        switch(choice){
            case 1:
                check_balance(balance);
                break;
            case 2:
                withdrawal(balance);
                break;
            case 3:
                deposit(balance);
                break;
            case 4:
                std::cout << "That's all for today! Goodbye! ";
                break;
            default:
                std::cout << "Invalid choice! Try again \n";
                break;
        }
    } while (choice !=4);
    
    std::cout << "\n******** You closed the app ************ \n";
        
    return 0;
}
