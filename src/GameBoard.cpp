#include "GameBoard.h"

GameBoard::GameBoard()
    : m_columns{0}, m_rows{0},
      m_height{0}, m_width{0} {

}

GameBoard::~GameBoard() {

}

std::unique_ptr<GameBoard> GameBoard::create() {
    return std::make_unique<GameBoard>();
}

void GameBoard::init(const FieldData& fieldData, const std::vector<ShipData>& shipsData, Owner owner) {
     m_columns = fieldData.columns;
     m_rows = fieldData.rows;
     m_width = fieldData.rowWidth;
     m_height = fieldData.rowHeight;
     m_shipData = shipsData;
}

void GameBoard::deleteBoard() {

}

void GameBoard::clear() {
    m_board.clear();
}

void GameBoard::show() {

}

void GameBoard::attack(int x, int y) {

}

void GameBoard::setupShips() {
    int numElem = m_rows * m_columns;
    m_board.reserve(numElem);
}

// ???return const ref
std::shared_ptr<Cell> GameBoard::getBoardSpace(int row, int col, int rows, int columns) {
    int elemIndex = (m_board.size()/columns) * row + col; 
    // Check the boundaries of the array
    if(row < 0 || row >= m_rows || col < 0 || col >= m_columns) {
        return nullptr;
    } else {
        return m_board.at(elemIndex);
    }
}

// ???return const ref
std::vector<std::shared_ptr<Cell>> GameBoard::getShipPosition(const Position& pos, int numberDecks, bool horizontal) {
     return {};   
}
