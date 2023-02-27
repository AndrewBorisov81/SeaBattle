#pragma once

#include <vector>
#include <memory>
#include "Cell.h"
class View {
public:
    View() = default;
    View(const std::vector<std::shared_ptr<Cell>>& board);
    void updateView(const std::vector<std::shared_ptr<Cell>>& board);
    void show();
    virtual ~View() = default;
private:
};

