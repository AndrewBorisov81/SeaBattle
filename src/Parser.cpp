#include "Parser.h"
#include <queue>
#include <vector>

Parser::Parser() {

}

std::tuple<int, FieldData, std::vector<ShipData>> Parser::parse(const std::string& str) {
    //std::tuple<int, FieldData, std::vector<ShipData>> parsedlevelData;
    std::queue<std::string> tokens;
    std::string levelData = str;

    std::string delimeter = ";";
    size_t pos = 0;
    std::string token;
    while ((pos = levelData.find(delimeter)) != std::string::npos) {
        token = levelData.substr(0, pos);
        tokens.push(token);
        levelData.erase(0, pos + delimeter.length());
    }
    token = levelData.substr(0, levelData.length());
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
    
    if(parsedFieldData.size() >= 4) {
        fieldData = {parsedFieldData.at(0), parsedFieldData.at(1), parsedFieldData.at(2), parsedFieldData.at(3)};
    }

    std::vector<ShipData> shipsData;
    
    while(!tokens.empty()){
        std::string parseShipData = tokens.front();
        tokens.pop();
        delimeter = ",";
        std::vector<int> parsedShipData;
        while ((pos = parseShipData.find(delimeter)) != std::string::npos) {
            token = parseShipData.substr(0, pos);
            parsedShipData.push_back(std::stoi(token));
            parseShipData.erase(0, pos + delimeter.length());
        }
        token = parseShipData.substr(0, str.length());
        parsedShipData.push_back(std::stoi(token));
        pos = 0;
        parseShipData.clear();
        if(parsedShipData.size() >= 4) {
            ShipData shipData{parsedShipData.at(0), parsedShipData.at(1), parsedShipData.at(2), parsedShipData.at(3)};
            shipsData.push_back(shipData);
        }
    }
    return std::tuple<int, FieldData, std::vector<ShipData>>{level, fieldData, shipsData};
}
