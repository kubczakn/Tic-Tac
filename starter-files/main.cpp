#include <iostream>
#include "board.cpp"

using namespace std;


int main() {
    Board b;
    bool win = false;
    int num = 0;
    bool play_again = true;
    if (b.welcome() == 1) {
        while (play_again == true) {
            win = false;
            char input;
            while (win == false) {
                ++num;
                win = b.move();
            }
            cout << endl << " Play Again? Y/N: ";
            cin >> input;
            while (toupper(input) != 'Y' && toupper(input) != 'N') {
                cout << endl << " Invalid input, please try again: ";
                cin >> input;
            }
            if (toupper(input) == 'N') {
                play_again = false;
            }
            else {
                b.board_reset();
            }
        }
    }
    else {
        Player p(b);
        while (play_again == true) {
            b.draw_board();
            win = false;
            char input;
            while (win == false) {
                ++num;
                win = p.move();
            }
            cout << endl << " Play Again? Y/N: ";
            cin >> input;
            while (toupper(input) != 'Y' && toupper(input) != 'N') {
                cout << endl << " Invalid input, please try again: ";
                cin >> input;
            }
            if (toupper(input) == 'N') {
                play_again = false;
            }
            else {
                p.board_reset();
            }
        }
    }
}

