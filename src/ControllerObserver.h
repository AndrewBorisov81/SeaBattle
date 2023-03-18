#pragma once
#include "Observer.h"
#include "IObserver.h"

#include <vector>

class ControllerObserver : public IObserver {
public:
    ControllerObserver() = default;
    ControllerObserver(std::shared_ptr<ISubject> subject);
    virtual ~ControllerObserver();
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
private:
    std::shared_ptr<ISubject> m_subject;
};
