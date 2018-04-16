//
// Created by Jordan on 21/11/2017.
//

#include "../headers/Partition.hpp"
#include "../headers/functions.hpp"

// Constructors
Partition::Partition() : tempo(120) {}

Partition::Partition(int tempo) : tempo(tempo) {}

// Returns the attribute "tempo"
int Partition::getTempo() const {
    return tempo;
}

// Sets the attribute "tempo"
void Partition::setTempo(int tempo) {
    Partition::tempo = tempo;
}

// Adds a note to the notes vector
void Partition::addNote(Note *note)  {
    notes.push_back(note);
}

// Returns the attribute "notes"
std::vector<Note*> Partition::getNotes() const {
    return notes;
}

// Sets the attribute "notes"
void Partition::setNotes(const std::vector<Note*> &vector) {
    Partition::notes = vector;
}

// Shows all the notes contained in the notes vector
void Partition::showNotes() {
    std::cout << "Tempo de la partition : " << tempo << std::endl;
    for (unsigned int i = 0; i < notes.size(); i++) {
        std::cout << notes.at(i)->getCompleteString() << std::endl;
    }
}

// Deletes all the notes contained in the notes vector from the memory
void Partition::deleteNotes() {
    for (unsigned int i = 0; i < notes.size(); i++) {
        delete &notes.at(i);
    }
}

