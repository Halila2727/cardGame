#include <deque>
#include "Hand.hpp"

// Constructor
Hand::Hand()
{

}

// Destructor
Hand::~Hand()
{

}

// Copy Constructor
Hand::Hand(const Hand& other)
{
    cards_ = other.cards_;
}

// Copy Assignment Operator
Hand& Hand::operator=(const Hand& other)
{
    if (this != &other)
    {
        cards_ = other.cards_;
    }

    return *this;
}

// Move Constructor
Hand::Hand(Hand&& other)
{
    cards_ = std::move(other.cards_);
}

// Move Assignment Operator
Hand& Hand::operator=(Hand&& other)
{
    if (this != &other)
    {
        cards_ = std::move(other.cards_);
    }
    return *this;
}

// Get the cards in the hand
const std::deque<PointCard>& Hand::getCards() const 
{
    return cards_;
}

// Add a card to the hand
void Hand::addCard(PointCard&& card)
{
    cards_.push_back(std::move(card));
}

// Check if the hand is empty
bool Hand::isEmpty() const
{
    return cards_.empty();
}

// Reverse the hand
void Hand::Reverse()
{
    std::deque<PointCard> reversedCards;
    while (!cards_.empty())
    {
        reversedCards.push_back(std::move(cards_.back()));
        cards_.pop_back();
    }
    cards_ = std::move(reversedCards);
}

// Play the card at the front of the hand, removing it from the hand
int Hand::PlayCard()
{
    if (isEmpty() == true)
    {
        throw std::out_of_range("Hand is empty, cannot play a card.");
    }

    PointCard card = std::move(cards_.front());
    cards_.pop_front();

    if (card.isPlayable() == false)
    {
        throw std::invalid_argument("The card in hand is not playable.");
    }

    return std::stoi(card.getInstruction());
}