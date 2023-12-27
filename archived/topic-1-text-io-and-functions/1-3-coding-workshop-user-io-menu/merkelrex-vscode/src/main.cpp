#include <iostream>

int main()
{
    while(true){
        
        std::cout << "1: Print help" << std::endl;
        std::cout << "2: Print exchange stats" << std::endl;
        std::cout << "3: Place an ask" << std::endl;
        std::cout << "4: Place a bid" << std::endl;
        std::cout << "5: Print wallet" << std::endl;
        std::cout << "6: Go to the next Time Frame" << std::endl;
        std::cout << "7: Exit" << std::endl;


        std::cout << "============================" << std::endl;

        // extraction operator used for input
        std::cout << "Type in 1-6" << std::endl;

        int userOption;
        std::cin >> userOption;
        std::cout << "You chose: " << userOption << std::endl;


        if (userOption == 1){
            std::cout << "Help - choose options from the menu" << std::endl;
            std::cout << "and follow the on screen instructions" << std::endl;
        }
        if(userOption == 2){
            std::cout << "Check ask/bid rates" << std::endl;
            std::cout << "and compare to other exchanges" << std::endl; 
        }
        if(userOption == 3){
            std::cout << "Place an sell call to the exchange" << std::endl;
            std::cout << "and wait for buyers" << std::endl;
        }
        if(userOption == 4){
            std::cout << "Place a bid for your order" << std::endl;
            std::cout << "and wait for sellers" << std::endl;
        }
        if(userOption == 5){
            std::cout << "Cehck your wallet" << std::endl;
            std::cout << "and see how much you have" << std::endl;
        }
        if(userOption == 6){
            std::cout << ">> Go to the next Time Frame" << std::endl;
            std::cout << "and select the next option" << std::endl;
        }
        if(userOption < 1 || userOption > 7){
            std::cout << ">> You have entered an invalid option" << std::endl;
            std::cout << "please try again" << std::endl;
            std::cout << "                                 " << std::endl;
        }
        if (userOption == 7){
                std::cout << "Exiting" << std::endl;
                return 0;
        }   

    }

}

