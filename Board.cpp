#include "Board.hpp"

Board::Board() {

    // Fill board with empty control character 'u'
    board.fill({'u', 'u', 'u'});
    
}

// Set a piece at a position on the board
void Board::makeMove(Move move) {
    board.at(move.getPosition().at(0)).at(move.getPosition().at(1)) = move.getPiece();
}

// Get a piece at a position on the board
char Board::getPieceAtPosition(int row, int col) {
    return board.at(row).at(col);
}

// Display the board to standard out
void Board::display() {
 
    int c = 0;
    for (int i = 0; i < BOARD_SIZE + 2; i++) {
        
        if (i % 2 == 0) {
            
            for (int j = 0; j < BOARD_SIZE; j++) {
               
                char piece = getPieceAtPosition(c, j);
                
                if (piece == 'u') {
                    printf(" ");
                } else {
                    printf("%c", piece);
                }
                
                if (j < BOARD_SIZE - 1) {
                    printf("|");
                }
            }
        
            c++;
        } else {
            
            for (int j = 0; j < BOARD_SIZE; j++) {
                printf("- ");
            }
            
        }
        printf("\n");
        
    }
}

// TODO: Get rid of this
std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> Board::getBoard() {
    return board;
}

void Board::copyFrom(Board board) {
    this->board = board.getBoard();
}

std::pair<bool, char> Board::isSequenceWinning(std::array<char, BOARD_SIZE> sequence) {
    
    if (sequence == std::array<char, BOARD_SIZE> {AI_PIECE, AI_PIECE, AI_PIECE}) {
        return std::make_pair(true, AI_PIECE);
    }
    
    if (sequence == std::array<char, BOARD_SIZE> {PLAYER_PIECE, PLAYER_PIECE, PLAYER_PIECE}) {
        return std::make_pair(true, PLAYER_PIECE);
    }
    return std::make_pair(false, ' ');
}

std::pair<bool, char> Board::hasGameBeenWon() {
    
    std::array<char, BOARD_SIZE> sequence;
    std::pair<bool, char> sequenceState;
    
    // Check rows for x or o win
    for (int i = 0; i < BOARD_SIZE; i++) {
        sequenceState = isSequenceWinning(getRow(i));
        if (sequenceState.first) {
            return sequenceState;
        }
    }
    
    // Check cols for x or o win
    for (int i = 0; i < BOARD_SIZE; i++) {
        sequenceState = isSequenceWinning(getColumn(i));
        if (sequenceState.first) {
            return sequenceState;
        }
    }
    
    // Check left to right diagonal for x or o win
    for (int i = 0; i < BOARD_SIZE; i++) {
        sequence.at(i) = getPieceAtPosition(i, i);
    }
    sequenceState = isSequenceWinning(sequence);
    if (sequenceState.first) {
        return sequenceState;
    }
    
    
    // Check right to left diagonal for x or o win
    for (int i = 0; i < BOARD_SIZE; i++) {
        sequence.at(i) = getPieceAtPosition(i, BOARD_SIZE - i - 1);
    }
    sequenceState = isSequenceWinning(sequence);
    if (sequenceState.first) {
        return sequenceState;
    }
    
    return sequenceState;
}


void Board::setBoard(std::array<std::array<char, BOARD_SIZE>, BOARD_SIZE> board) {
    this->board = board;
}

std::array<char, BOARD_SIZE> Board::getRow(int row) {
    
    return board.at(row);
    
}

std::array<char, BOARD_SIZE> Board::getColumn(int col) {
    
    std::array<char, BOARD_SIZE> column;
    for (int i = 0; i < BOARD_SIZE; i++) {
        column.at(i) = getPieceAtPosition(i, col);
    }
    
    return column;
    
}
