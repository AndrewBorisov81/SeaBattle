#pragma once
#include "IObserver.h"
#include "ISubject.h"

class LoggerObserver : public IObserver {
public:
    LoggerObserver() = default;
    LoggerObserver(std::shared_ptr<ISubject> subject);
    virtual ~LoggerObserver();
    virtual void update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns) override;
private:
    std::shared_ptr<ISubject> m_subject;
};
