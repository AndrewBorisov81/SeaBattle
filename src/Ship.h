#pragma once

#include <memory>
#include <vector>

class Cell;
  
class Ship {
public:
    enum class Type { 
        singleDeckShip = 1, 
        doubleDeckShip = 2, 
        threeDeckShip = 3, 
        fourDeckShip = 4, 
    };

    Ship();
    Ship(Type type, std::vector<std::shared_ptr<Cell>> position, bool isHorizontal);
    ~Ship();

    std::unique_ptr<Ship> create(Type type, std::vector<std::shared_ptr<Cell>> position);

    void hit();

    void setType(Type type);
    Type getType() const;
    bool isDestoryed() const;
    bool isHorizontal() const;

private:
   Type m_type;
   bool m_isDestroyed;
   bool m_isHorizontal;
   int m_health;
   std::vector<std::shared_ptr<Cell>> m_position;

   void destroy();
};
