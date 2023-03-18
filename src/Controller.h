#pragma once
#include "Observer.h"
#include "Model.h"
#include "IView.h"
#include "IInputController.h"

#include <memory>

class Controller {
    enum class Player{ player1, player2 };
public:
    Controller() = default;
    Controller(std::shared_ptr<Model> model, 
    std::unique_ptr<IView> view);
    virtual ~Controller();
    // when application start
    void init();
    void updateData();

protected:
    std::unique_ptr<IView> m_view;

private:
    std::shared_ptr<Model> m_model;
    std::unique_ptr<IInputController> m_inputController;
    Controller::Player m_currentPlayer;
    bool m_gameOver;

    std::shared_ptr<GameBoard> getBoard1() const;
    std::shared_ptr<GameBoard> getBoard2() const;
    void changePlayer();
    bool checkGameOver();
    void gameOver();
};
