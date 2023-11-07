#include <iostream>
#include <string>
#include "Card.hpp"

Card::~Card()
{
    delete[] bitmap_;
}

Card::Card(const Card& rhs)
{
    if (rhs.bitmap_ != nullptr)
    {
        *bitmap_ = 80;
    }
    else
    {
        bitmap_ = nullptr;
    }
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
}

Card& Card::operator=(const Card& rhs)
{
    if( this != &rhs )
    {
        *bitmap_ = 80;
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
    }
    return *this;
}

Card::Card(Card&& rhs)
{
    cardType_ = std::move(rhs.cardType_);

    instruction_ = std::move(rhs.instruction_);
    rhs.instruction_.clear();

    *bitmap_ = 80;
    rhs.bitmap_ = nullptr;

    drawn_ = std::move(rhs.drawn_);
}

Card& Card::operator=(Card&& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);

    if (bitmap_ != nullptr)
    {
        delete[] bitmap_;
    }
    *bitmap_ = 80;
    rhs.bitmap_ = nullptr;

    drawn_ = std::move(rhs.drawn_);
    
    return *this;
    // return *this;
}

Card::Card()
{
    instruction_ = "";
    drawn_ = false;
    *bitmap_ = 80;
}

std::string Card::getType() const
{
    if(cardType_ == POINT_CARD)
    {
        return "POINT_CARD";
    }
    return "ACTION_CARD";
}

void Card::setType(const CardType& type)
{
    cardType_ = type;
}

const std::string& Card::getInstruction() const
{
    return instruction_;
}

void Card::setInstruction(const std::string& instruction)
{
    instruction_ = instruction;
}

const int* Card::getImageData() const
{
    return bitmap_;
}

void Card::setImageData(int* data)
{
    bitmap_ = data;
}

bool Card::getDrawn() const
{
    return drawn_;
}

void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}