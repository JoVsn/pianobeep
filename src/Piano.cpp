//
// Created by Jordan on 01/12/2017.
//

#include "../headers/Piano.hpp"

// Constructors
Piano::Piano() {}

Piano::Piano(const std::string &name) : Instrument(name) {}

// Converts the Note given in parameter into a frenquency (Hz) from its name and its octave value
double Piano::convertNameToFrequency(const Note &note) {
    int noteOctave = note.getOctave(); // The Guitar is meant to have a higher pitch
    return note.calculateFrequency(note.getDemiTons(), noteOctave);
}

// Shows the name of the instrument
void Piano::printName() {
    std::cout << "Hey, I'm a piano ! Let's play !" << std::endl;
}
