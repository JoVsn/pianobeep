//
// Created by Jordan on 02/12/2017.
//

#ifndef PROJET_KEYBOARDPLAYER_HPP
#define PROJET_KEYBOARDPLAYER_HPP

#include <conio.h>
#include <map>
#include "Note.hpp"
#include "Piano.hpp"

class KeyboardPlayer {

public:

    // Constructors
    KeyboardPlayer(Instrument &);

    // Returns the attribute "instrument"
    Instrument &getInstrument() const;

    // Sets the attribute "instrument"
    void setInstrument(Instrument &instrument);

    // Returns the attribute "keyboard"
    const std::map<std::string, Note*> &getKeyboard() const;

    // Sets the attribute "keyboard"
    void setKeyboard(const std::map<std::string, Note*> &keyboard);

    // Returns the attribute "tempo"
    int getTempo() const;

    // Sets the attribute "tempo"
    void setTempo(int tempo);

    // Returns the Note corresponding to the key given in parameter
    Note* getNote(std::string myKey);

    // Returns the key/instruction corresponding to the key pressed by the user
    std::string detectKey() const;

    // Plays the note corresponding to the key pressed by the user
    std::string play();

    // Deletes the Notes in the keyboard map from the memory
    void deleteNotes();

private:
    Instrument &instrument;
    std::map<std::string, Note*> keyboard;
    int tempo;

};


#endif //PROJET_KEYBOARDPLAYER_HPP
