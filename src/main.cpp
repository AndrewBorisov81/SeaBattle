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

   //std::string gameLevel {"1; 12, 12, 25, 25; 4, 5, 5, 0; 3, 1, 2, 1;  2, 7, 1, 0; 1, 12, 12, 0"};
   std::string gameLevel {"123"};
   //std::string gameLevel {"abc"};

   Parser parser;
   std::tuple<int, FieldData, std::vector<ShipData>> levelParsedData = parser.parse(gameLevel);

   enum class InitData{field = 1, ships};
   std::unique_ptr<GameBoard> gameBoard = GameBoard::create();
   gameBoard->init(std::get<static_cast<int>(InitData::field)>(levelParsedData), 
                  std::get<static_cast<int>(InitData::ships)>(levelParsedData), GameBoard::Owner::player);

   // Test parse string
   /*std::string testString1 {"1; 12, 12; 5, 0"};
   std::string testString2 {"123;123"};
   std::string testString3 {"abc"};*/
   //std::string testString3 {"123"};
   std::string testString4{"abc;"};
   //std::string testString5{"abc"};
   std::queue<int> testQueue;
   parser.parseAlgorithm(testString4, std::string(";"), testQueue);
}
