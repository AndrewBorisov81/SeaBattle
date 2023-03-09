#include "Model.h"

bool Model::init(const FieldData& fieldData, const std::vector<ShipData>& shipsData) {
    m_board1 = GameBoard::create(fieldData, shipsData, GameBoard::Owner::player1);
    m_board2 = GameBoard::create(fieldData, shipsData, GameBoard::Owner::player2);
    return true;
}

std::shared_ptr<GameBoard> Model::getBoard1() const {
    return m_board1;
}

std::shared_ptr<GameBoard> Model::getBoard2() const {
    return m_board2;
}

void Model::setSubject(std::shared_ptr<Subject> subject) {
    m_subject = subject;
}

bool Model::shoot(int row, int column) {

}
