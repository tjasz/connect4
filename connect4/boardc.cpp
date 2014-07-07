// Tyler Jaszkowiak
// 29 Dec 2013
// boardc.cpp
//
// the board class implementation for connect 4
// The methods of the board class determine victory, legality of moves, and board evaluation
// 'x' trying to maximize, 'o' minimizing

#include "StdAfx.h"
using namespace std;

    
    // returns 1, -1 or 0 depending on x, o , or other
    int Board::intval(char a) const {
	if (a == 'x' || a == 'X') return 1;
	else if (a == 'o' || a == 'O') return -1;
	else return 0;
    }

    // go from int values to the char rep
    char Board::charval(int x) const {
	if (x == 1) return 'x';
	else if (x == -1) return 'o';
	else return ' ';
    }

    // determine if board contians a victory in the columns
    bool Board::colvictory() const {
        int row, col;
        for (row=0; row < 6; row++) {
	    for (col=0; col < 4; col++) {
		if( grid[col][row] == 1 && grid[col+1][row] == 1 && grid[col+2][row] == 1 && grid[col+3][row] == 1 )
		    return true;
	    }
        }
	return false;
    }

    // determine if board contains a victory in the rows
    bool Board::rowvictory() const {
        int row, col;
        for (row=0; row < 3; row++) {
	    for (col=0; col < 7; col++) {
		if(grid[col][row] == 1 && grid[col][row+1] == 1 && grid[col][row+2] == 1 && grid[col][row+3] == 1)
		    return true;
	    }
        }
	return false;
    }

    // determine if board contains a victory in the diagonals
    bool Board::crossvictory() const {
        bool ans = false;
        int row, col;
	for (row=0; row < 3; row++) {
	    for (col=0; col < 4; col++) {
		if(grid[col][row] == 1 && grid[col+1][row+1] == 1 && grid[col+2][row+2] == 1 && grid[col+3][row+3] == 1)
		    ans = true;
	    }
	}
	for (row=0; row < 3; row++) {
	    for (col=3; col < 7; col++) {
		if(grid[col][row] == 1 && grid[col-1][row+1] == 1 && grid[col-2][row+2] == 1 && grid[col-3][row+3] == 1)
		    ans = true;
	    }
	}
	return ans;
    }

    // determine if board contians a defeat in the columns
    bool Board::coldefeat() const {
        int row, col;
        for (row=0; row < 6; row++) {
	    for (col=0; col < 4; col++) {
		if( grid[col][row] == -1 && grid[col+1][row] == -1 && grid[col+2][row] == -1 && grid[col+3][row] == -1 )
		    return true;
	    }
        }
	return false;
    }

    // determine if board contains a defeat in the rows
    bool Board::rowdefeat() const {
        int row, col;
        for (row=0; row < 3; row++) {
	    for (col=0; col < 7; col++) {
		if(grid[col][row] == -1 && grid[col][row+1] == -1 && grid[col][row+2] == -1 && grid[col][row+3] == -1)
		    return true;
	    }
        }
	return false;
    }

    // determine if board contains a defeat in the diagonals
    bool Board::crossdefeat() const {
        bool ans = false;
        int row, col;
	for (row=0; row < 3; row++) {
	    for (col=0; col < 4; col++) {
		if(grid[col][row] == -1 && grid[col+1][row+1] == -1 && grid[col+2][row+2] == -1 && grid[col+3][row+3] == -1)
		    ans = true;
	    }
	}
	for (row=0; row < 3; row++) {
	    for (col=3; col < 7; col++) {
		if(grid[col][row] == -1 && grid[col-1][row+1] == -1 && grid[col-2][row+2] == -1 && grid[col-3][row+3] == -1)
		    ans = true;
	    }
	}
	return ans;
    }


