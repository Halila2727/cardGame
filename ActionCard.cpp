#include <iostream>
#include <string>
#include <cctype>
#include <regex>
#include "Card.hpp"
#include "ActionCard.hpp"

ActionCard::ActionCard() : Card::Card()
{
    setType(ACTION_CARD);
}

bool ActionCard::isPlayable()
{
    if(getDrawn() == false)
    {
        return false;
    }
    
    if(getInstruction().substr(0, 4) != "DRAW" || getInstruction().substr(0, 4) != "PLAY" || getInstruction().substr(0, 4) != "REVE" || getInstruction().substr(0, 4) != "SWAP")
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
    std::cout << getImageData();
}