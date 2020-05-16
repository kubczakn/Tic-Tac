#include <iostream>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Board {
public:
    void draw_board() {
        cout << endl;
        cout << "  " << squares[1] << " | " << squares[2] << " | " << squares[3] << endl;
        cout << " ---|---|---" << endl;
        cout << "  " << squares[4] << " | " << squares[5] << " | " << squares[6] << endl;
        cout << " ---|---|---" << endl;
        cout << "  " << squares[7] << " | " << squares[8] << " | " << squares[9] << endl;
    }

    int welcome() {
        char input;
        int other_input;
        cout << " Welcome to Tic-Tac-Toe!" << endl;
        cout << " Player 1, please choose X or O: ";
        cin >> input;
        while (toupper(input) != 'X' && toupper(input) != 'O') {
            cout << endl << " Invalid input, please try again: ";
            cin >> input;
        }
        player_one_piece = toupper(input);
        if (toupper(input) == 'X') {
            player_two_piece = 'O';
        }
        else {
            player_two_piece = 'X';
        }
        cout << endl << " Play against a human or computer? Input 1 for a human and 2 for a computer: ";
        cin >> other_input;
        while (other_input != 1 && other_input != 2) {
            cout << endl << "Invalid input, please try again: ";
            cin >> other_input;
        }
        return other_input;
    }

    bool check_draw() {
        int num_filled = 0;
        for (int i = 1; i < 10; ++i) {
            if (squares[i] == 'X' || squares[i] == 'O') {
                ++num_filled;
            }
        }
        if (num_filled == 9) {
            return true;
        }
        return false;
    }

    virtual bool move() {
        draw_board();
        cout << endl;
        int num;
        cout << " Player 1, please choose a number: ";
        cin >> num;
        while (squares[num] == 'X' || squares[num] == 'O') {
            cout << endl << " Already selected, choose another number: ";
            cin >> num;
        }
        squares[num] = toupper(player_one_piece);
        draw_board();
        if (check_draw() == true) {
            cout << endl << " Draw! What a shame" << endl;
            return true;
        }
        if (check_win(player_one_piece) == true) {
            cout << endl;
            cout << " Player 1 has won!" << endl;
            return true;
        }
        cout << endl << " Player 2, please choose a number: ";
        cin >> num;
        while (squares[num] == 'X' || squares[num] == 'O') {
            cout << endl << " Already selected, choose another number: ";
            cin >> num;
        }
        squares[num] = toupper(player_two_piece);
        draw_board();
        if (check_draw() == true) {
            cout << endl << " Draw! What a shame" << endl;
            return true;
        }
        if (check_win(player_two_piece) == true) {
            cout << endl;
            cout << " Player 2 has won!" << endl;
            return true;
        }
        return false;
    }

    bool check_win(char piece) {
        if (squares[1] == piece) {
            if (squares[2] == piece && squares[3] == piece) {
                return true;
            }
            else if (squares[4] == piece && squares[7] == piece) {
                return true;
            }
            else if (squares[5] == piece && squares[9] == piece) {
                return true;
            }
        }
        if (squares[5] == piece) {
            if (squares[7] == piece && squares[3] == piece) {
                return true;
            }
            else if (squares[8] == piece && squares[2] == piece) {
                return true;
            }
            else if (squares[4] == piece && squares[6] == piece) {
                return true;
            }
        }
        if (squares[9] == piece) {
            if (squares[3] == piece && squares[6] == piece) {
                return true;
            }
            else if (squares[7] == piece && squares[8] == piece) {
                return true;
            }
        }
        return false;
    }
    
    void board_reset() {
        squares[1] = '1';
        squares[2] = '2';
        squares[3] = '3';
        squares[4] = '4';
        squares[5] = '5';
        squares[6] = '6';
        squares[7] = '7';
        squares[8] = '8';
        squares[9] = '9';
    }

private:
    friend class Player;
    char squares[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    char player_one_piece;
    char player_two_piece;
};

class Player : public Board {
public:
    Player(Board b_input) :
        b(b_input), num_human_moves(0) {}

    bool move() {
        int num;
        b.draw_board();
        cout << endl;
        cout << " Player 1, please choose a number: ";
        cin >> num;
        while (b.squares[num] == 'X' || b.squares[num] == 'O') {
            cout << endl << " Already selected, choose another number: ";
            cin >> num;
        }
        b.squares[num] = toupper(b.player_one_piece);
        b.draw_board();
        if (check_draw() == true) {
            cout << endl << "Draw! What a shame" << endl;
            return true;
        }
        if (check_win(player_one_piece) == true) {
            cout << endl;
            cout << " Player 1 has won!" << endl;
            return true;
        }
        b.squares[comp_decision()] = toupper(b.player_two_piece);
        b.draw_board();
        if (check_draw() == true) {
            cout << endl << " Draw! What a shame" << endl;
            return true;
        }
        if (check_win(b.player_two_piece) == true) {
            cout << endl;
            cout << " Player 2 has won!" << endl;
            return true;
        }
        return false;
    }

    int comp_decision() {
        int move;
        // Looks through what's currently on the board
        for (int i = 1; i < 10; ++i) {
            if (b.squares[i] == b.player_one_piece) {
                human_player_moves.insert(i);
            }
        }
        num_human_moves = human_player_moves.size();
        if (num_human_moves == 1) {
            sit = human_player_moves.begin();
            srand(time(NULL));
            move = 1 + (rand() % 9);
            while (move == *sit) {
                move = 1 + (rand() & 9);
            }
            return move;
        }
        // Add more functionality below
        else {
            return 0;
        }
    }

private:
    Board b;
    set<int> human_player_moves;
    set<int>::iterator sit;
    int num_human_moves;
};