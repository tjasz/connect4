// Tyler Jaszkowiak
// 29 Dec 2013
// boardc.h
//
// The board class interface for the connect 4 game.
// 'x' trying to maximize, 'o' minimizing
// The board consists of an array of integers and a number of moves played
// Methods include determining victory and defeat, evaluating a board, 
//     determining a better move, and returning a stack of legal moves

#include<iostream>
#include<stack>
#include "movec.h"
using namespace std;

class Board {
  private:
    short int grid[7][6];   // columns before rows due to the nature of the game
    short int moves_played;
	short int last_player_move;
	short int last_comp_move;
    
    // returns 1, -1 or 0 depending on x, o , or blank
    int intval(char a) const;

    // go from int values to the char representation
    char charval(int x) const;

    // determine if board contians a victory (for 'x') in the columns, rows, diagonals
    bool colvictory() const;
    bool rowvictory() const;
    bool crossvictory() const;

    // determine defeat
    bool coldefeat() const;
    bool rowdefeat() const;
    bool crossdefeat() const;

  public:
    short int get_moves_played() const {
	return moves_played;
    }

    // determine the worst case for current player, or passed player
    short int worst_case() const;
    short int worst_case(int player) const;

    // the default constructor initializes all to 0
    Board() {
       moves_played=0;
       for(int i=0; i < 7; i++) {
	 for(int j=0; j < 6; j++) {
	    grid[i][j] = 0;
	 }
       }
    }

    // overloaded assignment operator
    Board operator = (Board param);
 
    // reset the board, as for playing again
    void reset();

    // print the board 
    void print() const;
	System::String ^ sprint() const;

    // determine if a board represents a victory for 'x' player
    bool isvictory() const;

    // determine if board represents a defeat for 'x' player
    bool isdefeat() const;

    // tests if game is over
    bool gameover() const;

    // play a move
    void play(Moveclass attempt);
	void play(int attempt);
	void unplay();

    // populate stack of legal moves
    int legal_moves(stack<Moveclass> &moves) const;

    // determine legality of a move
    bool islegal(Moveclass move) const;
	bool islegal(int move) const;

    // evaluate board based on wins, defeats, and unblocked sets of tokens
    float evaluate() const;

    // evaluate board based on unblocked sets of tokens alone
    float oldheuristic() const;
    float count_triples() const;
    float heuristic() const;

    // determine which value is better for the current player
    bool better(float newval, float val) const;
    int best(float vals[], int nvals) const;

    // determine which value is better for given player
    bool betterforplayer(float newval, float val, int player) const;
};
