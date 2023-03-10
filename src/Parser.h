#pragma once

#include <string>
#include <queue>
#include "UtilityData.h"

class Parser {
public:
    Parser();
    std::tuple<int, FieldData, std::vector<ShipData>> parse(const std::string& str);
    void parseAlgorithm(const std::string& stringToParse, 
                               const std::string& delimeter, std::queue<std::string>& returnParsedData);
};
