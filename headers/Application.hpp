//
// Created by Jordan on 21/11/2017.
//

#ifndef PROJET_APPLICATION_HPP
#define PROJET_APPLICATION_HPP

#include <iostream>
#include "GlobalMenu.hpp"
#include "Partition.hpp"
#include "KeyboardPlayer.hpp"
#include "Piano.hpp"
#include "Guitar.hpp"
#include "Bass.hpp"
#include "DataImporter.hpp"
#include "DataExporter.hpp"
#include "functions.hpp"

class Application {

public:

    // Constructors
    Application();

    // Shows the full music sheet of the current application
    void displayPartition(Partition &);

    // Changes the current partition tempo
    void changePartitionTempo(Partition &);

    // Imports a partition from a .txt file in the current application
    void importPartition(Partition &);

    // Exports the current application partition in a .txt file
    void exportPartition(Partition &);

    // Plays the current music sheet
    void playPartition(Partition &);

    // Plays an Instrument by pressing the keyboard keys
    void playOnKeyboard();

    // Launches the main application
    void launchApplication();

};


#endif //PROJET_APPLICATION_HPP
