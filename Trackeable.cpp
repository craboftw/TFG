//
// Created by craboftw on 19/06/23.
//

#include "Trackeable.h"

void Trackeable::print() const {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Version: " << versionMajor << "." << versionMinor << std::endl;
    std::cout << "Date: ";
    date_init.print();
    std::cout << "Comments: " << comments << std::endl;
    std::cout << "Authors: " << std::endl;
    for (auto &author : authors) {
        std::cout << "\t";

    }
    std::cout << "Changes: " << std::endl;
    for (auto &change : changes) {
        std::cout << "\t";
        change->print();
        std::cout<< std::endl;
    }
}
