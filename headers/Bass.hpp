//
// Created by Jordan on 01/12/2017.
//

#ifndef PROJET_BASS_HPP
#define PROJET_BASS_HPP

#include "Instrument.hpp"

class Bass : public Instrument {

public:

    // Constructors
    Bass();

    Bass(const std::string &name);

    // Converts the Note given in parameter into a frenquency (Hz) from its name and its octave value
    double convertNameToFrequency(const Note &note) override;

    // Shows the name of the instrument
    void printName() override;

private:

};


#endif //PROJET_BASS_HPP
