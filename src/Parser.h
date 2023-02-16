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
  bool direction;
};

class Parser {
public:
    Parser();
    void parse(std::string str);
};
