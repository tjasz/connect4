// Tyler Jaszkowiak
// 29 Dec 2013
// movec.h
//
// The Move class for the connect 4 game code

#ifndef MOVE
#define MOVE

// moves in connect4 consist only of a column field and assignment method
class Moveclass {
  public:
    int col;
    Moveclass(int c) {
	col =c;
    }

    // default constructor sets column to an illegal value
    Moveclass() {
	col = -1;
    }

    Moveclass operator= (Moveclass param) {
	  col = param.col;
	  return param;
    }
};

#endif
