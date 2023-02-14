#pragma once
  
class Ship {
public:
    enum class Type { 
        singleDeckShip = 1, 
        doubleDeckShip = 2, 
        threeDeckShip = 3, 
        fourDeckShip = 4, 
    };

    Ship();
    ~Ship();

    void hit();

    void setType(Type type);
    Type getType() const;
    void destoryed(bool destroyed);
    bool isDestoryed() const;

private:
   Type m_type;
   bool m_isDestroyed;
};
