#pragma once
#include "IObserver.h"
#include "ISubject.h"

class ViewObserver : public IObserver {
public:
    ViewObserver() = default;
    ViewObserver(std::shared_ptr<ISubject> subject);
    virtual ~ViewObserver();
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
    const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
private:
    std::shared_ptr<ISubject> m_subject;
};
