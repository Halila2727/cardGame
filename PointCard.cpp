#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"
#include "PointCard.hpp"

PointCard::PointCard() : Card::Card()
{
    setType(POINT_CARD);
}

bool PointCard::isPlayable()
{
    if(getDrawn() == false)
    {
        return false;
    }
    
    if(!isNumber(getInstruction()))
    {
        return false;
    }
    
    return true;
}

void PointCard::Print() const
{
    std::cout << "Type: " << getType();
    std::cout << "\nPoints: " << getInstruction();
    std::cout << "\nCard: \n";
    std::cout << getImageData();
}


template<typename T>
bool isNumber(T x)
{
    std::string s;
    std::regex e ("^-?\\d+");
    std::stringstream ss; 
    ss << x;
    ss >>s;
    if (std::regex_match (s,e)) return true;
    else return false;
}