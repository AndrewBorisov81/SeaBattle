#include "InputConsoleController.h"

#include <iostream>

InputConsoleController::InputConsoleController()
    : m_row{0}, m_column{0}, m_startInput{false}
{
  
}

void InputConsoleController::startInput() {
    m_startInput = true;

    if(m_startInput) {
        std::cout << "Choose a row number between 0 and 11\n";
        std::cin >> m_row;

        std::cout << "Choose a column number between 0 and 12\n";
        std::cin >> m_column;
    }

   m_startInput = false;
}

void InputConsoleController::stopInput() {
    m_startInput = false;
}

int InputConsoleController::getRow() const {
    return 0;
}

int InputConsoleController::getColumn() const {
    return 0;
}
