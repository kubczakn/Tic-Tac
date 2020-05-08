#include "board.h"
#include <iostream>


using namespace std;

void Board::space_out() {
    for (int i = 0; i < 11; ++i) {
        cout << " ";
    }
}
void Board::draw_spaced_segment() {
    for (int i = 0; i < 15; ++i) {
        cout << " ";
    }
    cout << " * ";
}

void Board::draw_spaced_line() {
    Board::space_out();
    Board::draw_spaced_segment();
    Board::draw_spaced_segment();

    cout << endl;
}

void Board::draw_connected_line() {
    Board::space_out();
    for (int i = 0; i < 17; ++i) {
        cout << " * ";
    }
    cout << endl;
}

void Board::draw_third() {
    for (int i = 0; i < 6; ++i) {
        Board::draw_spaced_line();
    }
    Board::draw_connected_line();
}

void Board::draw_board() {
    Board::draw_third();
    Board::draw_third();
    for (int i = 0; i < 6; ++i) {
        Board::draw_spaced_line();
    }
}