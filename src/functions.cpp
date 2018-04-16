//
// Created by Jordan on 09/12/2017.
//

#include "../headers/functions.hpp"

/* Allows to fuse two partitions objects.
 * Be careful, the tempo depends on the first partition, not on the second one
 */
Partition operator+(Partition part_1, Partition part_2) {
    Partition newPartition;
    if (part_1.getNotes().empty() || part_2.getNotes().empty())
        throw std::length_error("One of the partition is empty !");

    std::vector<Note*> notes = part_1.getNotes();
    std::vector<Note*> notes_2 = part_2.getNotes();
    notes.insert(notes.end(), notes_2.begin(), notes_2.end()); // We concatenate the second partition "notes" vector to the the first one

    newPartition.setNotes(notes);
    return newPartition;
}