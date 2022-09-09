#ifndef Ai_hpp
#define Ai_hpp

#include <array>
#include <utility>
#include <limits>
#include <utility>
#include <cmath>
#include "Constants.hpp"
#include "Move.hpp"
#include "Board.hpp"
#include "BoardNode.hpp"

class Ai {
private:
    void generatePossibleMoves(BoardNode &node, bool isAiTurn);
    
    std::pair<int, BoardNode> maximize(BoardNode node);
    std::pair<int, BoardNode> minimize(BoardNode node);
public:
    BoardNode makeMove(Board board);
    int calculateUtility(BoardNode board);
};

#endif
