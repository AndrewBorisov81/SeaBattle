#pragma once

#include "ISubject.h"
#include <forward_list>

class Subject: public ISubject {
public:
    Subject();
    virtual ~Subject();
    void attach(IObserver* observer) override;
    void detach(IObserver* observer) override;
    void notify() override;
private:
    std::forward_list<IObserver*> m_observers;
};
