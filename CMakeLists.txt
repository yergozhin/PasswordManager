cmake_minimum_required(VERSION 3.24)
project(Password_Manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(Password_Manager main.cpp Add_Password.cpp Add_Password.h Sort_Password.cpp Sort_Password.h CreatePMFile.cpp CreatePMFile.h OpenPMFile.cpp OpenPMFile.h PMFunctionalities.cpp PMFunctionalities.h DeleteCategory.cpp DeleteCategory.h AddCategory.cpp AddCategory.h SearchPassword.cpp SearchPassword.h DeletePassword.cpp DeletePassword.h EditPassword.cpp EditPassword.h)
