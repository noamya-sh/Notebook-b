
#include "doctest.h"
#include "Notebook.hpp"
#include "Notebook.cpp"
#include "sources/Direction.hpp"

#include <string>
#include <algorithm>
using namespace std;
using namespace ariel;

TEST_CASE("Good input"){
    Notebook notebook;
            notebook.write(1,2,4,ariel::Direction::Horizontal,"abcde");
            CHECK(notebook.read(1,2,4,ariel::Direction::Horizontal,5) == "abcde");
            notebook.write(3,1,10,Direction::Vertical,"notebook");
            CHECK(notebook.read(3,1,10,Direction::Vertical,8) == "notebook");
            notebook.erase(5,2,4,ariel::Direction::Horizontal,5);
            CHECK(notebook.read(5,2,4,ariel::Direction::Horizontal,5)== "~~~~~");
            notebook.erase(5,1,1,ariel::Direction::Vertical,5);
            CHECK(notebook.read(5,1,1,ariel::Direction::Vertical,5) == "~~~~~");
            CHECK_NOTHROW(notebook.write(3,10,20,Direction::Horizontal,"____"));
            CHECK_NOTHROW(notebook.write(3,10,20,Direction::Horizontal,"____"));
            notebook.write(2,2,1,ariel::Direction::Horizontal,"#$%^&");
            CHECK(notebook.read(2,2,1,ariel::Direction::Horizontal,5) == "#$%^&");
            notebook.write(1,5,1,ariel::Direction::Vertical,"$%5482");
            CHECK(notebook.read(1,5,1,ariel::Direction::Vertical,6) == "$%5482");
            notebook.write(6,8,1,Direction::Horizontal,"abf");
            CHECK_FALSE(notebook.read(6,8,1,Direction::Horizontal,3) == "aaa");
            notebook.write(6,1,10,Direction::Vertical,"9898");
            CHECK_FALSE(notebook.read(6,1,10,Direction::Vertical,4) == "1258");
            //10
            CHECK(notebook.read(1,2,4,ariel::Direction::Horizontal,5) == "abcde");
            notebook.write(15,2,4,ariel::Direction::Horizontal,"5258");
            CHECK(notebook.read(15,2,4,ariel::Direction::Horizontal,4) == "5258");
            CHECK(notebook.read(8,1,1,ariel::Direction::Horizontal,4) != "abcde");
            CHECK(notebook.read(9,2,4,ariel::Direction::Horizontal,5) != "~~~~~");


}
TEST_CASE("bad input"){
    Notebook notebook;
    CHECK_THROWS(notebook.read(1,2,101,ariel::Direction::Horizontal,2));
    CHECK_THROWS(notebook.read(1,2,199,ariel::Direction::Horizontal,5));
    notebook.erase(10,2,1,ariel::Direction::Horizontal,2);
    CHECK_THROWS(notebook.write(10,2,1,ariel::Direction::Horizontal,"dd"));
    notebook.write(2,8,1,Direction::Horizontal,"fff");
    CHECK_THROWS(notebook.write(2,8,1,Direction::Horizontal,"fff"));
    CHECK_THROWS(notebook.write(-2,9,1,Direction::Horizontal,"888"));
    CHECK_THROWS(notebook.write(2,-9,8,Direction::Horizontal,"85"));
    CHECK_THROWS(notebook.write(2,9,-8,Direction::Horizontal,"7895"));
}