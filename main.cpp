#include <iostream>
#include "Board.hpp"
#include "BoardNode.hpp"
#include "Ai.hpp"
#include "Player.hpp"
#include "Move.hpp"

int main() {
    
    Board board;
    Ai ai;
    Player player;
    std::pair<bool, char> boardState;
    Move playerMove;
    
    bool playerTurn = true;
    for (int i = 0; i < 10; i++) {
        if (playerTurn) {
            printf("YOU: ");
            playerMove = player.askForMove();
            board.makeMove(playerMove);
            playerTurn = false;
        } else {
            printf("AI: Played\n");
            BoardNode aiMove = ai.makeMove(board);
            board = aiMove.toBoard();
            playerTurn = true;
        }
        board.display();
        boardState = board.hasGameBeenWon();
        if (boardState.first) {
            printf("\n");
            printf("%c HAS WON!\n", boardState.second);
            return 0; 
        }
    }
    printf("\n");
    printf("TIED GAME!\n");
    
    /*Move move;
    move.setMove(0, 0, AI_PIECE);
    board.makeMove(move);
    move.setMove(1, 1, PLAYER_PIECE);
    board.makeMove(move);
    
    board.display();
    BoardNode boardNode;
    boardNode.copyFrom(board);
    printf("%d\n", ai.calculateUtility(boardNode)); */

    
    return 0;
}
