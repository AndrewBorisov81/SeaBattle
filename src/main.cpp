#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Parser.h"
#include "GameBoard.h"

using namespace std;

// how to get and hold data to ship

/*
1;
12, 12, 25, 25;
4, 5, 5, 0;
3, 1, 2, 1;
2, 7, 1, 0;
1, 12, 12, 0
*/

int main()
{
   cout << "Hello Sea Battle!" << '\n';

   std::string gameLevel {"1; 12, 12, 25, 25; 4, 5, 5, 0; 3, 1, 2, 1;  2, 7, 1, 0; 1, 12, 12, 0"};

   Parser parser;
   std::tuple<int, FieldData, std::vector<ShipData>> levelParsedData = parser.parse(gameLevel);

   std::unique_ptr<GameBoard> gameBoard = GameBoard::create();
   gameBoard->init(std::get<1>(levelParsedData), std::get<2>(levelParsedData), GameBoard::Owner::player);
}
