//
// Created by Jordan on 21/11/2017.
//

#ifndef PROJET_NOTE_HPP
#define PROJET_NOTE_HPP

#include <iostream>
#include <cmath>
#include <string>

class Note {

public:

    // Constructors
    Note(char nom);

    Note(char nom, int octave);

    Note(char nom, int octave, char alteration);

    Note(char nom, int octave, char alteration, const std::string &valeur, int pointee);

    // Returns the attribute "nom"
    char getNom() const;

    // Sets the attribute "nom"
    void setNom(char nom);

    // Returns the attribute "octave"
    int getOctave() const;

    // Sets the attribute "octave"
    void setOctave(int octave);

    // Returns the attribute "alteration"
    char getAlteration() const;

    // Sets the attribute "alteration"
    void setAlteration(char alteration);

    // Returns the attribute "valeur"
    const std::string &getValeur() const;

    // Sets the attribute "valeur"
    void setValeur(const std::string &Valeur);

    // Returns the attribute "pointee"
    int getPointee() const;

    // Sets the attribute "pointee"
    void setPointee(const int pointee);

    // Calculates the frequency of the Note (Hz) with the demi-tons and octave given in parameters
    double calculateFrequency(const int nbDemiTons, int octave) const;

    /* Gets the demi-tons to get the right frequency basis for
     * Note with the A3 taken in reference, with the name and alteration given in parameters
     */
    int getDemiTons() const;

    // Shows the complete name of a Note
    std::string getCompleteString();

private:
    char nom;
    int octave;
    char alteration;
    std::string valeur;
    int pointee;
};


#endif //PROJET_NOTE_HPP
