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
    delete opponent_;
    delete pointdeck_;
    delete actiondeck_;
}

// Get the player's hand
const Hand& Player::getHand() const
{
    return hand_;
}

// Set the player's hand
void Player::setHand(const Hand& hand)
{
    hand_ = Hand(hand);
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
    if (opponent != nullptr)
    {
        opponent_ = new Player[sizeof(opponent)];
        for (int i = 0; i < sizeof(opponent); ++i)
        {
            opponent_[i] = opponent[i];
        }
    } 
    else
    {
        opponent_ = nullptr;
    }
}

// Get a pointer to the player's opponent
Player* Player::getOpponent()
{
    return opponent_;
}

// Set the action deck of the player
void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
    if (actiondeck != nullptr)
    {
        actiondeck_ = new Deck<ActionCard>[sizeof(actiondeck)];
        for (int i = 0; i < sizeof(actiondeck); ++i)
        {
            actiondeck_[i] = actiondeck[i];
        }
    } 
    else
    {
        actiondeck_ = nullptr;
    }
}

// Get a pointer to the player's action deck
Deck<ActionCard>* Player::getActionDeck()
{
    return actiondeck_;
}

// Set the point deck of the player
void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
    if (pointdeck != nullptr)
    {
        pointdeck_ = new Deck<PointCard>[sizeof(pointdeck)];
        for (int i = 0; i < sizeof(pointdeck); ++i)
        {
            pointdeck_[i] = pointdeck[i];
        }
    } 
    else
    {
        pointdeck_ = nullptr;
    }
}

// Get a pointer to the player's point deck
Deck<PointCard>* Player::getPointDeck()
{
    return pointdeck_;
}