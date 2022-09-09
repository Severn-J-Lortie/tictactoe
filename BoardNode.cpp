#include "BoardNode.hpp"

Board BoardNode::toBoard() {
    Board board;
    board.setBoard(getBoard());
    return board;
}
