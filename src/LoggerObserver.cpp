#include "LoggerObserver.h"

#include <iostream>

 LoggerObserver::LoggerObserver(std::shared_ptr<ISubject> subject) 
     : m_subject{subject}
 {
    m_subject->attach(this);
 }
 LoggerObserver::~LoggerObserver() {
    m_subject->detach(this);
 }

void LoggerObserver::update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    std::cout << "LoggerObserver Update!" << '\n';
}
