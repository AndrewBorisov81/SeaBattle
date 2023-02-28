#include "Controller.h"

Controller::Controller(std::unique_ptr<Model> model, std::unique_ptr<View> view)
    : m_model{std::move(model)}, m_view{std::move(view)}
{
    onLoad();
}

void Controller::onLoad() {
    m_view->init(getBoard1()->getBoard(), getBoard1()->getShips(), 
        getBoard1()->getColumns(), getBoard1()->getRows());
    m_view->show(getBoard1()->getBoard(), getBoard1()->getShips(), 
        getBoard1()->getColumns(), getBoard1()->getRows());
}


std::shared_ptr<GameBoard> Controller::getBoard1() const {
  return m_model->getBoard1();
}

std::shared_ptr<GameBoard> Controller::getBoard2() const {
  return m_model->getBoard2();
}
