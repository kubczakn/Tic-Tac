#include <iostream>
#include "player.h"
#include "board.h"


int main() {
    Board b;
    b.draw_board();
    b.move(1, 1, 'x');
}