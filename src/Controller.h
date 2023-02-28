#pragma once
#include <memory>
#include "Model.h"
#include "View.h"

class Controller {
public:
    Controller() = default;
    Controller(std::unique_ptr<Model> model, std::unique_ptr<View> view);
    virtual ~Controller() = default;
    // when application start
    void onLoad();
private:
    std::unique_ptr<Model> m_model;
    std::unique_ptr<View> m_view;

    std::shared_ptr<GameBoard> getBoard1() const;
    std::shared_ptr<GameBoard> getBoard2() const;
};
