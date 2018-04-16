//
// Created by Jordan on 06/12/2017.
//

#include "../headers/Guitar.hpp"

// Constructors
Guitar::Guitar() {}

Guitar::Guitar(const std::string &name) : Instrument(name) {}

// Converts the Note given in parameter into a frenquency (Hz) from its name and its octave value
double Guitar::convertNameToFrequency(const Note &note) {
    int noteOctave = note.getOctave() + 2; // The Guitar is meant to have a higher pitch
    return note.calculateFrequency(note.getDemiTons(), noteOctave);
}

// Shows the name of the instrument
void Guitar::printName() {
    std::cout << "Hey, I'm a guitar ! Let's play !" << std::endl;
}
