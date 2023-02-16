#pragma once

#include <string>

struct FieldData {
    int rows;
    int columns;
    int rowWidth;
    int rowHeight;
};

struct ShipData {
  int type;
  int initRow;
  int initColumn;
  int direction;
};

class Parser {
public:
    Parser();
    std::tuple<int, FieldData, std::vector<ShipData>> parse(const std::string& str);
};
