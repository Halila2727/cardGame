#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"
#include "ActionCard.hpp"

//Construct an ActionCard object
ActionCard::ActionCard() : Card()
{
    setType(ACTION_CARD);
}

//Determines if a card is playable and returns corresponding boolean value.
bool ActionCard::isPlayable()
{
    if(getDrawn() == false || getInstruction().size() < 11)
    {
        return false;
    }


    if (getInstruction() == "REVERSE HAND" || getInstruction() == "SWAP HAND WITH OPPONENT")
    {
        return true;
    }
    
    if (getInstruction().substr(0, 4) == "DRAW" || getInstruction().substr(0,4) == "PLAY")
    {
        return true;
    }

    return false;
}

//Prints the information within a given ActionCard
void ActionCard::Print() const
{
    std::cout << "Type: " << getType() << std::endl;
    std::cout << "Instruction: " << getInstruction() << std::endl;
    std::cout << "Card: " << std::endl;
    
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

    std::cout << std::endl;
}