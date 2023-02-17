#include "Parser.h"
#include <queue>
#include <vector>

Parser::Parser() {

}

std::tuple<int, FieldData, std::vector<ShipData>> Parser::parse(const std::string& str) {
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
    if(!levelData.empty()) {
        token = levelData.substr(0, levelData.length());
        tokens.push(token);
    }
    pos = 0;
    token.clear();

    int level{0};
    if (!tokens.empty()) {
        level = std::stoi(tokens.front());
        tokens.pop();
    }

    enum class FieldAttr{rows = 0, columns, width, height};
    FieldData fieldData = {};
    if(!tokens.empty()) {
        std::vector<int> parsedFieldData;
        std::string parseFieldData = tokens.front();
        tokens.pop();
        delimeter = ",";
        while ((pos = parseFieldData.find(delimeter)) != std::string::npos) {
            token = parseFieldData.substr(0, pos);
            parsedFieldData.push_back(std::stoi(token));
            parseFieldData.erase(0, pos + delimeter.length());
        }
        if(!parseFieldData.empty()) {
            token = parseFieldData.substr(0, str.length());
            parsedFieldData.push_back(std::stoi(token));
        }
        pos = 0;
        parseFieldData.clear();
    
        if(parsedFieldData.size() >= 4) {
            fieldData = {parsedFieldData.at(static_cast<int>(FieldAttr::rows)), 
            parsedFieldData.at(static_cast<int>(FieldAttr::columns)), 
            parsedFieldData.at(static_cast<int>(FieldAttr::width)),
            parsedFieldData.at(static_cast<int>(FieldAttr::height))};
        }
    }

    std::vector<ShipData> shipsData;
    enum class ShipAttr{type = 0, initRow, initColumn, direction};
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
        if(!parseShipData.empty()) {
            token = parseShipData.substr(0, str.length());
            parsedShipData.push_back(std::stoi(token));
        }
        pos = 0;
        parseShipData.clear();
        if(parsedShipData.size() >= 4) {
            ShipData shipData{parsedShipData.at(static_cast<int>(ShipAttr::type)), 
            parsedShipData.at(static_cast<int>(ShipAttr::initRow)), 
            parsedShipData.at(static_cast<int>(ShipAttr::initColumn)), 
            parsedShipData.at(static_cast<int>(ShipAttr::direction))};
            shipsData.push_back(shipData);
        }
    }
    return std::tuple<int, FieldData, std::vector<ShipData>>{level, fieldData, shipsData};
}

void Parser::parseAlgorithm(const std::string& stringToParse, const std::string& delimeter, std::queue<int>& returnParsedData) {
    std::queue<std::string> tokens;
    std::string stringData = stringToParse;

    size_t pos = 0;
    std::string token;
    while ((pos = stringData.find(delimeter)) != std::string::npos) {
        token = stringData.substr(0, pos);
        tokens.push(token);
        stringData.erase(0, pos + delimeter.length());
    }
    if (!stringData.empty()) {
        token = stringData.substr(0, stringData.length());
        tokens.push(token);
    }
}
