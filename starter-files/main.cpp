#include <iostream>
#include "board.cpp"

using namespace std;


int main() {
    Board b;
    b.welcome();
    b.draw_board();
    bool win = false;
    int num = 0;
    while (win == false) {
        ++num;
        win = b.move();
    }
}

