#include "GameBoard.h"

GameBoard::GameBoard()
    : m_fieldData{}, m_owner{GameBoard::Owner::player1},
      m_inputMode{GameBoard::InputMode::manual}
{

}

GameBoard::GameBoard(const FieldData& fieldData,
                     const std::vector<ShipData>& shipData, Owner owner)
    : m_fieldData{fieldData.rows, fieldData.columns},
      m_shipsData{shipData}, m_owner{owner}
{
    setupCells();
    setupShips();
}

GameBoard::~GameBoard() {

}

std::unique_ptr<GameBoard> GameBoard::create(const FieldData& fieldData, 
                                             const std::vector<ShipData>& shipsData, Owner owner) {
    return std::make_unique<GameBoard>(fieldData, shipsData, owner);
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

void GameBoard::setupCells() {
    int numElem = m_fieldData.rows * m_fieldData.columns;
    m_board.reserve(numElem);

    for(int i = 0; i < m_fieldData.rows; i++) {
        for (int j = 0; j  < m_fieldData.columns; j++) {
           std::shared_ptr<Cell> cell = std::make_shared<Cell>(i, j);
           m_board.emplace_back(cell);
        }
    }
}

void GameBoard::setupShips() {
    for(auto shipData: m_shipsData) {
        std::shared_ptr<Ship> ship = std::make_unique<Ship>();
        m_ships.emplace_back(ship);
    }
}

const std::shared_ptr<Cell>& GameBoard::getBoardSpace(int row, int col) {
    int index = (m_board.size()/m_fieldData.columns) * row + col; 
    return m_board.at(index);
}

 bool GameBoard::getShipPosition(const Position& pos, 
    int numberDecks, bool horizontal, std::vector<std::shared_ptr<Cell>>& shipPosition) {
    for(int i = 0; i < numberDecks; i++) {
        if(pos.column >= m_fieldData.columns || pos.column < 0 || pos.column + i >= m_fieldData.columns) {
            return false;
        };
        if(pos.row < 0 || pos.row >= m_fieldData.rows || pos.row + i >= m_fieldData.rows) {
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
