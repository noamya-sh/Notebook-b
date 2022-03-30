#include "Direction.hpp"
#include <unordered_map>

using namespace std;
namespace ariel {
    class Notebook {
    private:
        std::unordered_map<string, char> note;
        int first_line;
        int final_line;

        bool check1(int page, int row, int col, Direction dir, const std::string &str);

        void static check2(int page, int row, int col, Direction dir, int length);

    public:
        Notebook();

        ~Notebook();

        void write(int page, int row, int col, Direction dir, string str);

        string read(int page, int row, int col, Direction dir, int length);

        void erase(int page, int row, int col, Direction dir, int length);

        void show(int page);

    };
}