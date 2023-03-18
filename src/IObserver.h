#pragma once
#include <vector>

class Cell;
class Ship;

class IObserver {
    //using CellsList = std::vector<std::shared_ptr<Cell>>;
    //using ShipsList = std::vector<std::shared_ptr<Ship>>;
public:
    virtual ~IObserver() = default;
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) = 0;
};
