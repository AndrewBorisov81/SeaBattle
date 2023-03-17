#pragma once
#include "IObserver.h"
#include "Subject.h"

#include <memory>

class Observer : public IObserver {
public:
    //Observer(Subject& subject);
    Observer() = default;
    Observer(std::shared_ptr<ISubject> subject);
    virtual ~Observer();
    /*void update(const GameBoard::CellsList& board,
    const GameBoard::ShipsList& ships, int rows, int columns) override;*/
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
private:
    //Subject& m_subject;
    std::shared_ptr<ISubject> m_subject;
    static int m_number;
};
