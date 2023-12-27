#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"
#include "MerkelMain.h"


int main()
    {   
        // class that represents the app which instantiates the main application class
        // this is the entry point to the application - public interface
        MerkelMain app{};
        // call the init method of the class
        app.init();

    };

