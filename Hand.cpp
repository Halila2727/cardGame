#include <deque>
#include "Hand.hpp"

// Constructor
Hand::Hand()
{
    cards_.clear();
}

// Destructor
Hand::~Hand()
{
    while (this->cards_.size() > 0)
    {
        this->cards_.pop_back();
    }
}

// Copy Constructor
Hand::Hand(const Hand& other)
{
    this->cards_ = other.cards_;
}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other)
{
    if (this != &other)
    {
        this->cards_ = other.cards_;
    }

    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other)
{
    this->cards_ = std::move(other.cards_);
}

// Move Assignment Operator
Hand& Hand::operator=(Hand&& other)
{
    if (this != &other)
    {
        this->cards_ = std::move(other.cards_);
    }
    return *this;
}

// Get the cards in the hand
const std::deque<PointCard>& Hand::getCards() const 
{
    return this->cards_;
}

// Add a card to the hand
void Hand::addCard(PointCard&& card)
{
    card.setDrawn(true);
    this->cards_.push_back(std::move(card));
}

// Check if the hand is empty
bool Hand::isEmpty() const
{
    if(this->cards_.empty() == true)
    {
        return true;
    }
    return false;
}

// Reverse the hand
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

// Play the card at the front of the hand, removing it from the hand
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