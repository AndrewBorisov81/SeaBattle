#include "Controller.h"

Controller::Controller(std::unique_ptr<Model> model, std::unique_ptr<View> view)
    : m_model{std::move(model)}, m_view{std::move(view)}
{

}

bool Controller::init(const FieldData& fieldData, const std::vector<ShipData>& shipsData) {
    m_board1 = GameBoard::create(fieldData, shipsData, GameBoard::Owner::player1);
    m_board2 = GameBoard::create(fieldData, shipsData, GameBoard::Owner::player2);
    return true;
}
