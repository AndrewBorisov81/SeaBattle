#pragma once
#include "Subject.h"
#include "Model.h"

class ModelSubject : public Subject, private Model {
public:
    ModelSubject();
    virtual ~ModelSubject() = default;
};
