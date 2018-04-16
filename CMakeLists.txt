cmake_minimum_required(VERSION 3.8)
project(Projet)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Application.cpp src/DataImporter.cpp src/DataExporter.cpp src/Note.cpp src/Partition.cpp src/Instrument.cpp src/Piano.cpp src/Guitar.cpp src/Bass.cpp src/KeyboardPlayer.cpp src/GlobalMenu.cpp src/functions.cpp headers/Application.hpp headers/DataImporter.hpp headers/DataExporter.hpp headers/Note.hpp headers/Partition.hpp headers/Instrument.hpp headers/Piano.hpp headers/Guitar.hpp headers/Bass.hpp headers/KeyboardPlayer.hpp headers/GlobalMenu.hpp headers/functions.hpp)
add_executable(Projet ${SOURCE_FILES})