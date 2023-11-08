#include <iostream>
#include <string>
#include "Card.hpp"

//Destructor for Card
Card::~Card()
{
    delete[] this->bitmap_;
}

//Copy Constructor for Card
Card::Card(const Card& rhs)
{
    setImageData(rhs.bitmap_);
    cardType_ = rhs.cardType_;
    instruction_ = rhs.instruction_;
    drawn_ = rhs.drawn_;
}

//Copy Assignment Operator for Card
Card& Card::operator=(const Card& rhs)
{
    if( this != &rhs )
    {
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

//Move Constructor for Card
Card::Card(Card&& rhs)
{
    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    drawn_ = std::move(rhs.drawn_);
    bitmap_ = std::move(rhs.bitmap_);

    rhs.instruction_ = "";
}

//Move Assignment Operator for Card
Card& Card::operator=(Card&& rhs)
{
    // if (this == &rhs)
    // {
    //     return *this;
    // }

    // cardType_ = std::move(rhs.cardType_);
    // instruction_ = std::move(rhs.instruction_);
    // rhs.instruction_ = "";

    // setImageData(std::move(rhs.bitmap_));
    // rhs.bitmap_ = nullptr;

    // drawn_ = std::move(rhs.drawn_);

    cardType_ = std::move(rhs.cardType_);
    instruction_ = std::move(rhs.instruction_);
    bitmap_ = std::move(rhs.bitmap_);
    drawn_ = std::move(rhs.drawn_);
    
    return *this;
    // return *this;
}

//Default Constructor for Card
Card::Card()
{
    instruction_ = "";
    drawn_ = false;
    bitmap_ = nullptr;
}

//Returns the corresponding string to the cardType_ of Card
std::string Card::getType() const
{
    if(cardType_ == POINT_CARD)
    {
        return "POINT_CARD";
    }
    else if(cardType_ == ACTION_CARD)
    {
        return "ACTION_CARD";
    }
    return "";
}

//Sets cardType_ with type
void Card::setType(const CardType& type)
{
    cardType_ = type;
}

//Returns the instruction_ of Card
const std::string& Card::getInstruction() const
{
    return instruction_;
}

//Sets instruction_ with instruction
void Card::setInstruction(const std::string& instruction)
{
    instruction_ = instruction;
}

//Returns the bitmap_ of card
const int* Card::getImageData() const
{
    return bitmap_;
}

//Sets each value of bitmap_ with data, or else setting it nullptr as data is nullptr as well
void Card::setImageData(int* data)
{
    if (data != nullptr)
    {
        bitmap_ = new int[sizeof(80)];
        for (int i = 0; i < sizeof(80); ++i)
        {
            bitmap_[i] = data[i];
        }
    } 
    else
    {
        bitmap_ = nullptr;
    }
}

//Returns the drawn_ of card
bool Card::getDrawn() const
{
    return drawn_;
}

//Sets drawn_ with drawn
void Card::setDrawn(const bool& drawn)
{
    drawn_ = drawn;
}