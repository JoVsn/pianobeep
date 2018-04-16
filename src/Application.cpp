//
// Created by Jordan on 21/11/2017.
//

#include "../headers/Application.hpp"

// Constructors
Application::Application() {}

// Show the full music sheet of the current application
void Application::displayPartition(Partition &myPartition) {
    myPartition.showNotes();
}

// Change the current partition tempo
void Application::changePartitionTempo(Partition &myPartition) {
    int newTempo;
    std::cout << "------------------------------" << std::endl;
    std::cout << "Current tempo : " << myPartition.getTempo() << std::endl;
    std::cout << "Enter a new value : ";

    while (!(std::cin >> newTempo)) {
        std::cerr << "Enter a valid value please : ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    myPartition.setTempo(newTempo);
    std::cout << "Tempo updated !" << std::endl;
}

// Import a partition from a .txt file in the current application
void Application::importPartition(Partition &myPartition) {
    DataImporter myDataImporter = DataImporter();
    std::string fileName;
    std::cout << "Type the name of the file to import : ";

    std::cin >> fileName;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    char choice;
    // If there is already a partition in our application
    if (!myPartition.getNotes().empty()) {
        do {
            std::cout << "Do you want to delete the current partition ? (y/n) : ";

            std::cin >> choice;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } while (choice != 'y' && choice != 'n');
    }

    std::ifstream myFile(fileName.c_str(), std::ios::in);

    if (myFile) {
        if (choice != 'n')
            myPartition = myDataImporter.importPartition(fileName);
        else if (choice == 'n'){ // If we want to conserve the old partition in the application
            try {
                Partition newPartition = myDataImporter.importPartition(fileName);
                myPartition = myPartition + newPartition;
            }
            catch (const std::exception &e) {
                std::cerr << "Erreur : " << e.what() << std::endl;
            }
        }
    }
    else {
        std::cerr << "The file " << fileName << " can't be opened !" << std::endl;
    }
}

// Export the current application partition in a .txt file
void Application::exportPartition(Partition &myPartition) {
    DataExporter dataExporter;

    DataExporter myDataExporter = DataExporter();
    std::string fileName;
    std::cout << "Type the name of the partition that will be created : ";

    std::cin >> fileName;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    myDataExporter.exportPartition(fileName, myPartition);

}

// Play the current music sheet
void Application::playPartition(Partition &myPartition) {
    Instrument *instrument;
    int choice;
    do {
        std::cout << "Press 1 to play the partition on Piano ; 2 to play the partition on Guitar ; "
                "3 to play the partition on Bass ; "
                "4 to return : ";

        if (!(std::cin >> choice)) {
            std::cerr << "Invalid data type! Try again :";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(choice <= 0 || choice > 4);
    switch(choice) {
        case 1:
            instrument = new Piano("Piano");
            break;
        case 2:
            instrument = new Guitar("Guitar");
            break;
        case 3:
            instrument = new Bass("Bass");
            break;
        case 4:
            return;
        default:
            break;
    }
    instrument->play(myPartition);
}

// Play an Instrument by pressing the keyboard keys
void Application::playOnKeyboard() {
    Instrument *instrument;
    int choice;
    do {
        std::cout << "Type 1 to play with the Piano ; 2 to play with the Guitar ; "
                "3 to play with the Bass ; "
                "4 to return : ";

        if (!(std::cin >> choice)) {
            std::cerr << "Invalid data type! Try again :";
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(choice <= 0 || choice > 4);

    switch(choice) {
        case 1:
            instrument = new Piano("Piano");
            break;
        case 2:
            instrument = new Guitar("Guitar");
            break;
        case 3:
            instrument = new Bass("Bass");
            break;
        case 4:
            return;
        default:
            instrument = new Piano("Piano");
            break;
    }

    int save = 0;
    Partition *partition = new Partition;

    KeyboardPlayer myKb = KeyboardPlayer(*instrument);
    std::string instruction;
    std::cout <<
                "Regular notes : q -> B ; s -> C ; d -> D ; f -> E ; g -> F ; h -> G ; j -> A ; k -> B ; l -> C"
              << std::endl;

    std::cout <<
              "# notes : e -> C# ; r -> D# ; y -> F# ; u -> G# ; i -> A#"
              << std::endl;
    std::cout <<
              "Type 'w' if you want to return to the main menu ; type 'x' if you want to start/stop recording"
              << std::endl <<
                " ; type 'c' if you want to change the tempo"
              << std::endl;
    do {
        instruction = myKb.play();
        if (instruction == "save" && save == 0) {
            save = 1;
            std::cout << "Currently recording ..." << std::endl;
        }
        else if (instruction == "save" && save == 1) {
            save = 0;
            std::cout << "Record stopped ..." << std::endl;
        }
        // If we play a note
        if (save && instruction != "save" && instruction != "") {
            Note* newNote;
            newNote = (myKb.getNote(instruction));
            partition->addNote(newNote);
        }
        if(instruction == "tempo") {
            int newTempo;
            std::cout << "------------------------------" << std::endl;
            std::cout << "Current tempo : " << myKb.getTempo() << std::endl;
            std::cout << "Enter a new value : ";

            while (!(std::cin >> newTempo)) {
                std::cerr << "Invalid data type! Try again :";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            myKb.setTempo(newTempo);
            std::cout << "Tempo updated !" << std::endl;
        }
    } while(instruction != "leave");

    // If we enabled the save option at any time
    if (!partition->getNotes().empty()) {
        DataExporter dataExporter;

        DataExporter myDataExporter = DataExporter();
        std::string fileName;
        std::cout << "Type the name of the partition that will be created : ";

        std::cin >> fileName;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        partition->setTempo(myKb.getTempo());
        myDataExporter.exportPartition(fileName, *partition);
    }
    myKb.deleteNotes();
    delete instrument;
    delete partition;
}

// Launch the main application
void Application::launchApplication() {

    std::cout << "------------------------------" << std::endl;
    std::cout << "Pian'IMAC Player" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << std::endl;

    // Creating the global Menu
    GlobalMenu globalMenu;

    // Creating the different tools
    Partition *partition = new Partition;

    bool launched = true;
    do {
        globalMenu.displayChoices();
        globalMenu.askForChoice();

        switch (globalMenu.getChoice()) {
            case 1:
                Application::displayPartition(*partition);
                break;
            case 2:
                Application::changePartitionTempo(*partition);
                break;
            case 3:
                Application::importPartition(*partition);
                break;
            case 4:
                Application::exportPartition(*partition);
                break;
            case 5:
                Application::playPartition(*partition);
                break;
            case 6:
                Application::playOnKeyboard();
                break;
            case 0:
                launched = false;
                break;
            default:
                break;
        }

    } while (launched);
    std::cout << "------------------------------" << std::endl;
    std::cout << "You quit the program! See you later :)" << std::endl;
    partition->deleteNotes();
    delete partition;
}