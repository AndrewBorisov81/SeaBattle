#pragma once
#include "IView.h"
#include "Cell.h"
#include "Ship.h"
#include "Observer.h"

#include <vector>
#include <memory>
class View : public IView {
public:
    View() = default;
    View(const std::vector<std::shared_ptr<Cell>>& board, 
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
    virtual ~View() = default;
    bool init(const std::vector<std::shared_ptr<Cell>>& board, 
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
    void updateView(const std::vector<std::shared_ptr<Cell>>& board,
         const std::vector<std::shared_ptr<Ship>>& ships);
    void show(const std::vector<std::shared_ptr<Cell>>& board);
    void show(const std::vector<std::shared_ptr<Cell>>& board, 
        const std::vector<std::shared_ptr<Ship>>& ships, int rows, int columns);
    void clear();

    void setObserver(std::shared_ptr<Observer> observer);
private:
   std::vector<std::shared_ptr<Cell>> m_board;
   std::vector<std::shared_ptr<Ship>> m_ships;
   int m_rows;
   int m_columns;
   std::shared_ptr<Observer> m_observer;

   const char* getChar(std::shared_ptr<Cell> cell);
   const char* getShipChar(std::shared_ptr<Cell> cell);
};
