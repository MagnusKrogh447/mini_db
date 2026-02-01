#include <iostream>

#include "db/Database.h"

using namespace std;

int main() {
    Database db;
    string input;

    cout << "MiniDB has started. Type ¨exit¨ to quit. \n";

    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "exit") {
            db.save();
            break;
        }

        cout << db.execute(input) << endl;
    }

    return 0;
}