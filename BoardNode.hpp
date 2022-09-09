#ifndef GameNode_hpp
#define GameNode_hpp

#include <vector>

#include "Board.hpp"
#include "Constants.hpp"

class BoardNode: public Board {
public:
    std::vector<BoardNode> children;
    Board toBoard();
};


#endif
