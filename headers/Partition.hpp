//
// Created by Jordan on 21/11/2017.
//

#ifndef PROJET_PARTITION_HPP
#define PROJET_PARTITION_HPP

#include <iostream>
#include <vector>
#include <windows.h>
#include <cmath>
#include <string>
#include "Note.hpp"

class Partition {

public:

    // Constructors
    Partition();

    Partition(int tempo);

    // Returns the attribute "tempo"
    int getTempo() const;

    // Sets the attribute "tempo"
    void setTempo(int tempo);

    // Adds a note to the notes vector
    void addNote(Note *note);

    // Returns the attribute "notes"
    std::vector<Note*> getNotes() const;

    // Sets the attribute "notes"
    void setNotes(const std::vector<Note*> &vector);

    // Shows all the notes contained in the notes vector
    void showNotes();

    // Deletes all the notes contained in the notes vector from the memory
    void deleteNotes();


private:
    int tempo;
    std::vector<Note*> notes;

};

#endif //PROJET_PARTITION_HPP
