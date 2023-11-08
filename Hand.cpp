#include <deque>
#include "Hand.hpp"

//Constructor for Hand
Hand::Hand()
{
    cards_.clear();
}

//Destructor for Hand
Hand::~Hand()
{
    while (this->cards_.size() > 0)
    {
        this->cards_.pop_back();
    }
}

//Copy Constructor for Hand
Hand::Hand(const Hand& other)
{
    this->cards_ = other.cards_;
}

//Copy Assignment Operator for Hand
Hand& Hand::operator=(const Hand& other)
{
    if (this != &other)
    {
        this->cards_ = other.cards_;
    }

    return *this;
}

//Move Constructor for Hand
Hand::Hand(Hand&& other)
{
    this->cards_ = std::move(other.cards_);
}

//Move Assignment Operator for Hand
Hand& Hand::operator=(Hand&& other)
{
    if (this != &other)
    {
        this->cards_ = std::move(other.cards_);
    }
    return *this;
}

//Returns the deque of Cards in Hand
const std::deque<PointCard>& Hand::getCards() const 
{
    return this->cards_;
}

//Adds a PointCard to Hand
void Hand::addCard(PointCard&& card)
{
    card.setDrawn(true);
    this->cards_.push_back(std::move(card));
}

//Determines if Hand is empty and returns corresponding boolean value
bool Hand::isEmpty() const
{
    if(this->cards_.empty() == true)
    {
        return true;
    }
    return false;
}

//Reverses the order of the cards in Hand
void Hand::Reverse()
{
    std::deque<PointCard> reversedCards;
    while (this->cards_.empty() == false)
    {
        reversedCards.push_back(std::move(this->cards_.back()));
        this->cards_.pop_back();
    }
    this->cards_ = std::move(reversedCards);
}

//Unless Hand is empty or card in Hand is not playable, will play the card at front of the Hand
// It will then return the integer value of the PointCard played unless it threw one of the error
//messages
int Hand::PlayCard()
{
    if (this->isEmpty() == true)
    {
        throw std::out_of_range("Hand is empty, cannot play a card.");
    }

    PointCard card = std::move(this->cards_.front());
    cards_.pop_front();

    if (card.isPlayable() == false)
    {
        throw std::invalid_argument("The card in hand is not playable.");
    }

    return std::stoi(card.getInstruction());
}