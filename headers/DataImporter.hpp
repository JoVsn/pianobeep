//
// Created by Jordan on 21/11/2017.
//

#ifndef PROJET_DATAIMPORTER_HPP
#define PROJET_DATAIMPORTER_HPP

#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include "Partition.hpp"

class DataImporter {

public:

    // Constructors
    DataImporter();

    // Imports a partition from a .txt file
    Partition importPartition(std::string filePath);

private:
};


#endif //PROJET_DATAIMPORTER_HPP
