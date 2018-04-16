//
// Created by Jordan on 28/11/2017.
//

#ifndef PROJET_INSTRUMENT_HPP
#define PROJET_INSTRUMENT_HPP

#include <iostream>
#include <exception>
#include "Partition.hpp"

class Instrument {

public:

    // Constructors
    Instrument();

    Instrument(const std::string &name);

    // Returns the attribute "name"
    const std::string &getName() const;

    // Sets a value for the attribute "name"
    void setName(const std::string &name);

    /* Converts the Note given in parameter into a frequency (Hz) from its name and its octave value
     * This method is abstract
     */
    virtual double convertNameToFrequency(const Note &note) = 0;

    // Converts the Note given in parameter into a duration (seconds) from its value and with tempo taken in count
    template<typename T>
    float convertNoteValToDuration(const Note &note, T tempo);

    // Plays the Note given in parameter
    template <typename T>
    void playNote(Note &note, T tempo);

    // Plays the Notes contained in the partition given in parameter
    virtual void play(Partition &partition);

    // Shows the name of the instrument
    virtual void printName();

protected:
    std::string name;

};


#endif //PROJET_INSTRUMENT_HPP