/* public functions start here */ 
    // assignment operator overloading
    Board Board::operator= (Board param) {
	  for (int i=0; i < 7; i++) {
	    for (int j=0; j < 6; j++) {
		grid[i][j] = param.grid[i][j];
	    }
	  }
	  return param;
    }

    // reset the board to initial state
    void Board::reset() {
       moves_played=0;
       for(int i=0; i < 7; i++) {
	 for(int j=0; j < 6; j++) {
	    grid[i][j] = 0;
	 }
       }
    }

    short int Board::worst_case() const {
	if (moves_played % 2) return 43;
	else return -43;
    }  // minimum evaluation of any board for any player
    
    short int Board::worst_case(int player) const {
        if (player==0) return -43;
        else return 43;
    }

    // print the board in a friendly way
    void Board::print() const {
	int row, col;
	cout << " 0 1 2 3 4 5 6 \n";
	for (row=0; row < 6; row++) {
	    cout << "|";
	    for (col=0; col < 7; col++) {
		cout << charval(grid[col][row]) << "|";
	    }
	    cout << endl;
	    }
      cout << endl;
    }

	// print the board in a friendly way to a string
    System::String ^ Board::sprint() const {
	int row, col;
	char buff[500], buffcopy[500];
	strcpy_s(buffcopy,"");
	for (row=0; row < 6; row++) {
		sprintf_s(buff,"%s|",buffcopy);
		strcpy_s(buffcopy,buff);
	    for (col=0; col < 7; col++) {
			sprintf_s(buff,"%s%c|",buffcopy,charval(grid[col][row]));
			strcpy_s(buffcopy,buff);
	    } 
	    sprintf_s(buff,"%s\r\n",buffcopy);
		strcpy_s(buffcopy,buff);
	  }
	  System::String ^ output = gcnew System::String(buff);
	  return output;
    }

    // determine if a board represents a victory for 'x' player
    bool Board::isvictory() const {
	if (colvictory() || rowvictory() || crossvictory() ) {
	    return true;
	} else {
	    return false; 
	}
    }

    // determine if a board represents defeat for 'x' player
    bool Board::isdefeat() const {
	if (coldefeat() || rowdefeat() || crossdefeat() ) return true;
	else return false;
    }

    // determine if game is over, as per Kruse & Ryba
    bool Board::gameover() const {
	return (moves_played == 42) || isdefeat() || isvictory();
    }

    // play a move, as per Kruse & Ryba
    void Board::play(Moveclass attempt) {
	int row=0;
	if(grid[attempt.col][0] == 0) {
	    while(row < 6 && grid[attempt.col][row] == 0) {
		row++;
	    }
	    grid[attempt.col][row-1] = (int) pow((float)-1,moves_played);
	    moves_played++;
	} else {
	    cout << "Play attempted to write to nonempty cell. Turn is forfeit" << endl;
	    moves_played++;
	}
    }

    // play a move, as per Kruse & Ryba
    void Board::play(int attempt) {
	int row=0;
	if(grid[attempt][0] == 0) {
	    while(row < 6 && grid[attempt][row] == 0) {
		row++;
	    }
	    grid[attempt][row-1] = (int) pow((float)-1,moves_played);
	    moves_played++;
	} else {
		moves_played++;
	}
    }

    // populate a stack of legal moves - directly from Kruse & Ryba 207
    int Board::legal_moves(stack<Moveclass> &moves) const {
	int count = 0;
	int a[7] = {3,4,2,5,1,6,0};
	while(!moves.empty()) moves.pop(); // empty the stack
	for (int i=0; i < 7; i++ ) { 
	    if (grid[a[i]][0] == 0) {
		Moveclass can_play(a[i]);
		moves.push(can_play);
		count++;
	    }
	}
	return count;
    }

    // determine if move is legal
    bool Board::islegal(Moveclass move) const {
        if (grid[move.col][0] == 0 && move.col >= 0 && move.col <= 6) {
	    return true;
        } else { 
	    return false;
        }
    }

	
	bool Board::islegal(int move) const {
		if (grid[move][0] == 0 && move >= 0 && move <= 6) return true;
		else return false;
	}

    // evaluate the board; quicker victories are best, 
    //                     long defeats are least embarrassing 
    //                     if no end condition met, evaluate with heuristic
    float Board::evaluate() const {
	if ( isdefeat() ) return moves_played - 43;
	else if ( isvictory() ) return 43 - moves_played;
	else return heuristic();
    }


	// evaluate the board, based on the number of unblocked singles, pairs and triples on the board
    // unblocked singles are worth 1; unblocked doubles are worth 4; unblocked triples are worth 9;
    // All values are added up and divided by a large enough number so that the return is less than 1
    float Board::oldheuristic() const {
        int row, col;
        int groupsum;
        float sum=0;

        // count up singles, pairs and triples in columns
        for (row=0; row < 6; row++) {
            for (col=0; col < 4; col++) {
                // check for nevative player unblocked sets
                if( groupsum = grid[col][row] + grid[col+1][row] + grid[col+2][row] + grid[col+3][row] < 0
                  && grid[col][row] <= 0 && grid[col+1][row] <= 0 && grid[col+2][row] <= 0 && grid[col+3][row] <= 0) 
		    sum -= pow((float) groupsum,2);
                // check for positive player unblocked sets
                if( groupsum = grid[col][row] + grid[col+1][row] + grid[col+2][row] + grid[col+3][row] > 0
                  && grid[col][row] >= 0 && grid[col+1][row] >= 0 && grid[col+2][row] >= 0 && grid[col+3][row] >= 0)
					sum += pow((float) groupsum,2);
            }
        }
        // count sets in all rows
        for (row=0; row < 3; row++) {
            for (col=0; col < 7; col++) {
                // check for negative player unblocked sets
                if( groupsum = grid[col][row] + grid[col][row+1] + grid[col][row+2] + grid[col][row+3] < 0
                  && grid[col][row] <= 0 && grid[col][row+1] <= 0 && grid[col][row+2] <= 0 && grid[col][row+3] <= 0)
                    sum -= pow( (float) groupsum,2);
                // check for positive player unblocked sets
                if( groupsum = grid[col][row] + grid[col][row+1] + grid[col][row+2] + grid[col][row+3] > 0
                  && grid[col][row] >= 0 && grid[col][row+1] >= 0 && grid[col][row+2] >= 0 && grid[col][row+3] >= 0)
					sum += pow((float) groupsum,2);
            }
        }
        // count up sums in positive diagonal
        for (row=0; row < 3; row++) {
            for (col=0; col < 4; col++) {
                // check for sets in negative player tokens
                if( groupsum = grid[col][row] + grid[col+1][row+1] + grid[col+2][row+2] + grid[col+3][row+3] < 0
                  && grid[col][row] <= 0 && grid[col+1][row+1] <= 0 && grid[col+2][row+2] <= 0 && grid[col+3][row+3] <= 0)
                    sum -= pow((float) groupsum,2);
                // check for sets in positive player tokens
                if( groupsum = grid[col][row] + grid[col+1][row+1] + grid[col+2][row+2] + grid[col+3][row+3] > 0
                  && grid[col][row] >= 0 && grid[col+1][row+1] >= 0 && grid[col+2][row+2] >= 0 && grid[col+3][row+3] >= 0)
					sum += pow((float) groupsum,2);
            }
        }
        // count up sums in negative diagonal
        for (row=0; row < 3; row++) {
            for (col=3; col < 7; col++) {
                // check for sets in negative player tokens
                if( groupsum = grid[col][row] + grid[col-1][row+1] + grid[col-2][row+2] + grid[col-3][row+3] < 0
                  && grid[col][row] <= 0 && grid[col-1][row+1] <= 0 && grid[col-2][row+2] <= 0 && grid[col-3][row+3] <= 0)
                    sum -= pow( (float) groupsum,2);
                // check for sets in positive player tokens
                if( groupsum = grid[col][row] + grid[col-1][row+1] + grid[col-2][row+2] + grid[col-3][row+3] > 0
                  && grid[col][row] >= 0 && grid[col-1][row+1] >= 0 && grid[col-2][row+2] >= 0 && grid[col-3][row+3] >= 0)
					sum += pow((float) groupsum,2);
            }
        }
        // since these clusters do not mean as much as a victory, the return value must be of magnitude less than 1.
        return sum/630;
    }	

	 // just count the triples each player has and count them as 1/4 point
    float Board::count_triples() const {
        int row, col;
        int groupsum;
        float sum=0;
        // count up triples in columns
        for (row=0; row < 6; row++) {
            for (col=0; col < 4; col++) {
                // check for nevative player unblocked sets
                if( groupsum = grid[col][row] + grid[col+1][row] + grid[col+2][row] + grid[col+3][row] == -3 ) {
					sum -= 1;
				}
                // check for positive player unblocked sets
                if( groupsum = grid[col][row] + grid[col+1][row] + grid[col+2][row] + grid[col+3][row] == 3 ) {
					sum += 1;
				}
            }
        }
        // count sets in all rows
        for (row=0; row < 3; row++) {
            for (col=0; col < 7; col++) {
                // check for negative player unblocked sets
                if( groupsum = grid[col][row] + grid[col][row+1] + grid[col][row+2] + grid[col][row+3] == -3) {
					sum -= 1;
				}
                // check for positive player unblocked sets
                if( groupsum = grid[col][row] + grid[col][row+1] + grid[col][row+2] + grid[col][row+3] == 3) {
					sum += 1;
				}
            }
        }
        // count up sums in positive diagonal
        for (row=0; row < 3; row++) {
            for (col=0; col < 4; col++) {
                // check for sets in negative player tokens
                if( groupsum = grid[col][row] + grid[col+1][row+1] + grid[col+2][row+2] + grid[col+3][row+3] == -3) {
                    sum -= 1;
				}
                // check for sets in positive player tokens
                if( groupsum = grid[col][row] + grid[col+1][row+1] + grid[col+2][row+2] + grid[col+3][row+3] == 3) {
                    sum += 1;
				}
            }
        }
        // count up sums in negative diagonal
        for (row=0; row < 3; row++) {
            for (col=3; col < 7; col++) {
                // check for sets in negative player tokens
                if( groupsum = grid[col][row] + grid[col-1][row+1] + grid[col-2][row+2] + grid[col-3][row+3] == -3) {
                    sum -= 1;
				}
                // check for sets in positive player tokens
                if( groupsum = grid[col][row] + grid[col-1][row+1] + grid[col-2][row+2] + grid[col-3][row+3] == 3) {
                    sum += 1;
				}
            }
        }
        // since these clusters do not mean as much as a victory, the return value must be of magnitude less than 1.
        return sum/17;
    }
	
	// Allis 1998, even row threats are deadliest from P2, odd row threats deadliest from P1
    float Board::heuristic() const {
        int row, col;
        int groupsum;
        float sum=0;
        // count up triples in columns
        for (row=0; row < 6; row++) {
            for (col=0; col < 4; col++) {
                // check for nevative player unblocked sets
                if( groupsum = grid[col][row] + grid[col+1][row] + grid[col+2][row] + grid[col+3][row] == -3) {
					// find which member of set is 0
					for (int relcol = 0; relcol < 4; relcol++) {
						if (grid[col+relcol][row] == 0 && row % 2 == 1) {
							// consider only the P1 threats in odd rows.
							sum -= 1;
						}
					}
				}
                // check for positive player unblocked sets
                if( groupsum = grid[col][row] + grid[col+1][row] + grid[col+2][row] + grid[col+3][row] == 3) {
					// find which member of set is 0
					for (int relcol = 0; relcol < 4; relcol++) {
						if (grid[col+relcol][row] == 0 && row % 2 == 0) {
							// consider only the threats P2 makes in even rows
							sum += 1;
						}
					}
				}
            }
        }
        // count sets in all rows
        for (row=0; row < 3; row++) {
            for (col=0; col < 7; col++) {
                // check for negative player unblocked sets
                if( groupsum = grid[col][row] + grid[col][row+1] + grid[col][row+2] + grid[col][row+3] == -3) {
					// find which member of set is 0
					for (int relrow = 0; relrow < 4; relrow++) {
						if (grid[col][row+relrow] == 0 && row+relrow % 2 == 1) {
							sum -= 1;
						}
					}
				}
                // check for positive player unblocked sets
                if( groupsum = grid[col][row] + grid[col][row+1] + grid[col][row+2] + grid[col][row+3] == 3) {
					// find which member of set is 0
					for (int relrow = 0; relrow < 4; relrow++) {
						if (grid[col][row+relrow] == 0 && row+relrow % 2 == 0) {
							sum += 1;
						}
					}
				}
            }
        }
        // count up sums in positive diagonal
        for (row=0; row < 3; row++) {
            for (col=0; col < 4; col++) {
                // check for sets in negative player tokens
                if( groupsum = grid[col][row] + grid[col+1][row+1] + grid[col+2][row+2] + grid[col+3][row+3] == -3) {
                    for (int i = 0; i < 4; i++) {
						if (grid[col+i][row+i] == 0 && row+i % 2 == 1) {
							sum -= 1;
						}
					}
				}
                // check for sets in positive player tokens
                if( groupsum = grid[col][row] + grid[col+1][row+1] + grid[col+2][row+2] + grid[col+3][row+3] == 3) {
                    for (int i = 0; i < 4; i++) {
						if (grid[col+i][row+i] == 0 && row+i % 2 == 0) {
							sum += 1;
						}
					}
				}
            }
        }
        // count up sums in negative diagonal
        for (row=0; row < 3; row++) {
            for (col=3; col < 7; col++) {
                // check for sets in negative player tokens
                if( groupsum = grid[col][row] + grid[col-1][row+1] + grid[col-2][row+2] + grid[col-3][row+3] == -3) {
                    for (int i = 0; i < 4; i++) {
						if (grid[col-i][row+i] == 0 && row+i % 2 == 1) {
							sum -= 1;
						}
					}
				}
                // check for sets in positive player tokens
                if( groupsum = grid[col][row] + grid[col-1][row+1] + grid[col-2][row+2] + grid[col-3][row+3] == 3) {
                    for (int i = 0; i < 4; i++) {
						if (grid[col-i][row+i] == 0 && row+i % 2 == 0) {
							sum += 1;
						}
					}
				}
            }
        }
        // since these clusters do not mean as much as a victory, the return value must be of magnitude less than 1.
        float threatsum = sum/70;
		float oldheusum = oldheuristic();
		float triples   = count_triples();
		return (threatsum + oldheusum*1.4375 + triples)/(1 + 1.4375 + 1);
    }


    // determine if current player would prefer newval over val
    bool Board::better(float newval, float val) const {
        if ((moves_played % 2) == 0) return newval >= val;
	else return newval <= val;
    }

    // determine which move/value pair is best for current player
    int Board::best(float vals[], int nvals) const {
	int indexofbest = 0;
	float bestval = vals[indexofbest];
	for(int i=1; i<nvals; i++) {
	    if( better(vals[i],bestval) ) {
		bestval = vals[i];
		indexofbest=i;
	    }
	}
        return indexofbest;
    }

    bool Board::betterforplayer(float newval, float val, int player) const {
       if( (player % 2) == 0) return newval >= val; 
       else  return newval <= val; 
    }

