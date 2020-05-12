#include "board.h"
#include "Windows.h"
#include <iostream>


void setCursorPosition(int x, int y) {
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(output, pos);
}

void Board::space_out() {
    for (int i = 0; i < 11; ++i) {
        std::cout << " ";
    }
}
void Board::draw_spaced_segment() {
    for (int i = 0; i < 15; ++i) {
        std::cout << " ";
    }
    std::cout << " * ";
}

void Board::draw_spaced_line() {
    Board::space_out();
    Board::draw_spaced_segment();
    Board::draw_spaced_segment();

    std::cout << endl;
}

void Board::draw_connected_line() {
    Board::space_out();
    for (int i = 0; i < 17; ++i) {
        std::cout << " * ";
    }
    std::cout << endl;
}


void Board::draw_third() {
    for (int i = 0; i < 3; ++i) {
        Board::draw_spaced_line();
    }
    for (int i = 0; i < 3; ++i) {
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

void Board::row_across() {
    for (int i = 0; i < 18; ++i) {
        std::cout << " ";
    }
}

void Board::column_down() {
    for (int i = 0; i < 7; ++i) {
        std::cout << std::endl;
    }
}

void Board::draw_o() {

}

void Board::position_row(int row) {
    int num_moves = 0;
    space_out();
    std::cout << "    ";
    while (num_moves != row) {
        row_across();
        ++num_moves;
    }
}

void Board::position_column(int column) {
    int num_moves = 0;
    while (num_moves != column) {
        column_down();
        ++num_moves;
    }
}

void Board::draw_x(int row) {
    if (row == 2) {
        int num = 0;
        Board::position_row(row);
        while (num < 24) {
            std::cout << "\b";
            ++num;
        }
        std::cout << "*                 *     ";
        std::cout << "*   *" << std::endl;
        Board::position_row(row);
        num = 0;
        while (num < 24) {
            std::cout << "\b";
            ++num;
        }
        std::cout << "*                 *     ";
        std::cout << " * * " << std::endl;
        Board::position_row(row);
        num = 0;
        while (num < 24) {
            std::cout << "\b";
            ++num;
        }
        std::cout << "*                 *     ";
        std::cout << "  *  " << std::endl;
        Board::position_row(row);
        num = 0;
        while (num < 24) {
            std::cout << "\b";
            ++num;
        }
        std::cout << "*                 *     ";
        std::cout << " * * " << std::endl;
        Board::position_row(row);
        num = 0;
        while (num < 24) {
            std::cout << "\b";
            ++num;
        }
        std::cout << "*                 *     ";
        std::cout << "*   *";
    }
    else if (row == 1) {
        Board::position_row(row);
        std::cout << "\b\b\b\b\b\b*     ";
        std::cout << "*   *" << std::endl;
        Board::position_row(row);
        std::cout << "\b\b\b\b\b\b*     ";
        std::cout << " * * " << std::endl;
        Board::position_row(row);
        std::cout << "\b\b\b\b\b\b*     ";
        std::cout << "  *  " << std::endl;
        Board::position_row(row);
        std::cout << "\b\b\b\b\b\b*     ";
        std::cout << " * * " << std::endl;
        Board::position_row(row);
        std::cout << "\b\b\b\b\b\b*     ";
        std::cout << "*   *";
    }
    else {
        Board::position_row(row);
        std::cout << "*   *" << std::endl;
        Board::position_row(row);
        std::cout << " * * " << std::endl;
        Board::position_row(row);
        std::cout << "  *  " << std::endl;
        Board::position_row(row);
        std::cout << " * * " << std::endl;
        Board::position_row(row);
        std::cout << "*   *";
    }
}

void Board::move(int row, int column, char piece) {
    setCursorPosition(0, 0);
    std::cout << std::endl;
    Board::position_column(column);
    if (piece == 'x') {
        Board::draw_x(row);
    }
    setCursorPosition(0, 20);
}