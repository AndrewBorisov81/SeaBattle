#pragma once

class IInputController {
public:
    virtual void startInput() = 0;
    virtual void stopInput() = 0;
    virtual int getRow() const = 0;
    virtual int getColumn() const = 0;
    virtual ~IInputController() = default;
};
