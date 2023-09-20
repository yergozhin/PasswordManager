//
// Created by Ержан Ергожин on 29.05.2023.
//

#include "OpenPMFile.h"
#include <iostream>
#include <string>
#include <fstream>
#include "PMFunctionalities.h"


void checkingIfAFileEnteredCorrect(){
    while(true){
        std::cout << "Enter name of the password manager file:";
        std::string file = "";
        std::cin >> file;
        if(!std::filesystem::exists(file + ".txt")){
            std::cout << "This file name doesn't exist!" << std::endl;
            std::cout << "Choose option: (1) or (2)" << std::endl;
            std::cout << "(1) Try again" << std::endl;
            std::cout << "(2) Return to main menu" << std::endl;
            std::string decision = "";
            std::cin >> decision;
            if (decision == "2") {
                return;
            }
        }else{
            std::ifstream readFile(file + ".txt");
            std::string line;
            std::getline(readFile,line);
            if(line != "Password Manager"){
                std::cout << "Unfortunately this is not a password manager file" << std::endl;
                std::cout << "Choose option: (1) or (2)" << std::endl;
                std::cout << "(1) Try again" << std::endl;
                std::cout << "(2) Return to main menu" << std::endl;
                std::string decision = "";
                std::cin >> decision;
                if (decision == "2") {
                    return;
                }
            }else{
                std::getline(readFile,line);
                std::string decription = "";
                for(int i = 5; i < line.size(); i = i + 1){
                    int x = (int)line[i] ^ 17;
                    decription = decription + char(x);
                }
                while(true){
                    std::cout << "Enter the password of the file <<" << file << ">>" << std::endl;
                    std::string password = "";
                    std::cin >> password;
                    if(password != decription){
                        std::cout << "Unfortunately this password is incorrect" << std::endl;
                        std::cout << "Choose option: (1) or (2)" << std::endl;
                        std::cout << "(1) Try again" << std::endl;
                        std::cout << "(2) Return to main menu" << std::endl;
                        std::string decision = "";
                        std::cin >> decision;
                        if (decision == "2") {
                            return;
                        }
                    }else{
                        std::cout << "You can now use your password manager" << std::endl;
                        PMFunctionalities pmFunctionalities = PMFunctionalities();
                        pmFunctionalities.start(file + ".txt");
                        return;
                    }
                }
            }
        }
    }
}
void OpenPMFile::start() {
    checkingIfAFileEnteredCorrect();
}