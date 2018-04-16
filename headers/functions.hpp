//
// Created by Jordan on 09/12/2017.
//

#ifndef PROJET_FUNCTIONS_HPP
#define PROJET_FUNCTIONS_HPP

#include <iostream>
#include <exception>
#include <regex>
#include <sstream>
#include <string>
#include "Partition.hpp"

/* Allows to fuse two partitions objects.
 * Be careful, the tempo depends on the first partition, not on the second one
 */
Partition operator+(Partition, Partition);

#endif //PROJET_FUNCTIONS_HPP
