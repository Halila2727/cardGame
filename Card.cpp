#include <iostream>
#include <string>
#include "Card.hpp"

Card::~Card()
{
}

Card::Card(const Card& rhs)
{
    setImageData(rhs.bitmap_);
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
}

Card& Card::operator=(const Card& rhs)
{
    if( this != &rhs )
    {
        bitmap_ = rhs.bitmap_;
        cardType_ = rhs.cardType_;
        instruction_ = rhs.instruction_;
        drawn_ = rhs.drawn_;
        if (rhs.bitmap_ != nullptr)
        {
            bitmap_ = new int[sizeof(80)];
            for (int i = 0; i < sizeof(80); ++i)
            {
                bitmap_[i] = rhs.bitmap_[i];
            }
        }
        else
        {
            bitmap_ = nullptr;
        }
    }
    return *this;
}

Card::Card(Card&& rhs)
{
    cardType_ = std::move(rhs.cardType_);

    instruction_ = std::move(rhs.instruction_);

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

    setImageData(std::move(rhs.bitmap_));
    rhs.bitmap_ = nullptr;

    drawn_ = std::move(rhs.drawn_);
    
    return *this;
    // return *this;
}

Card::Card()
{
    instruction_ = "";
    drawn_ = false;
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
    if (data != nullptr)
    {
        bitmap_ = new int[sizeof(80)];
        for (int i = 0; i < sizeof(80); ++i) {
            bitmap_[i] = data[i];
        }
    } 
    else
    {
        bitmap_ = nullptr;
    }
}

bool Card::getDrawn() const
{
    return drawn_;
}

void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}