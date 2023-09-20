//
// Created by Ержан Ергожин on 29.05.2023.
//

#include "PMFunctionalities.h"
#include <iostream>
#include <string>
#include "Add_Password.h"
#include "Sort_Password.h"
#include "DeleteCategory.h"
#include "AddCategory.h"
#include "SearchPassword.h"
#include "DeletePassword.h"
#include "EditPassword.h"

void PMFunctionalities::start(std::string file){
    while(true){
        std::cout << "Choose option(1-8):" << std::endl;
        std::cout << "(1) Add password" << std::endl;
        std::cout << "(2) Delete password" << std::endl;
        std::cout << "(3) Search passwords" << std::endl;
        std::cout << "(4) Sort passwords" << std::endl;
        std::cout << "(5) Edit password" << std::endl;
        std::cout << "(6) Add category" << std::endl;
        std::cout << "(7) Delete category" << std::endl;
        std::cout << "(8) Exit this password manager file" << std::endl;
        std::string decision = "";
        std::cin >> decision;
        if(decision == "1"){
            Add_Password addPassword = Add_Password();
            addPassword.start(file);
        }else if(decision == "2"){
            DeletePassword deletePassword = DeletePassword();
            deletePassword.start(file);
        }else if(decision == "3"){
            SearchPassword searchPassword = SearchPassword();
            searchPassword.start(file);
        }else if(decision == "4") {
            Sort_Password sortPassword = Sort_Password();
            sortPassword.start(file);
        }else if(decision == "5"){
            EditPassword editPassword = EditPassword();
            editPassword.start(file);
        }else if(decision == "6") {
            AddCategory addCategory = AddCategory();
            addCategory.start(file);
        }else if(decision == "7") {
            DeleteCategory deleteCategory = DeleteCategory();
            deleteCategory.start(file);
        }else if(decision == "8"){
                return;
        }
    }
}