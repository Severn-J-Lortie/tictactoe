#include "Player.hpp"

Move Player::askForMove() {
    
    // Ask the player for their next move
    printf("Enter row, col of next move\n");
    int row, col;
    scanf("%d, %d", &row, &col);
    
    // Create a move object containing the next move
    Move move;
    move.setMove(row - 1, col - 1, PLAYER_PIECE);
    
    return move;
}
