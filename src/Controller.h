#pragma once
#include <memory>
#include "Model.h"
#include "View.h"
#include "IInputController.h"

class Controller {
    enum class Player{ player1, player2 };
public:
    Controller() = default;
    Controller(std::unique_ptr<Model> model, 
    std::unique_ptr<View> view);
    virtual ~Controller();
    // when application start
    void init();

private:
    std::unique_ptr<Model> m_model;
    std::unique_ptr<View> m_view;
    std::unique_ptr<IInputController> m_inputController;
    Controller::Player m_currentPlayer;
    bool m_gameOver;

    std::shared_ptr<GameBoard> getBoard1() const;
    std::shared_ptr<GameBoard> getBoard2() const;
    void changePlayer();
    bool checkGameOver();
};
