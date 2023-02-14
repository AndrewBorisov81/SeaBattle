#include "GameBoard.h"

GameBoard::GameBoard()
    : m_columns{15}, m_rows{15},
      m_height{15}, m_width{15} {

}

GameBoard::~GameBoard() {

}

std::unique_ptr<GameBoard> GameBoard::create() {
    return std::make_unique<GameBoard>();
}

void GameBoard::deleteBoard() {

}

void GameBoard::clear() {

}

void GameBoard::show() {

}

void GameBoard::attack(int x, int y) {

}

void GameBoard::setupShips() {

}

std::unique_ptr<Cell> GameBoard::getBoardSpace(int row, int col, int rows, int columns) {
    int elemIndex = (m_board.size()/columns) * row + col; 
    // Check the boundaries of the array
    if(row < 0 || row >= m_rows || col < 0 || col >= m_columns) {
        return nullptr;
    } else {
        return std::move(m_board.at(elemIndex));
    }
}
