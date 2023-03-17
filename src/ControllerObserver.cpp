#include "ControllerObserver.h"

ControllerObserver::ControllerObserver(std::shared_ptr<ISubject> subject,
    std::unique_ptr<Model> model, std::unique_ptr<View> view)
    :   Observer(subject),
        Controller(std::move(model), std::move(view))
{

}

void ControllerObserver::update(const GameBoard::CellsList& board,
    const GameBoard::ShipsList& ships, int rows, int columns)
{
    bool stop = true;    
}
