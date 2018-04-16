//
// Created by Jordan on 28/11/2017.
//

#include "../headers/Instrument.hpp"

// Constructors
Instrument::Instrument() {}

Instrument::Instrument(const std::string &name) : name(name) {}

// Returns the attribute "name"
const std::string &Instrument::getName() const {
    return name;
}

// Sets a value for the attribute "name"
void Instrument::setName(const std::string &name) {
    Instrument::name = name;
}

// Converts the Note given in parameter into a duration (seconds) from its value and with tempo taken in count
template<typename T>
float Instrument::convertNoteValToDuration(const Note &note, T tempo) {
    if (tempo == 0)
        throw std::domain_error("Division by 0, be careful and try to change the tempo value");
    else if (tempo < 0)
        throw std::range_error("The tempo can't be negative, be careful and try to change the tempo value");
    else {
        std::string valeur = note.getValeur();
        for (unsigned int i = 0; i < valeur.size(); i++)
            std::tolower(valeur.at(i));

        int pointee = note.getPointee();
        float val;

        if (valeur == "noire" || valeur == "n") {
            val = 60.f / tempo;
        }
        else if (valeur == "croche" || valeur == "c")  {
            val = 60.f / tempo / 2.f;
        }
        else if (valeur == "double-croche" || valeur == "dc") {
            val = 60.f / tempo / 4.f;
        }
        else if (valeur == "blanche" || valeur == "b") {
            val = 60.f / tempo * 2.f;
        }
        else if (valeur == "ronde" || valeur == "r")  {
            val = 60.f / tempo * 4.f;
        }

        if (pointee) {
            val += val / 2.f;
        }
        return val;
    }
}

// Plays the Note given in parameter
template <typename T>
void Instrument::playNote(Note &note, T tempo) {
    if (note.getNom() >= 'A' && note.getNom() <= 'G') {
        try {
            Beep(convertNameToFrequency(note), convertNoteValToDuration(note, tempo) * 1000); // Time is in millisecond
        }
        catch(std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    else {
        try {
            Beep(0, convertNoteValToDuration(note, tempo) * 1000); // Time is in millisecond
        }
        catch(std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }

}

// Plays the Notes contained in the partition given in parameter
void Instrument::play(Partition &partition) {
    int i;
    for(i = 0; i < partition.getNotes().size(); i++) {
        playNote(*partition.getNotes().at(i), partition.getTempo());
    }
}

// Shows the name of the instrument
void Instrument::printName() {
    std::cout << "Hey, I'm an instrument !" << std::endl;
}