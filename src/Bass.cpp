//
// Created by Jordan on 01/12/2017.
//

#include "../headers/Bass.hpp"

// Constructors
Bass::Bass() {}

Bass::Bass(const std::string &name) : Instrument(name) {}

// Converts the Note given in parameter into a frenquency (Hz) from its name and its octave value
double Bass::convertNameToFrequency(const Note &note) {
    int noteOctave = note.getOctave() - 1; // The Guitar is meant to have a higher pitch
    return note.calculateFrequency(note.getDemiTons(), noteOctave);
}

// Shows the name of the instrument
void Bass::printName() {
    std::cout << "Hey, I'm a bass ! Let's play !" << std::endl;
}
