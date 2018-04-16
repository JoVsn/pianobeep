//
// Created by Jordan on 01/12/2017.
//

#ifndef PROJET_PIANO_HPP
#define PROJET_PIANO_HPP

#include "Instrument.hpp"

class Piano : public Instrument {

public:

    // Constructors
    Piano();

    Piano(const std::string &name);

    // Converts the Note given in parameter into a frenquency (Hz) from its name and its octave value
    double convertNameToFrequency(const Note &note) override;

    // Shows the name of the instrument
    void printName() override;

private:

};


#endif //PROJET_PIANO_HPP
