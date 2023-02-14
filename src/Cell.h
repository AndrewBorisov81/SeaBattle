#pragma once

class Cell {
public:
    Cell();
    virtual ~Cell();

    void setRow(int row);
    int getRow() const;
    void setColumn(int col);
    int getColumn() const;
    bool isEmpty() const;
    void setEmpty(bool empty);
private:
    int m_row;
    int m_column;
    bool m_isEmpty;
};
