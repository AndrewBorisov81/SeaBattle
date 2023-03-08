#pragma once
#include "IObserver.h"
#include "Subject.h"

class Observer : public IObserver {
public:
    Observer(Subject& subject);
    virtual ~Observer();
    void update() override;
private:
    Subject& m_subject;
    static int m_number;
};
