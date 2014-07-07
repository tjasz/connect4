#include "stdafx.h"
/*
// minimax()
// The minimax algorithm, to be called recursively
// input: the board, depth of minimax search, recommended move, and its 
//     resulting value
// output: the values, passed by reference, of the recommended move and its
//     value are edited
void minimax(const Board &game, int depth, Moveclass *recommended, float* best_value) {
    // base case: passed gameboard represents a completed game or depth is 0
    //            return the evaluation
    if (game.gameover() || depth == 0) {
        *best_value = game.evaluate();
    } 
    // otherwise: use recursive calls to determine the best possible legal move
    else {
        stack<Moveclass> moves;
        game.legal_moves(moves);	// populates the stack with legal moves
        float value;
	*best_value=game.worst_case();
        while(!moves.empty() ) {
            Moveclass try_it(8), reply(8);
            try_it = moves.top();
            Board newgame = game;
            newgame.play(try_it);
            minimax(newgame, depth-1, &reply, &value);
	    // if the value from the recursive call is better than previous
	    // values, edit the values of best_value and recommended move
            if( game.better(value, *best_value) ) {
                *best_value = value;
                *recommended = try_it;
            }
            moves.pop();
        }
    }
} */