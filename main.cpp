#include <iostream>
#include "Add_Password.h"
#include "Sort_Password.h"
#include "CreatePMFile.h"
#include <string>
#include "OpenPMFile.h"

int main() {
    while(true) {
        std::cout << "Choose option: (1),(2) or (3)" << std::endl;
        std::cout << "(1) Create new password manager file" << std::endl;
        std::cout << "(2) Open password manager file" << std::endl;
        std::cout << "(3) Exit" << std::endl;
        std::string decision = "";
        std::cin >> decision;
        if (decision == "1") {
            CreatePMFile createPmFile = CreatePMFile();
            createPmFile.start();
        }
        if (decision == "2"){
            OpenPMFile openPmFile = OpenPMFile();
            openPmFile.start();
        }
        if (decision == "3") {
            return 0;
        }
    }
    return 0;
}
