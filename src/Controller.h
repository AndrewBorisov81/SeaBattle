#pragma once
#include <memory>
#include "Model.h"
#include "View.h"

class Controller {
public:
    Controller() = default;
    Controller(std::unique_ptr<Model> model, std::unique_ptr<View> view);
private:
    std::unique_ptr<Model> m_model;
    std::unique_ptr<View> m_view;
};
