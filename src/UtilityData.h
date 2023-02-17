#pragma once

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

struct Position {
  int row{0};
  int column{0};

  Position(){}
  Position(int row, int col) : row{row}, column{col} {}
};

