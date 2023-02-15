#pragma once

#include <memory>
#include <vector>
#include "Cell.h"

class GameBoard {
public:
    enum class Owner{ player, computer, player1, player2 };
    // Input ship position
    enum class InputMode{ manual, autoRandom };

    GameBoard();
    ~GameBoard();

    static std::unique_ptr<GameBoard> create();
    // Function for removing the playing and feeling memory
    void deleteBoard();

    void clear();
    void show();

    void setupShips();
    std::shared_ptr<Cell> getBoardSpace(int row, int col, int rows, int columns);

    void attack(int row, int col);

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getColumns() const { return m_columns; }
    int getRows() const { return m_rows; }

private:
    std::vector<std::shared_ptr<Cell>> m_board;
    Owner m_owner;
    InputMode m_inputMode;

    int m_columns;
    int m_rows;
    int m_height;
    int m_width;
};
