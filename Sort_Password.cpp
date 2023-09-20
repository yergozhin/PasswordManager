//
// Created by Ержан Ергожин on 29.05.2023.
//

#include "Sort_Password.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::string key = "Key: ";
std::vector<std::vector<std::string>> catTitLogPass;
void saveEverythingIntoAVector(std::string file){
    std::ifstream readFile(file);
    std::string line;
    int i = 0;
    std::string password = "";
    std::string category = "";
    std::string title =  "";
    std::string login = "";
    std::getline(readFile,line);
    std::getline(readFile,line);
    for(int i = 5; i < line.size(); i = i + 1){
        key = key + line[i];
    }
    while(std::getline(readFile,line)) {
        if(i == 0){
            category = "";
            for(int i = 10; i < line.size(); i = i + 1){
                category.push_back(line[i]);
            }
        }
        if(i == 1){
            title = "";
            for(int i = 7; i < line.size(); i = i + 1){
                title.push_back(line[i]);
            }
        }
        if(i == 2){
            login = "";
            for(int i = 7; i < line.size(); i = i + 1){
                login.push_back(line[i]);
            }
        }
        if(i == 3){
            password = "";
            for(int i = 10; i < line.size(); i = i + 1){
                password.push_back(line[i]);
            }
            std::vector<std::string> save = {category,title,login,password};
            catTitLogPass.push_back(save);
            i = -1;
        }
        i = i + 1;
    }
}
void saveEverythingBackIntoAFile(std::string file){
    std::ofstream deleteEverything(file);
    deleteEverything.close();
    std::ofstream addEverything(file, std::ios::app);
    addEverything << "Password Manager" << std::endl;
    addEverything << key << std::endl;
    for(int i = 0; i < catTitLogPass.size(); i = i + 1){
        std::string category = "Category: ";
        category = category + catTitLogPass[i][0];
        std::string title = "Title: ";
        title = title + catTitLogPass[i][1];
        std::string login = "Login: ";
        login = login + catTitLogPass[i][2];
        std::string password = "Password: ";
        password = password + catTitLogPass[i][3];
        addEverything << category << std::endl;
        addEverything << title << std::endl;
        addEverything << login << std::endl;
        addEverything << password << std::endl;
    }
}
void Sort_Password::start(std::string file){
    saveEverythingIntoAVector(file);
    std::sort(catTitLogPass.begin(),catTitLogPass.end());
    saveEverythingBackIntoAFile(file);
}