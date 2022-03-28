//
// Created by נעמיה on 21/03/2022.
//

#ifndef NOTEBOOK_A_NOTEBOOK_H
#define NOTEBOOK_A_NOTEBOOK_H
#include "sources/Direction.hpp"
#include <iostream>
#include <unordered_map>
using namespace std;
namespace ariel{
    class Notebook {
    private:
        unordered_map<string, char> note;
    public:
        Notebook();
        ~Notebook();
        void write(int page,int row,int col,Direction d,string s);
        string read(int page,int row,int col,Direction d, int length);
        void erase(int page,int row,int col,Direction d, int length);
        void show(int page);
    };}




#endif //NOTEBOOK_A_NOTEBOOK_H
