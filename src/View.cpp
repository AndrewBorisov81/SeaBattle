#include "View.h"
#include "Cell.h"
#include "Ship.h"

#include <iostream>

View::View(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) 
    : m_board{board}, m_ships{ships}, m_rows{rows}, m_columns{columns}
{

}

void View::updateView(const std::vector<std::shared_ptr<Cell>>& board, 
    const std::vector<std::shared_ptr<Ship>>& ships) {
    m_board = board;
    m_ships = ships;
    show();
}

void View::show() {
    const int numElements = m_board.size();
    for (int i = 0; i < m_rows; i++) {
        for (int j = 0; j < m_columns; j++) {
            int indexElem = numElements/m_rows * i + j;
            std::shared_ptr<Cell> cell = m_board.at(indexElem);
            std::cout << getChar(cell) << " ";
        }
        std::cout << std::endl;
    }
}

void View::clear() {

}

const char* View::getChar(std::shared_ptr<Cell> cell) {
    const char* ch = "0";
    switch(cell->getType()) {
        case Cell::Type::Empty:
            ch = "0";
            break;
        case Cell::Type::Ship:
            ch = "X";
            break;
        case Cell::Type::Hit:
            ch = "X";   
            break;
        case Cell::Type::DestroyedShip:
            ch = "X";
            break;
        case Cell::Type::Missed:
            ch = ".";
            break;
    }
    return ch;
}

const char* View::getShipChar(std::shared_ptr<Cell> cell) {
    const char* ch = "1";
    return ch;
}
