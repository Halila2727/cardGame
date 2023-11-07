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
    
    // if(getInstruction().substr(0, 1) != "0" || getInstruction().substr(0, 1) != "1" || getInstruction().substr(0, 1) != "2" || getInstruction().substr(0, 1) != "3" 
    // || getInstruction().substr(0, 1) != "4" || getInstruction().substr(0, 1) != "5" || getInstruction().substr(0, 1) != "6" || getInstruction().substr(0, 1) != "7" 
    // || getInstruction().substr(0, 1) != "8" || getInstruction().substr(0, 1) != "9" )
    // {
    //     return false;
    // }
    try
    {
        int number = std::stoi(getInstruction());
        return number >= 1 && number <= 99;
    } 
    catch (const std::invalid_argument&)
    {
        return false; // Invalid number format
    } 
    catch (const std::out_of_range&)
    {
        return false; // Out of range integer
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

    std::cout << "\n";
}