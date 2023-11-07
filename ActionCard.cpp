#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"
#include "ActionCard.hpp"

ActionCard::ActionCard() : Card()
{
    setType(ACTION_CARD);
}

bool ActionCard::isPlayable()
{
    if(getDrawn() == false)
    {
        return false;
    }
    
    if(getInstruction().substr(0, 1) != "D" || getInstruction().substr(0, 4) != "P" 
    || getInstruction().substr(0, 4) != "R" || getInstruction().substr(0, 4) != "S")
    {
        return false;
    }
    
    return true;
}

void ActionCard::Print() const
{
    std::cout << "Type: " << getType();
    std::cout << "\nInstruction: " << getInstruction();
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