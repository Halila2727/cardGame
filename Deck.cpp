#include "Deck.hpp"

template <typename CardType>
Deck<ActionCard>::Deck()
{

}

template <typename CardType>
Deck<CardType>::~Deck()
{

}

template <typename CardType>
void Deck<CardType>::AddCard(const CardType& card)
{
    cards_.push_back(card);
}

template <typename CardType>
CardType&& Deck<CardType>::Draw()
{
    if(IsEmpty() == true)
    {
        throw std::out_of_range("Cannot draw, deck is empty.");
    }
    else
    {
        CardType card = cards_.back();
        cards_.pop_back();
        return std::move(card);
    }
}

template <typename CardType>
bool Deck<CardType>::IsEmpty() const
{
    return cards_.empty();
}

template <typename CardType>
void Deck<CardType>::Shuffle()
{
    std::mt19937 seed(2028358904);
    std::shuffle(cards_.begin(), cards_.end(), seed);
}

template <typename CardType>
int Deck<CardType>::getSize() const
{
    return cards_.size();
}

template <typename CardType>
std::vector<CardType> Deck<CardType>::getDeck() const
{
    return cards_;
}
