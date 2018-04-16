//
// Created by Jordan on 21/11/2017.
//

#ifndef PROJET_DATAEXPORTER_HPP
#define PROJET_DATAEXPORTER_HPP

#include "Partition.hpp"

class DataExporter {

public:

    // Constructors
    DataExporter();

    // Export a partition in a .txt file
    void exportPartition(std::string filePath, Partition myPartition);

private:
};


#endif //PROJET_DATAEXPORTER_HPP
