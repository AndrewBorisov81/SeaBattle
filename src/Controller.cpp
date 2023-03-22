#include "Controller.h"
#include "InputConsoleController.h"
#include "Constants.h"

#include <string>
#include <iostream>

 Controller::Controller(std::shared_ptr<Model> model, 
    std::shared_ptr<IView> view)
    : m_view{view},
      m_model{model}, 
      m_currentPlayer{Controller::Player::player1},
      m_gameOver{false},
      m_state{State::init}
{
    init();
}

Controller::~Controller() {

}

void Controller::init() {
    if(auto board1 = getBoard1()) {
        m_view->init(board1->getBoard(), board1->getShips(), 
            board1->getColumns(), board1->getRows());
        m_view->show(board1->getInitBoard());
    }

    /*while (true && !m_gameOver) {
        if (auto board1 = getBoard1()) {
            std::shared_ptr<IInputController> m_inputController = 
            std::make_shared<InputConsoleController>(board1->getRows(), board1->getColumns());
    
            m_inputController->startInput(Constants::str_player1);
            int row = m_inputController->getRow();
            int column = m_inputController->getColumn();
    
            board1->attack(row, column);
            m_model->updatedBoardData(board1->getBoard(), board1->getShips(), 
                board1->getColumns(), board1->getRows());

            m_gameOver = board1->isShipsDestroyed();
        }
    }*/
}

std::shared_ptr<GameBoard> Controller::getBoard1() const {
  return m_model->getBoard1();
}

void Controller::changeState(State state) {
    switch (state) {
        case State::init:
            m_state = State::init;
            init();
            changeState(State::playerOneTurn);
            break;

        case State::playerOneTurn:
            m_state = State::playerOneTurn;
            //changeState(State::playerTwoTurn);
            break;

        case State::playerTwoTurn:
            m_state = State::playerTwoTurn;
            changeState(State::playerOneTurn);
            break;

        case State::GameOver:
            //m_state = State::GameOver;
            break;
    
        default:
           break;
    }
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

bool Controller::checkGameOver() {
    if(auto board = m_model->getBoard1()) {
        if(bool allShipsDestoryed = board->isShipsDestroyed()) {
            gameOver();
            return true;                        
        }
    }
    return false;
}

void Controller::gameOver() {
    std::cout << "Game Over!" << '\n';
}
