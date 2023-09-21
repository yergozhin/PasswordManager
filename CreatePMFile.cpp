//
// Created by Ержан Ергожин on 29.05.2023.
//

#include "CreatePMFile.h"
#include <iostream>
#include <fstream>
#include "Add_Password.h"
#include <string>

std::string file = "";
void checkIfFileExists(){
    while(true){
        std::cout << "Enter new file name: ";
        std::string filename = "";
        std::cin >> filename;
        if(std::filesystem::exists(filename + ".txt")){
            std::cout << "This file name already exists!" << std::endl;
            std::cout << "Choose option: (1) or (2)" << std::endl;
            std::cout << "(1) Try again" << std::endl;
            std::cout << "(2) Return to main menu" << std::endl;
            std::string decision = "";
            std::cin >> decision;
            if (decision == "2") {
                return;
            }
        }else{
            file = filename;
            //std::ofstream createFile(file, std::ios::app);
            //createFile << "Password Manager" << std::endl;
            Add_Password addPassword = Add_Password();
            std::cout << "Choose option: (1),(2),(3) or (4)" << std::endl;
            std::cout << "(1) Create password for a file" << std::endl;
            std::cout << "(2) Generate password for a file" << std::endl;
            std::cout << "(3) Return to main menu" << std::endl;
            std::cout << "(4) Try creating password manager file again" << std::endl;
            std::string decision = "";
            std::cin >> decision;
            if(decision == "1"){
                addPassword.createPassword();
                std::ofstream createFile(file + ".txt", std::ios::app);
                createFile << "Password Manager" << std::endl;
                std::string s = "Key: ";
                std::string encrypt = addPassword.getCreatedPassword();
                for(int i = 0; i < encrypt.size(); i = i + 1){
                    int x = (int)(encrypt[i]);
                    x = x ^ 17;
                    s = s + char(x);
                }
                createFile << s << std::endl;
                std::cout << "Your created password is <<" << addPassword.getCreatedPassword() << ">>" << std::endl;
                return;
            }
            if(decision == "2"){
                addPassword.generatePassword();
                std::ofstream createFile(file + ".txt", std::ios::app);
                createFile << "Password Manager" << std::endl;
                std::string s = "Key: ";
                std::string encrypt = addPassword.getGeneratedPassword();
                for(int i = 0; i < encrypt.size(); i = i + 1){
                    int x = (int)(encrypt[i]);
                    x = x ^ 17;
                    s = s + char(x);
                }
                createFile << s << std::endl;
                std::cout << "Your created password is <<" << addPassword.getGeneratedPassword() << ">>" << std::endl;
                addPassword.setCP();
                addPassword.setGP();
                return;
            }
            if(decision == "3"){
                return;
            }
        }
    }
    return;
}
void CreatePMFile::start(){
    checkIfFileExists();
}
