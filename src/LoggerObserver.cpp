#include "LoggerObserver.h"

#include <iostream>

 LoggerObserver::LoggerObserver(std::shared_ptr<ISubject> subject) {

 }
 LoggerObserver::~LoggerObserver() {

 }

void LoggerObserver::update(const std::vector<std::shared_ptr<Cell>>& board,
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns)
{
    std::cout << "LoggerObserver Update!" << '\n';
}
