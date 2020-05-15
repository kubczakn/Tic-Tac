#include <iostream>
#include "player.h"
#include "board.h"

void game_intro() {
    char input;
    std::cout << "Welcome to Tic-Tac-Toe! Would you like to start a new game Y/N?";
    std::cin >> input;
}

int main() {
    Board b;
    b.draw_board();
    b.move(2, 0, 'x');
    b.move(0, 0, 'x');
    b.move(1, 2, 'x');
    b.move(1, 0, 'x');
}