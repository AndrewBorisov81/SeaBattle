#include "Controller.h"
#include "InputConsoleController.h"
#include "Constants.h"

#include <string>

 Controller::Controller(std::unique_ptr<Model> model, 
    std::unique_ptr<View> view)
    : m_model{std::move(model)}, 
      m_view{std::move(view)},
      m_currentPlayer{Controller::Player::player1},
      m_gameOver{false}
{
    init();
}

Controller::~Controller() {

}

void Controller::init() {

    while (true) {
        if (auto board1 = getBoard1()) {
            std::shared_ptr<IInputController> m_inputController = 
            std::make_shared<InputConsoleController>(getBoard1()->getRows(), getBoard1()->getColumns());
    
            m_view->init(getBoard1()->getBoard(), getBoard1()->getShips(), 
                getBoard1()->getColumns(), getBoard1()->getRows());
            m_view->show(getBoard1()->getBoard(), getBoard1()->getShips(), 
                getBoard1()->getColumns(), getBoard1()->getRows());
    
            m_inputController->startInput(Constants::str_player1);
            int row = m_inputController->getRow();
            int column = m_inputController->getColumn();
    
            getBoard1()->attack(row, column);
            m_view->updateView(getBoard1()->getBoard(), getBoard1()->getShips()); 
        }
    }
}

std::shared_ptr<GameBoard> Controller::getBoard1() const {
  return m_model->getBoard1();
}

std::shared_ptr<GameBoard> Controller::getBoard2() const {
  return m_model->getBoard2();
}

void Controller::changePlayer() {
    if(m_currentPlayer == Controller::Player::player1) {
        m_currentPlayer = Controller::Player::player2;
    } else {
        m_currentPlayer = Controller::Player::player1;
    }
}
