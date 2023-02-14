#include "Cell.h"

Cell::Cell() {

}

Cell::~Cell() {

}

void Cell::setRow(int row) {
    m_row = row;
}

int Cell::getRow() const {
    return m_row;
}

void Cell::setColumn(int col){
   m_column = col;
}

int Cell::getColumn() const {
    return m_column;
}

void Cell::setEmpty(bool empty) {
    m_isEmpty = empty;
}

bool Cell::isEmpty() const {
    return m_isEmpty;
}
