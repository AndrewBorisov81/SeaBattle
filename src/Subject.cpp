#include "Subject.h"
#include "IObserver.h"

Subject::Subject() {

}

Subject::~Subject() {

}

void Subject::attach(IObserver* observer) {
    m_observers.push_front(observer);
}

void Subject::detach(IObserver* observer) {
   m_observers.remove(observer);
}

void Subject::notify() {
    for (auto& o: m_observers) {
        o->update();
    }
}
