#pragma once

#include "Cell.h"
#include "Ship.h"
#include "UtilityData.h"

#include <memory>
#include <vector>

class GameBoard {
public:
    enum class Owner{ player, computer, player1, player2 };
    // Input ship position
    enum class InputMode{ manual, autoRandom };

    GameBoard();
    ~GameBoard();

    static std::unique_ptr<GameBoard> create();
    void init(const FieldData& fieldData, const std::vector<ShipData>& shipsData, Owner owner);
    // Function for removing the playing and feeling memory
    void deleteBoard();

    void clear();
    void show();

    void setupShips();
    std::shared_ptr<Cell> getBoardSpace(int row, int col, int rows, int columns);
    std::vector<std::shared_ptr<Cell>> getShipPosition(std::shared_ptr<Cell> begin, std::shared_ptr<Cell> end);

    void attack(int row, int col);

    int getWidth() const { return m_width; }
    int getHeight() const { return m_height; }
    int getColumns() const { return m_columns; }
    int getRows() const { return m_rows; }

private:
    std::vector<std::shared_ptr<Cell>> m_board;
    std::vector<std::shared_ptr<Ship>> m_ships;
    std::vector<ShipData> m_shipData;
    Owner m_owner;
    InputMode m_inputMode;

    int m_columns;
    int m_rows;
    int m_height;
    int m_width;
};
