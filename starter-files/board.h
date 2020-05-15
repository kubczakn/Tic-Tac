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

    // Draws the default board
    void draw_board();

    // Moves across a row
    void row_across();

    // Moves piece down a column
    void column_down();


    // Draws an X
    void draw_x(int row);
    
    // Draws an O
    void draw_o(int row);

    // Positions piece in correct row
    void position_row(int row);

    // Positions piece in correct column
    void position_column(int column);

    // Completes player move
    void move(int row, int column, char piece);
};

