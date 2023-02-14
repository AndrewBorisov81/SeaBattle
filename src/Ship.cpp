#include "Ship.h"

Ship::Ship() {

}
Ship::~Ship() {

}

void Ship::hit() {

}

void Ship::setType(Type type) {
    m_type = type;
}

Ship::Type Ship::getType() const {
    return m_type;
}

void Ship::destoryed(bool destroyed) {
    m_isDestroyed = destroyed;
}

bool Ship::isDestoryed() const {
    return m_isDestroyed;
}
