#include "board.h"
#include <iostream>


using namespace std;
void space_out() {
    for (int i = 0; i < 11; ++i) {
        cout << " ";
    }
}
void draw_spaced_segment() {
   for (int i = 0; i < 15; ++i) {
        cout << " ";
   }
   cout << " * ";
}

void draw_spaced_line() {
    space_out();
    draw_spaced_segment();
    draw_spaced_segment();

    cout << endl;
}

void draw_connected_line() {
    space_out();
    for (int i = 0; i < 17; ++i) {
        cout << " * ";
    }
    cout << endl;
}

void draw_third() {
    for (int i = 0; i < 6; ++i) {
        draw_spaced_line();
    }
    draw_connected_line();
}

void draw_board() {
    draw_third();
    draw_third();
    for (int i = 0; i < 6; ++i) {
        draw_spaced_line();
    }
}