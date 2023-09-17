//
// Created by Ержан Ергожин on 31.05.2023.
//

#include "SearchPassword.h"
#include <iostream>
#include <fstream>
#include <string>

void searchByCategory(std::string file, std::string str){
    std::ifstream readFile(file);
    std::string line;
    std::string category = "";
    std::cout << "Enter the " << str << ": ";
    std::cin >> category;
    std::string previous_line = "";
    while(std::getline(readFile,line)){
        if((line.size() < 10 + category.size() && category.size() < 3 && str.size() == 8) ||
        (line.size() < 7 + category.size() && str.size() == 5)){
            continue;
        }
        std::string s = "";
        for(int i = 0; i < str.size() + 2; i = i + 1){
            s.push_back(line[i]);
        }
        if(s == "Category: "){
            previous_line = line;
        }
        if((s != "Category: " && str.size() == 8) || (s != "Title: " && str.size() == 5)){
            continue;
        }
        bool unique = true;
        for(int i = str.size() + 2; i < line.size(); i = i + 1){
            if(line.size() - i < category.size()){
                break;
            }
            bool check = false;
            for(int j = i; j < line.size(); j = j + 1) {
                if (line[i] != category[i - (str.size() + 2)]) {
                    check = true;
                }
            }
            if(!check){
                unique = false;
            }
        }
        if(!unique && str.size() == 8){
            std::cout << line << std::endl;
            std::getline(readFile,line);
            std::cout << line << std::endl;
            std::getline(readFile,line);
            std::cout << line << std::endl;
            std::getline(readFile,line);
            std::cout << line << std::endl;
        }else if(!unique && str.size() == 5){
            std::cout << previous_line << std::endl;
            std::cout << line << std::endl;
            std::getline(readFile,line);
            std::cout << line << std::endl;
            std::getline(readFile,line);
            std::cout << line << std::endl;
        }
    }
}
void seeAllPasswords(std::string file){
    std::ifstream readFile(file);
    std::string line;
    while(std::getline(readFile,line)){
        std::cout << line << std::endl;
    }
}
void SearchPassword::start(std::string file){
    std::cout << "Choose option: (1),(2) or (3)" << std::endl;
    std::cout << "(1) Search by category and title" << std::endl;
    std::cout << "(2) Search by category" << std::endl;
    std::cout << "(3) Search by title" << std::endl;
    std::cout << "(4) See all the passwords" << std::endl;
    std::cout << "(5) Return to main menu" << std::endl;
    std::string decision = "";
    std::cin >> decision;
    if(decision == "1"){
        searchByCategory(file,"category");
        searchByCategory(file,"title");
    }
    if(decision == "2"){
        searchByCategory(file,"category");
    }
    if(decision == "3"){
        searchByCategory(file,"title");
    }
    if(decision == "4"){
        seeAllPasswords(file);
    }
    if(decision == "5"){
        return;
    }
}