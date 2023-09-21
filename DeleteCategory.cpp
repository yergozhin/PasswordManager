//
// Created by Ержан Ергожин on 30.05.2023.
//

#include "DeleteCategory.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> everythingExceptParticularCategory;
bool savingEverythingIntoAVector(std::string file) {
    std::cout << "Enter the category you want to delete: ";
    std::string category = "";
    std::cin >> category;
    std::cout << "Are you sure you want to delete that category" << std::endl;
    std::cout << "Remember all the information in that category will be deleted" << std::endl;
    std::cout << "Choose option: (1-4)" << std::endl;
    std::cout << "(1) Yes, delete that category" << std::endl;
    std::cout << "(2) No, don't delete that category" << std::endl;
    std::cout << "(3) Try again" << std::endl;
    std::cout << "(4) Return to main menu" << std::endl;
    std::string decision = "";
    std::cin >> decision;
    if (decision == "4") {
        return true;
    }else if(decision == "2"){
        return true;
    }else if(decision == "3"){
        return savingEverythingIntoAVector(file);
    }else {
        std::ifstream readFile(file);
        std::string line = "";
        while (std::getline(readFile, line)) {
            if (line.size() < 14) {
                everythingExceptParticularCategory.push_back(line);
                continue;
            }
            std::string s = "";
            for (int i = 0; i < 10; i = i + 1) {
                s.push_back(line[i]);
            }
            if (s == "Category: ") {
                s = "";
                for (int i = 10; i < line.size(); i = i + 1) {
                    s.push_back(line[i]);
                }
                if (s == category) {
                    std::getline(readFile, line);
                    std::getline(readFile, line);
                    std::getline(readFile, line);
                    continue;
                }
            }
            everythingExceptParticularCategory.push_back(line);
        }
        return false;
    }
    return true;
}
void addEverythingBackIntoAFile(std::string file){
    std::ofstream deleteEverything(file);
    deleteEverything.close();
    std::ofstream addEverything(file, std::ios::app);
    for(int i = 0; i < everythingExceptParticularCategory.size(); i = i + 1){
        addEverything << everythingExceptParticularCategory[i] << std::endl;
    }
}
void DeleteCategory::start(std::string file) {
    bool returnToMainMenu = savingEverythingIntoAVector(file);
    if(returnToMainMenu){
        return;
    }
    addEverythingBackIntoAFile(file);
}