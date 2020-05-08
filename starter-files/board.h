#include <iostream>

using namespace std;

class Board {
public:
    // Spaces out board for readibility
    void space_out();

    // Draws segment of the board that is mostly space
    void draw_spaced_segment();

    // Draws line of the board that is mostly space
    void draw_spaced_line();

    // Draws a portion of the board that is connected
    void draw_connected_line();

    // Draws a third of the board
    void draw_third();

    // Draws the board
    void draw_board();
};

