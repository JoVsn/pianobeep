//
// Created by Jordan on 02/12/2017.
//

#include "../headers/KeyboardPlayer.hpp"

// Constructors
KeyboardPlayer::KeyboardPlayer(Instrument &myInstrument) : instrument(myInstrument), tempo(120) {
    keyboard.insert(std::make_pair("q", new Note('B', 3)));
    keyboard.insert(std::make_pair("s", new Note('C', 4)));
    keyboard.insert(std::make_pair("d", new Note('D', 4)));
    keyboard.insert(std::make_pair("f", new Note('E', 4)));
    keyboard.insert(std::make_pair("g", new Note('F', 4)));
    keyboard.insert(std::make_pair("h", new Note('G', 4)));
    keyboard.insert(std::make_pair("j", new Note('A', 4)));
    keyboard.insert(std::make_pair("k", new Note('B', 4)));
    keyboard.insert(std::make_pair("l", new Note('C', 5)));
    keyboard.insert(std::make_pair("m", new Note('D', 5)));

    keyboard.insert(std::make_pair("e", new Note('C', 4, 'd')));
    keyboard.insert(std::make_pair("r", new Note('D', 4, 'd')));
    keyboard.insert(std::make_pair("y", new Note('F', 4, 'd')));
    keyboard.insert(std::make_pair("u", new Note('G', 4, 'd')));
    keyboard.insert(std::make_pair("i", new Note('A', 4, 'd')));
    keyboard.insert(std::make_pair("p", new Note('C', 5, 'd')));

}

// Returns the attribute "instrument"
Instrument &KeyboardPlayer::getInstrument() const {
    return instrument;
}

// Sets the attribute "instrument"
void KeyboardPlayer::setInstrument(Instrument &instrument) {
    KeyboardPlayer::instrument = instrument;
}

// Returns the attribute "keyboard"
const std::map<std::string, Note*> &KeyboardPlayer::getKeyboard() const {
    return keyboard;
}

// Sets the attribute "keyboard"
void KeyboardPlayer::setKeyboard(const std::map<std::string, Note*> &keyboard) {
    KeyboardPlayer::keyboard = keyboard;
}

// Returns the attribute "tempo"
int KeyboardPlayer::getTempo() const {
    return tempo;
}

// Sets the attribute "tempo"
void KeyboardPlayer::setTempo(int tempo) {
    KeyboardPlayer::tempo = tempo;
}

// Returns the Note corresponding to the key given in parameter
Note* KeyboardPlayer::getNote(std::string myKey) {
    if (keyboard.find(myKey) == keyboard.end()) {
        return new Note('N');
    }
    return keyboard[myKey];
}

// Returns the key/instruction corresponding to the key pressed by the user
std::string KeyboardPlayer::detectKey() const {
    int c = getch();
    switch(c) {
        case 'q':
            return "q";
        case 's':
            return "s";
        case 'd':
            return "d";
        case 'f':
            return "f";
        case 'g':
            return "g";
        case 'h':
            return "h";
        case 'j':
            return "j";
        case 'k':
            return "k";
        case 'l':
            return "l";
        case 'm':
            return "m";
        case 'e':
            return "e";
        case 'r':
            return "r";
        case 'y':
            return "y";
        case 'u':
            return "u";
        case 'i':
            return "i";
        case 'p':
            return "p";
        case 'w':
            return "leave";
        case 'x':
            return "save";
        case 'c':
            return "tempo";
        default:
            return "";
    }
}

// Plays the note corresponding to the key pressed by the user
std::string KeyboardPlayer::play()  {
    std::string keyPressed;
    keyPressed = detectKey();
    Note* myNote = getNote(keyPressed);
    instrument.playNote(*myNote, tempo);
    return keyPressed;

}

// Deletes the Notes in the keyboard map from the memory
void KeyboardPlayer::deleteNotes() {
    for(std::map<std::string, Note*>::iterator it = keyboard.begin(); it != keyboard.end(); ++it) {
        delete it->second;
    }
}
