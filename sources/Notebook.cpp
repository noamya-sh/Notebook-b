#include <iostream>
#include <stdexcept>
#include "Direction.hpp"
#include "Notebook.hpp"
#include <unordered_map>
#include <limits.h>
using namespace ariel;
using namespace std;

const int end_line = 100;
const int inf = 10000;


Notebook::Notebook(){
    this->final_line=0;
    this->first_line=INT_MAX;
}

Notebook::~Notebook(){}

void Notebook::write(int page, int row, int col, Direction dir, string str){
    if(str.length()>inf){
        return;
    }
    if(!Notebook::check1(page, row, col, dir, str)){
        throw invalid_argument{"you can't write here"};
    }
    check2(page,row,col,dir,str.length());
    char c=0;
    for (unsigned int i = 0; i < str.length(); i++){
        c=str.at(i);
        if(c < ' ' || c> '~'){
            throw invalid_argument{"Illegal char"};
        }
    }
    char t='~';
    if (str.find(t) != string::npos){
        throw invalid_argument{"Illegal char"};
    }
    if(dir==Direction::Vertical){
        if(row+(int)str.length()>this->final_line){
            this->final_line = row + (int)str.length();
        }
    }else{
        if(row>this->final_line){
            this->final_line=row+1;
        }
    }
    if(row<this->first_line){
        this->first_line=row;
    }
    char ch=0;

    for(unsigned int i=0;i<str.length();i++){
        if(this->note[to_string(page)+","+to_string(row)+","+to_string(col)]!=0 && this->note[to_string(page)+","+to_string(row)+","+to_string(col)]!='_'){
            throw invalid_argument{"you can't write here"};
        }
        ch=str.at(i);
        this->note[to_string(page)+","+to_string(row)+","+to_string(col)]=ch;
        if (dir==Direction::Horizontal) {col++;}
        else{row++;}
    }
//
//    else if(dir==Direction::Vertical){
//        for(unsigned int i=0;i<str.length();i++){
//            if(this->note[to_string(page)+","+to_string(row)+","+to_string(col)]!=0 && this->note[to_string(page)+","+to_string(row)+","+to_string(col)]!='_'){
//                throw invalid_argument{"you can't write here"};
//            }
//            ch=str.at(i);
//            this->note[to_string(page)+","+to_string(row)+","+to_string(col)]=ch;
//
//            row++;
//        }
//    }
}


string Notebook::read(int page, int row, int col, Direction dir, int length){
    check2(page,row,col,dir,length);
    string textForRead;
    for(int i=0;i<length;i++){
        if(this->note[to_string(page)+","+to_string(row)+","+to_string(col)]==0){
            textForRead+='_';
            col++;
            continue;
        }
        textForRead+=this->note[to_string(page)+","+to_string(row)+","+to_string(col)];
        if (dir==Direction::Horizontal) {col++;}
        else{row++;}
    }
//
//    else if(dir==Direction::Vertical){
//        for(int i=0;i<length;i++){
//            if(this->note[to_string(page)+","+to_string(row)+","+to_string(col)]==0){
//                textForRead+='_';
//                row++;
//                continue;
//            }
//            textForRead+=this->note[to_string(page)+","+to_string(row)+","+to_string(col)];
//            row++;
//        }
//    }
    return textForRead;
}


void Notebook::erase(int page, int row, int col, Direction dir, int length){
    check2(page,row,col,dir,length);
    if(dir==Direction::Vertical){
        if(row+length>this->final_line){
            this->final_line=row+length;
        }
    }else{
        if(row>this->final_line){
            this->final_line=row;
        }
    }
    if(row<this->first_line){
        this->first_line=row;
    }
    for(int i=0;i<length;i++){
        this->note[to_string(page)+","+to_string(row)+","+to_string(col)]='~';
        if (dir==Direction::Horizontal) {col++;}
        else{row++;}
    }
//    else if(dir==Direction::Vertical){
//        for(int i=0;i<length;i++){
//            this->note[to_string(page)+","+to_string(row)+","+to_string(col)]='~';
//            row++;
//        }
//    }
}
void Notebook::show(int page){
    if(page<0){
        throw invalid_argument{"This page doesn't exist"};
    }
    string s;
    for(int i=this->first_line-2;i<this->final_line+2;i++){
        if(i<end_line){
            s+=to_string(i)+":  ";
        }else{
            s+=to_string(i)+": ";
        }
        for(int j=0;j<=end_line;j++){
            if(this->note[to_string(page)+","+to_string(i)+","+to_string(j)]==0){
                s+='_';
                j++;
            }
            s+=this->note[to_string(page)+","+to_string(i)+","+to_string(j)];
        }
        s+='\n';
    }cout<<s<<endl;
}

bool Notebook::check1(int page, int row, int col, Direction dir, const string &str){

    for (int i = 0; i < str.length(); i++){
        char c = this->note[to_string(page)+","+to_string(row)+","+to_string(col)];
        if(c!=0 && c!='_'){
            return false;
        }
        if (dir==Direction::Horizontal) {col++;}
        else{row++;}
    }
//    else{
//        for (int i = 0; i < str.length(); i++){
//            char c = this->note[to_string(page)+","+to_string(row)+","+to_string(col)];
//            if(c!=0 && c!='_'){
//                return false;
//            }row++;
//        }
//    }
    return true;
}
void Notebook::check2(int page, int row, int col, Direction dir, int length) {
    if(col<0 || col>=end_line || row<0 || page<0 || length<0){
        throw invalid_argument{"out of range"};
    }
    if((col+length > end_line && dir==Direction::Horizontal)){
        throw invalid_argument{"out of range"};
    }
}