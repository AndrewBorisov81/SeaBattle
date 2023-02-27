#pragma once
#include <memory>
#include "GameBoard.h"

class Model {
public:
    Model() = default;
    Model(std::unique_ptr<GameBoard> gameBoard);
    virtual ~Model() = default;
private:
    std::unique_ptr<GameBoard> m_gameBoard;
};
