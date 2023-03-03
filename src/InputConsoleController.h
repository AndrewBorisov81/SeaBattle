#pragma once

#include "IInputController.h"

class InputConsoleController : public IInputController {
public:
    InputConsoleController();
    InputConsoleController(int rows, int columns);
    virtual ~InputConsoleController() = default;

    virtual void startInput(const std::string& player) override;
    virtual void stopInput() override;
    virtual int getRow() const override;
    virtual int getColumn() const override;
private:
  int m_rows;
  int m_columns;
  bool m_startInput;

  int getInputNumber(char* checkBreakCh);
};
