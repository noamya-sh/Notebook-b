
#include "Notebook.hpp"
#include "sources/Direction.hpp"
#include <iostream>
#include <unordered_map>
#include <string>
#include <stdexcept>

using namespace std;
namespace ariel {
    Notebook::Notebook() {}
    Notebook::~Notebook() {}

    void Notebook::write(int page, int row, int col, Direction d, string s) {
        if (col + (int) s.length() > 100)
            throw out_of_range("row length is 100 characters.");
        if (page < 0 || row < 0 || col < 0)
            throw out_of_range("There is no negative number.");
        bool flag = (d == Direction::Horizontal);
        string temp;
        for (unsigned int i = 0; i < s.length(); ++i) {
            if (flag)
                temp = to_string(page) + "," + to_string(row) + "," + to_string((unsigned int)col + i);
            else
                temp = to_string(page) + "," + to_string((unsigned int)row + i) + "," + to_string(col);

            if (note.find(temp) == note.end() || note.at(temp) == '_')
                note[temp] = s.at(i);
            else
                throw runtime_error("It is not possible to write about a written or deleted place.");
        }
    }

    string Notebook::read(int page, int row, int col, Direction d, int length) {
        if (col + length > 100)
            throw out_of_range("row length is 100 characters.");
        string s;
        bool flag = (d == Direction::Horizontal);
        string temp;
        for (unsigned int i = 0; i < length; ++i) {
            if (flag)
                temp = to_string(page) + "," + to_string(row) + "," + to_string((unsigned int)col + i);
            else
                temp = to_string(page) + "," + to_string((unsigned int)row + i) + "," + to_string(col);
            if (note.find(temp) == note.end())
                s += '_';
            else
                s += note.at(temp);
        }
        return s;
    }

    void Notebook::erase(int page, int row, int col, Direction d, int length) {
        if (col + length > 100)
            throw out_of_range("row length is 100 characters.");
        bool flag = (d == Direction::Horizontal);
        string temp;
        for (unsigned int i = 0; i < length; ++i) {
            if (flag)
                temp = to_string(page) + "," + to_string(row) + "," + to_string((unsigned int)col + i);
            else
                temp = to_string(page) + "," + to_string((unsigned int)row + i) + "," + to_string(col);
            note[temp] = '~';
        }
    }

    void Notebook::show(int page) {
    }

}
