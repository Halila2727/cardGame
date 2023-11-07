#include "Player.hpp"

// Constructor
Player::Player()
{
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
}

// Destructor
Player::~Player()
{

}

// Get the player's hand
const Hand& Player::getHand() const
{
    return hand_;
}

// Set the player's hand
void Player::setHand(const Hand& hand)
{
    hand_ = hand;
}

// Get the player's score
int Player::getScore() const
{
    return score_;
}

// Set the player's score
void Player::setScore(const int& score)
{
    score_ = score;
}

// Play an action card
void Player::play(ActionCard&& card)
{
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << "\n";
    
    
}

// Draw a point card and place it in the player's hand
void Player::drawPointCard()
{
    PointCard pointCard = pointdeck_->Draw();
    hand_.addCard(std::move(pointCard));
}

// Play a point card from the player's hand and update the player's score
void Player::playPointCard()
{
    if (!hand_.isEmpty())
    {
        int points = hand_.PlayCard();
        score_ += points;
    }
}

// Set the opponent of the player
void Player::setOpponent(Player* opponent)
{
    opponent_ = opponent;
}

// Get a pointer to the player's opponent
Player* Player::getOpponent()
{
    return opponent_;
}

// Set the action deck of the player
void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
    actiondeck_ = actiondeck;
}

// Get a pointer to the player's action deck
Deck<ActionCard>* Player::getActionDeck()
{
    return actiondeck_;
}

// Set the point deck of the player
void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
    pointdeck_ = pointdeck;
}

// Get a pointer to the player's point deck
Deck<PointCard>* Player::getPointDeck()
{
    return pointdeck_;
}
