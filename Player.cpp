#include "Player.hpp"

// Constructor
Player::Player()
{
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
    hand_ = Hand();
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
    this->hand_ = hand;
}

// Get the player's score
int Player::getScore() const
{
    return score_;
}

// Set the player's score
void Player::setScore(const int& score)
{
    this->score_ = score;
}

// Play an action card
void Player::play(ActionCard&& card)
{
    std::string instruction = card.getInstruction();
    std::cout << "PLAYING ACTION CARD: " << instruction << "\n";

    //splitting the instruction into a vector
    std::vector<std::string> word_list;
    std::string word;
    std::stringstream stringstream(instruction);

    while(std::getline(stringstream, word, ' ')){
        word_list.push_back(word);
    }
    
    //Checking the different instruction of ActionCard
    if(word_list[0] == "PLAY"){
        for(int i = 0; i < std::stoi(word_list[1]); i++){
            this->playPointCard();
        }
    }else if(word_list[0] == "DRAW"){
        for(int i = 0; i < std::stoi(word_list[1]); i++){
            this->drawPointCard();
        }            
    }else if(word_list[0] == "REVERSE"){
        this->hand_.Reverse();

    }else if(word_list[0] == "SWAP"){
        if(this->opponent_ != nullptr){
            std::swap(this->hand_, this->opponent_->hand_);
        }
        
    }
}

// Draw a point card and place it in the player's hand
void Player::drawPointCard()
{
    if((this->hand_.isEmpty()) == true)
    {} //do nothing
    else
    {
        this->score_ += this->hand_.PlayCard();
    }
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
        this->opponent_ = new Player[sizeof(opponent)];
        for (int i = 0; i < sizeof(opponent); ++i)
        {
            this->opponent_[i] = opponent[i];
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
        this->actiondeck_ = new Deck<ActionCard>[sizeof(actiondeck)];
        for (int i = 0; i < sizeof(actiondeck); ++i)
        {
            this->actiondeck_[i] = actiondeck[i];
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
        this->pointdeck_ = new Deck<PointCard>[sizeof(pointdeck)];
        for (int i = 0; i < sizeof(pointdeck); ++i)
        {
            this->pointdeck_[i] = pointdeck[i];
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