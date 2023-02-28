#pragma once

#include <vector>

class Cell;

class IView {
    void updateView(const std::vector<std::shared_ptr<Cell>>& board);
    void show();
};
