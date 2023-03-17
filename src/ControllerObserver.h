#pragma once
#include "Observer.h"
#include "Controller.h"

class ControllerObserver : public Observer, private Controller {
public:
    ControllerObserver() = default;
    ControllerObserver(std::shared_ptr<ISubject> subject,
        std::unique_ptr<Model> model, std::unique_ptr<View> view);
    virtual ~ControllerObserver() = default;
    void update(const GameBoard::CellsList& board,
    const GameBoard::ShipsList& ships, int rows, int columns) override;
};
