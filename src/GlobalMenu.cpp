//
// Created by Jordan on 07/12/2017.
//

#include "../headers/GlobalMenu.hpp"

// Constructors
GlobalMenu::GlobalMenu() {
    listofChoices = {
            {1, "See the current partition"},
            {2, "Change the partition tempo"},
            {3, "Import a partition from a .txt file"},
            {4, "Export the current partition in a .txt file"},
            {5, "Play the current partition"},
            {6, "Play with the keyboard"},
            {0, "Quit"}
    };
}

// Returns the attribute "choice"
int GlobalMenu::getChoice() const {
    return choice;
}

// Sets a value for the attribute "choice"
void GlobalMenu::setChoice(int choice) {
    GlobalMenu::choice = choice;
}

// Shows all the choices of the attribute "listofChoices"
void GlobalMenu::displayChoices() {
    std::cout << "----------------------------------------" << std::endl;
    for(std::map<int, std::string>::iterator it = listofChoices.begin(); it != listofChoices.end(); ++it) {
        std::cout << "Type " << it->first << " : " << it->second << std::endl;
    }
}

// Asks the user to set a value for the attribute "choice"
void GlobalMenu::askForChoice() {
    int newChoice;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Type your choice : ";

    while(!(std::cin >> newChoice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid data type! Try again : ";
    }

    choice = newChoice;

}