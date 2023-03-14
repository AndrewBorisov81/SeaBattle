#pragma once
#include "IObserver.h"
#include "Subject.h"

#include <memory>

class Observer : public IObserver {
public:
    //Observer(Subject& subject);
    Observer() = default;
    Observer(std::shared_ptr<ISubject> subject);
    virtual ~Observer();
    void update() override;
private:
    //Subject& m_subject;
    std::shared_ptr<ISubject> m_subject;
    static int m_number;
};
