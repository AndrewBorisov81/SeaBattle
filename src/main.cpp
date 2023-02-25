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
12, 12, 25, 25;   // rows, columns, rowWidth, rowHight - gameField
4, 1, 1, 0;       // four decks(four horizontal cells from beginCell), beginRowCell, beginColumnCell, isHorizontal - ship1
3, 3, 3, 1;       // three decks - ship2
2, 7, 1, 0;       // ship3
1, 12, 12, 0      // ship4
*/

int main()
{
   cout << "Hello Sea Battle!" << '\n';

   std::string gameLevel {"1; 12, 12, 25, 25; 4, 5, 5, 0; 3, 1, 2, 1;  2, 7, 1, 0; 1, 12, 12, 0"};

   Parser parser;
   std::tuple<int, FieldData, std::vector<ShipData>> levelParsedData = parser.parse(gameLevel);

   enum class InitData{field = 1, ships};
   std::unique_ptr<GameBoard> gameBoard 
       = GameBoard::create(std::get<static_cast<int>(InitData::field)>(levelParsedData), 
                           std::get<static_cast<int>(InitData::ships)>(levelParsedData), GameBoard::Owner::player);
   /*gameBoard->init(std::get<static_cast<int>(InitData::field)>(levelParsedData), 
                  std::get<static_cast<int>(InitData::ships)>(levelParsedData), GameBoard::Owner::player);*/
}
