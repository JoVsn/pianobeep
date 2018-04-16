//
// Created by Jordan on 21/11/2017.
//

#include "../headers/DataImporter.hpp"

// Constructors
DataImporter::DataImporter() {}

// Import a partition from a .txt file
Partition DataImporter::importPartition(std::string filePath){
    Partition myPartition;

    std::ifstream myFile(filePath.c_str(), std::ios::in);
    int i;

    if (myFile) {
        std::string currentLine;
        int line = 0;
        while(getline(myFile, currentLine)) { // We read the whole file
            std::string token;

            if (line == 0) { // We get the tempo
                token = currentLine.substr(0, currentLine.size());
                int tempo = std::stoi(token);
                myPartition.setTempo(tempo);
            }
            else {
                size_t pos = 0;
                std::string delimiter = " - ";

                char nom;
                int octave;
                char alteration;
                std::string valeur;
                int pointee = 0;

                i = 0;

                while ((pos = currentLine.find(delimiter)) != std::string::npos) { // We find each value separated by the delimiter ", "

                    token = currentLine.substr(0, pos);

                    switch (i) {
                        case 0:
                            nom = token.at(0);
                            octave = token.at(1) - '0'; // Convertion string to int
                            if (token.size() == 3) { // If there is an alteration on the Note
                                if (token.at(2) != 'd' && token.at(2) != 'b')
                                    alteration = '\0';
                                else
                                    alteration = token.at(2);
                            }
                            break;
                        case 1:
                            valeur = token;
                            break;
                        default:
                            break;
                    }
                    currentLine.erase(0, pos + delimiter.length()); // we remove the part we don't want
                    i++;
                }
                token = currentLine.substr(0, pos); // We take the last value after the " - " delimiter
                if (token.at(0) != 'p')
                    pointee = 0;
                else
                    pointee = 1;

                // We create a new Note Object and add it to the Partition
                Note *note = new Note(nom, octave, alteration, valeur, pointee);
                myPartition.addNote(note);
                alteration = '\0';
            }
            line++;
        }

        myFile.close();

        std::cout << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Partition : imported" << std::endl;
    }
    else
        std::cerr << "The file " << filePath << " can't be opened !" << std::endl;
    return myPartition;
}