#pragma once
#include <memory>
#include "Model.h"
#include "View.h"

class Controller {
public:
    Controller() = default;
    Controller(std::unique_ptr<Model> model, std::unique_ptr<View> view);
    virtual ~Controller() = default;

    bool init(const FieldData& fieldData, const std::vector<ShipData>& shipsData);
private:
    std::unique_ptr<Model> m_model;
    std::unique_ptr<View> m_view;

    std::unique_ptr<GameBoard> m_board1;
    std::unique_ptr<GameBoard> m_board2;
};
