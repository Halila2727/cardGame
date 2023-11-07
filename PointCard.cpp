#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"
#include "PointCard.hpp"

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

PointCard::PointCard() : Card()
{
    setType(POINT_CARD);
}

bool PointCard::isPlayable()
{
    if(getDrawn() == false)
    {
        return false;
    }
    
    const std::string& instruction = getInstruction();
    for (char c : instruction)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    
    return true;
}

void PointCard::Print() const
{
    std::cout << "Type: " << getType();
    std::cout << "\nPoints: " << getInstruction();
    std::cout << "\nCard: \n";
    
    const int* imageData = getImageData();
    if (imageData != nullptr)
    {
        for (int i = 0; i < sizeof(imageData); i++)
        {
            std::cout << imageData[i];
        }
    }
    else
    {
        std::cout << "No image data";
    }
}