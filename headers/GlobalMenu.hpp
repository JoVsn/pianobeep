//
// Created by Jordan on 07/12/2017.
//

#ifndef PROJET_GLOBALMENU_HPP
#define PROJET_GLOBALMENU_HPP

#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <exception>
#include "../headers/functions.hpp"

class GlobalMenu {

public:

    // Constructors
    GlobalMenu();

    // Returns the attribute "choice"
    int getChoice() const;

    // Sets a value for the attribute "choice"
    void setChoice(int choice);

    // Shows all the choices of the attribute "listofChoices"
    void displayChoices();

    // Asks the user to set a value for the attribute "choice"
    void askForChoice();

private:
    int choice;
    std::map<int, std::string> listofChoices;
};


#endif //PROJET_GLOBALMENU_HPP
