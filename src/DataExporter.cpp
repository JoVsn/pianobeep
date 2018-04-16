//
// Created by Jordan on 21/11/2017.
//

#include "../headers/DataExporter.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

// Constructors
DataExporter::DataExporter() {}

// Export a partition in a .txt file
void DataExporter::exportPartition(std::string filePath, Partition myPartition) {

    std::ofstream myFile(filePath.c_str(), std::ios::out);
    int i;

    if (myFile) {
        std::cout << "File opened" << std::endl;
        myFile << myPartition.getTempo() << std::endl; // We put the tempo on the first line of the .txt file
        for(i = 0; i < myPartition.getNotes().size(); i++) { // We export each entry of our partition in the .txt file
            myFile << myPartition.getNotes().at(i)->getCompleteString() << std::endl;
        }
        myFile.close();

        std::cout << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Partition : exported" << std::endl;
    }
    else
        std::cerr << "The file " << filePath << " can't be opened !" << std::endl;
}