#include "Parser.h"
#include <queue>
#include <vector>

Parser::Parser() {

}

void Parser::parse(std::string str) {
    std::tuple<int, FieldData, std::vector<ShipData>> parsedlevelData;
    std::queue<std::string> tokens;

    std::string delimeter = ";";
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimeter)) != std::string::npos) {
        token = str.substr(0, pos);
        tokens.push(token);
        str.erase(0, pos + delimeter.length());
    }
    token = str.substr(0, str.length());
    tokens.push(token);
    pos = 0;
    token.clear();

    int level = std::stoi(tokens.front());
    tokens.pop();

    FieldData fieldData;
    std::vector<int> parsedFieldData;
    std::string parseFieldData = tokens.front();
    tokens.pop();
    delimeter = ",";
    while ((pos = parseFieldData.find(delimeter)) != std::string::npos) {
        token = parseFieldData.substr(0, pos);
        parsedFieldData.push_back(std::stoi(token));
        parseFieldData.erase(0, pos + delimeter.length());
    }
    token = parseFieldData.substr(0, str.length());
    parsedFieldData.push_back(std::stoi(token));
    pos = 0;
    parseFieldData.clear();
    
    fieldData = {parsedFieldData.at(0), parsedFieldData.at(1), parsedFieldData.at(2), parsedFieldData.at(3)};

    std::vector<ShipData> shipsData;
}
