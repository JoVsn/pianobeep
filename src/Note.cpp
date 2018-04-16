//
// Created by Jordan on 21/11/2017.
//

#include "../headers/Note.hpp"

// Constructors
// We only give the name
Note::Note(char nom) : nom(nom), octave(4), valeur("noire"), pointee(0){
    alteration = '\n';
}

// We only give the name and the octave
Note::Note(char nom, int octave) : nom(nom), octave(octave), valeur("noire"), pointee(0){
    alteration = '\n';
}

// We only give the name, the octave and the alteration
Note::Note(char nom, int octave, char alteration) : nom(nom), octave(octave), alteration(alteration), valeur("noire"), pointee(0){}

// We only give the name and the octave, the alteration, and if the note is "dotted" are not
Note::Note(char nom, int octave, char alteration, const std::string &valeur, int pointee) : nom(nom), octave(octave), alteration(alteration), valeur(valeur), pointee(pointee) {}

// Returns the attribute "nom"
char Note::getNom() const {
    return nom;
}

// Sets the attribute "nom"
void Note::setNom(char nom) {
    Note::nom = nom;
}

// Returns the attribute "octave"
int Note::getOctave() const {
    return octave;
}

// Sets the attribute "octave"
void Note::setOctave(int octave) {
    Note::octave = octave;
}

// Returns the attribute "alteration"
char Note::getAlteration() const {
    return alteration;
}

// Sets the attribute "alteration"
void Note::setAlteration(char alteration) {
    Note::alteration = alteration;
}

// Returns the attribute "valeur"
const std::string &Note::getValeur() const {
    return valeur;
}

// Sets the attribute "valeur"
void Note::setValeur(const std::string &valeur) {
    Note::valeur = valeur;
}

// Returns the attribute "pointee"
int Note::getPointee() const {
    return pointee;
}

// Sets the attribute "pointee"
void Note::setPointee(const int pointee) {
    Note::pointee = pointee;
}

// Calculates the frequency of the Note (Hz) with the demi-tons and octave given in parameters
double Note::calculateFrequency(const int nbDemiTons, int octave) const {
    /*
     * Example :
     * Frequency of A4 = Frequency of A3 * 2
     * Frequency of A5 = Frequency of A4 * 2 = Frequency of A3 * 2 * 2
     *
     * Frequency of A3 = Frequency of A4 / 2
     * Frequency of A2 = Frequency of A3 /2 = Frequency of A4 / 2 / 2
     *
     * Full formula :
     * ANY note Frequency = 440 [Frequency of A3] * (a [1.059463] ^ number of Demi-tons)
     * And we multiply the frequency by a number, depending if the octave is higher or lower
    */

    double a = 1.059463;
    double A3 = 440;
    int pitch = octave - 3; // Because we are based on A3

    if (pitch > 0){ // means the Note has an octave equal or superior to 4, so we need to multiply the frequency
        return A3 * powf(a, nbDemiTons) * pow(2, pitch - 1);
    }
    else if (pitch == 0) { // means the Note has an octave equal to 3, and we start with the 4th octave, so we divide the frequency by two
        return A3 * powf(a, nbDemiTons) / 2.f;
    }
    else { // means the note has an octave inferior to 3, so we need to divide the frequency
        return A3 * powf(a, nbDemiTons) / pow(2, pitch*(-1) + 1);
    }
}

/* Gets the demi-tons to get the right frequency basis for
 * Note with the A3 taken in reference, with the name and alteration given in parameters
 */
int Note::getDemiTons() const {
    // We refer to the A3 Note, and start with the C4 Note (then D4, E4, and so on...)
    int demiTons = 0;
    switch(nom) {
        case 'A': // This is the A4 note, so it is 12 demi-tons after the A3 Note
            demiTons = 12;
            break;
        case 'B': // Same for the other notes...
            demiTons = 14;
            break;
        case 'C':
            demiTons = 3;
            break;
        case 'D':
            demiTons = 5;
            break;
        case 'E':
            demiTons = 7;
            break;
        case 'F':
            demiTons = 8;
            break;
        case 'G':
            demiTons = 10;
            break;
        case 'N':
        // The "Silence" note
            demiTons = 0;
            break;
        default:
            break;
    }

    if (alteration == 'd')
        return ++demiTons;
    else if (alteration == 'b')
        return --demiTons;
    return demiTons;
}

// Shows the complete name of a Note
std::string Note::getCompleteString() {
    std::string completeString = "";
    completeString += (nom);
    completeString += std::to_string(octave);
    if (alteration == 'd')
        completeString += 'd';
    if (alteration == 'b')
        completeString += 'b';
    completeString += " - " + valeur;
    if (pointee) completeString += " - p";
    else completeString += " - np";
    return completeString;
}
