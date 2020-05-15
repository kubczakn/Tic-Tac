#include <iostream>

using namespace std;

class Board {
public:
    void draw_board() {
        cout << "    |   |   " << endl;
        cout << "  " << squares[0] << " | " << squares[1] << " | " << squares[2] << endl;
        cout << " ___|___|___" << endl;
        cout << "  " << squares[3] << " | " << squares[4] << " | " << squares[5] << endl;
    }

private:
    char squares[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
};