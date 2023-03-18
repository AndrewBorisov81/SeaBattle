#pragma once

#include <vector>

class Cell;
class Ship;

class IView {
public:
    virtual void updateView(const std::vector<std::shared_ptr<Cell>>& board,
         const std::vector<std::shared_ptr<Ship>>& ships) = 0;
    virtual bool init(const std::vector<std::shared_ptr<Cell>>& board, 
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) = 0;
    virtual void show(const std::vector<std::shared_ptr<Cell>>& board) = 0;
    virtual void show(const std::vector<std::shared_ptr<Cell>>& board, 
        const std::vector<std::shared_ptr<Ship>>& ships, 
            int rows, int columns) = 0;
    virtual ~IView() {}
};
