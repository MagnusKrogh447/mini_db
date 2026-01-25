#include <iostream>

#include "db/Database.h"

int main() {
    Database db;
    std::string input;

    std::cout << "MiniDB has started. Type ¨exit¨ to quit. \n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "exit"){ break; }

        std::cout << db.execute(input) << std::endl;
    }
    return 0;
}