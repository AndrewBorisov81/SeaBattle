#include "InputConsoleController.h"

#include <iostream>
#include <string>
#include <queue>

InputConsoleController::InputConsoleController()
    : m_rows{-1}, m_columns{-1}, m_startInput{false}
{
  
}

InputConsoleController::InputConsoleController(int rows, int columns)
    : m_rows{rows}, m_columns{columns}, m_startInput{false}
{
  
}

void InputConsoleController::startInput(const std::string& player) {
    m_startInput = true;

    if (m_startInput) {
        std::cout << player << " Choose a row number between 0 and 11\n";
            int getNumber{-1};
        char* checkBreakCh{nullptr};
        while(1) {
            getNumber = getInputNumber(checkBreakCh);
            //if(*checkBreakCh == '\n') break;
            if(getNumber >=0 && getNumber < m_rows) {
                break;
            }
        }
        //std::cout << player << " Choose a column number between 0 and 11\n";
        //std::cin >> m_column;
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

int InputConsoleController::getInputNumber(char* checkBreakCh) {
    char ch;
    char chDigit;
    std::string strDigit;
    int retInt{-1};
    while(1) {
        ch = std::cin.peek();
        checkBreakCh = &ch;
        if(ch == '\n') break;
        if(ch >= '0' && ch <= '9') {
            std::cin >> chDigit;
            strDigit.push_back(chDigit);
            continue;
        }
    }
    if(strDigit.length() > 0) {
        retInt = std::stoi(strDigit);
    }
    return retInt;
}
