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

        if (input == "exit"){ break; }

        cout << db.execute(input) << endl;
    }
    db.save();

    return 0;
}