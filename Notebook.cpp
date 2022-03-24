
#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdexcept>
using namespace std;
namespace ariel{
    Notebook::Notebook(){
//        this->note = unordered_map<string, char>;
    }
    Notebook::~Notebook(){}
    void Notebook::write(int page, int row, int col,Direction,string s){
        if (col+(int)s.length() > 100)
            throw out_of_range("row length is 100 characters.");

//        char ch;
//        int i=0;
//        ch=s.at(i);
    }
    string Notebook::read(int page, int row, int col,Direction d, int length){
//        Notebook::note n;
        if (col+length > 100)
            throw out_of_range("row length is 100 characters.");
//        string s;

//        int i = (d == Direction::Horizontal) ? col : row;
//        int j = (d == Direction::Horizontal) ? row : col;
//        for (; i < length; ++i) {
//            if (umap.find(key) == umap.end())
//        }
        return "";
    }
    void Notebook::erase(int page, int row, int col,Direction,  int length){
        if (col+length > 100)
            throw out_of_range("row length is 100 characters.");
    }
    void Notebook::show(int page){}
}
