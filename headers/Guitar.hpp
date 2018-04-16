//
// Created by Jordan on 06/12/2017.
//

#ifndef PROJET_GUITAR_HPP
#define PROJET_GUITAR_HPP

#include "Instrument.hpp"

class Guitar : public Instrument {

public:

    // Constructors
    Guitar();

    Guitar(const std::string &name);

    // Converts the Note given in parameter into a frenquency (Hz) from its name and its octave value
    double convertNameToFrequency(const Note &note) override;

    // Shows the name of the instrument
    void printName() override;

private:

};


#endif //PROJET_GUITAR_HPP
