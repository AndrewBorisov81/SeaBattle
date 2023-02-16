#pragma once

#include <string>
#include "UtilityData.h"

class Parser {
public:
    Parser();
    std::tuple<int, FieldData, std::vector<ShipData>> parse(const std::string& str);
};
