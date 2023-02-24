#include "Ship.h"

Ship::Ship()
    : m_type{Type::singleDeckShip},
      m_isDestroyed{false},
      m_isHorizontal{true},
      m_health{0}, 
      m_isHit{false}
{

}

Ship::Ship(Type type, std::vector<std::shared_ptr<Cell>> position, bool isHorizontal) 
    : m_type{type}, m_isHorizontal{isHorizontal},
      m_health{0}, m_isHit{false}, m_position{position} {

}

Ship::~Ship() {

}

std::shared_ptr<Ship> Ship::create(Type type, 
        std::vector<std::shared_ptr<Cell>> position, bool isHorizontal) {
    return std::make_unique<Ship>(type, position, isHorizontal);
}

void Ship::hit() {
    m_health--;
    
    if(m_health <= 0) {
        destroy();
    }
}

void Ship::setType(Type type) {
    m_type = type;
}

Ship::Type Ship::getType() const {
    return m_type;
}

void Ship::destroy() {
    m_isDestroyed = true;
}

bool Ship::isDestoryed() const {
    return m_isDestroyed;
}

bool Ship::isHorizontal() const {
    return m_isHorizontal;
}

bool Ship::isHit() const {
    return m_isHit;
}

const std::vector<std::shared_ptr<Cell>>& Ship::getPosition() {
    return m_position;
}
