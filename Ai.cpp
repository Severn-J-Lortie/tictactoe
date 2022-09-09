#include "Ai.hpp"

void Ai::generatePossibleMoves(BoardNode &node, bool isAiTurn) {
    
    // Return if game has been won by AI or player
    if (node.hasGameBeenWon().first) {
        return;
    }
    
    // Choose the piece we add to the board
    char piece;
    if (isAiTurn) {
        piece = AI_PIECE;
    } else {
        piece = PLAYER_PIECE;
    }
    
    // Add nodes to the current node
    int emptySpaces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            
            if (node.getPieceAtPosition(i, j) == NO_PIECE) {
                
                BoardNode possibleMove;
                possibleMove.copyFrom(node);
                
                Move move;
                move.setMove(i, j, piece);
                
                possibleMove.makeMove(move);
                node.children.push_back(possibleMove);
                emptySpaces++;
                
            }
            
        }
    }
    
    // Return on tied game
    if (emptySpaces == 0) {
        return;
    }
    
    // Loop through added nodes and call generatePossibleMoves() on each
    for (int i = 0; i < node.children.size(); i++) {
        generatePossibleMoves(node.children.at(i), !isAiTurn);
    }
    
}

int Ai::calculateUtility(BoardNode board) {
    std::pair<bool, char> boardState;
    boardState = board.hasGameBeenWon();
    if (boardState.first) {
        if (boardState.second == AI_PIECE) {
            return 1;
        } else {
            return -1;
        }
    }
    return 0;
}

std::pair<int, BoardNode> Ai::maximize(BoardNode node) {
    
    // Return if depth limit reached or game is in win state
    if (node.children.size() == 0) {
        return std::make_pair(calculateUtility(node), node);
    }
    
    // Choose child node with maximum utility
    BoardNode maximumUtilityNode;
    int maximumUtility = -std::numeric_limits<int>::max();
    for (int i = 0; i < node.children.size(); i++) {
        
        std::pair<int, BoardNode> returnValue = minimize(node.children.at(i));
        
        if (returnValue.first > maximumUtility) {
            maximumUtility = returnValue.first;
            maximumUtilityNode = node.children.at(i);
        }
        
    }
    
    return std::make_pair(maximumUtility, maximumUtilityNode);
    
}


std::pair<int, BoardNode> Ai::minimize(BoardNode node) {
    
    // Return if depth limit reached or game is in win state
    if (node.children.size() == 0) {
        return std::make_pair(calculateUtility(node), node);
    }

    // Choose child node with maximum utility
    BoardNode minimumUtilityNode;
    int minimumUtility = std::numeric_limits<int>::max();
    for (int i = 0; i < node.children.size(); i++) {
        
        std::pair<int, BoardNode> returnValue = maximize(node.children.at(i));
        
        if (returnValue.first < minimumUtility) {
            minimumUtility = returnValue.first;
            minimumUtilityNode = node.children.at(i);
        }
        
    }
    
    return std::make_pair(minimumUtility, minimumUtilityNode);
    
}
 

BoardNode Ai::makeMove(Board board) {
    
    BoardNode rootNode;
    rootNode.copyFrom(board);
    generatePossibleMoves(rootNode, true);
    
    // Traverse tree with min max to make move decision
    std::pair<int, BoardNode> moveNode = maximize(rootNode);
    
    return moveNode.second;
}





