#include "GameBoard.h"

GameBoard::GameBoard()
    : m_rows{0}, m_columns{0},
      m_width{0}, m_height{0}
{

}

GameBoard::GameBoard(const FieldData& fieldData,
                     const std::vector<ShipData>& shipData, Owner owner)
    : m_rows{fieldData.rows}, m_columns{fieldData.columns}, 
      m_width{fieldData.rowWidth}, m_height{fieldData.rowHeight},
      m_shipData{shipData}, m_owner{owner}
{
      
    for (int row = 0; row < m_rows; row++) {
        for (int col = 0; col < m_columns; col++) {
            m_board.emplace_back(std::make_shared<Cell>());
        }
    }
      setupShips();
}

GameBoard::~GameBoard() {

}

std::unique_ptr<GameBoard> GameBoard::create(const FieldData& fieldData, 
                                             const std::vector<ShipData>& shipData, Owner owner) {
    return std::make_unique<GameBoard>(fieldData, shipData, owner);
}

/*void GameBoard::init(const FieldData& fieldData, const std::vector<ShipData>& shipsData, Owner owner) {
     m_columns = fieldData.columns;
     m_rows = fieldData.rows;
     m_width = fieldData.rowWidth;
     m_height = fieldData.rowHeight;
     m_shipData = shipsData;
}*/

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

 bool GameBoard::getShipPosition(const Position& pos, 
    int numberDecks, bool horizontal, std::vector<std::shared_ptr<Cell>>& shipPosition) {
    for(int i = 0; i < numberDecks; i++) {
        if(pos.column >= m_columns || pos.column < 0 || pos.column + i >= m_columns) {
            return false;
        };
        if(pos.row < 0 || pos.row >= m_rows || pos.row + i >= m_rows) {
            return false;
        }
        std::shared_ptr<Cell> cell = std::make_shared<Cell>();
        if (horizontal) {
            cell->setRow(pos.column);
            cell->setColumn(pos.row + i);
        } else {
            cell->setRow(pos.column + i);
            cell->setColumn(pos.row);
        }
        shipPosition.push_back(cell);
    }
    return true;
}

