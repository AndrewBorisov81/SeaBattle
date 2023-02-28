#include "Controller.h"

Controller::Controller(std::unique_ptr<Model> model, std::unique_ptr<View> view)
    : m_model{std::move(model)}, m_view{std::move(view)}
{

}

void Controller::onLoad() {
    //m_view->init();
    m_view->show();
}
