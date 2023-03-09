#pragma once
#include <memory>
#include "GameBoard.h"
#include "Subject.h"

class Model {
public:
    Model() = default;
    virtual ~Model() = default;

    bool init(const FieldData& fieldData, const std::vector<ShipData>& shipsData);

    std::shared_ptr<GameBoard> getBoard1() const;
    std::shared_ptr<GameBoard> getBoard2() const;

    bool shoot(int row, int column);

    void setSubject(std::shared_ptr<Subject> subject);
private:
    std::shared_ptr<GameBoard> m_board1;
    std::shared_ptr<GameBoard> m_board2;
    std::shared_ptr<Subject> m_subject;
};
