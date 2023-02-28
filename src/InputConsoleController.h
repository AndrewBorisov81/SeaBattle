#pragma once

#include "IInputController.h"

class InputConsoleController : public IInputController {
public:
    InputConsoleController();
    virtual ~InputConsoleController() = default;

    virtual void startInput(const std::string& player) override;
    virtual void stopInput() override;
    virtual int getRow() const override;
    virtual int getColumn() const override;
private:
  int m_row;
  int m_column;
  bool m_startInput;
};
