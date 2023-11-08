#include "Player.hpp"

//Constructor for Player
Player::Player()
{
    score_ = 0;
    opponent_ = nullptr;
    actiondeck_ = nullptr;
    pointdeck_ = nullptr;
    hand_ = Hand();
}

//Destructor for Hand
Player::~Player()
{
    delete opponent_;
    delete pointdeck_;
    delete actiondeck_;
}

//Returns the Hand that the Player possesses
const Hand& Player::getHand() const
{
    return hand_;
}

//Sets the Player's hand_ as the given hand.
void Player::setHand(const Hand& hand)
{
    this->hand_ = hand;
}

//Returns the PLayer's score_
int Player::getScore() const
{
    return score_;
}

//Sets the player's score_ as score
void Player::setScore(const int& score)
{
    this->score_ = score;
}

//Plays an ActionCard by matching the instructions of the card to an action and performing
//the given action
void Player::play(ActionCard&& card)
{
    std::cout << "PLAYING ACTION CARD: " << card.getInstruction() << "\n";

    // //splitting the instruction into a vector
    // std::vector<std::string> word_list;
    // std::string word;
    // std::stringstream stringstream(instruction);

    // while(std::getline(stringstream, word, ' ')){
    //     word_list.push_back(word);
    // }
    
    // //Checking the different instruction of ActionCard
    // if(word_list[0] == "PLAY"){
    //     for(int i = 0; i < std::stoi(word_list[1]); i++){
    //         this->playPointCard();
    //     }
    // }else if(word_list[0] == "DRAW"){
    //     for(int i = 0; i < std::stoi(word_list[1]); i++){
    //         this->drawPointCard();
    //     }            
    // }else if(word_list[0] == "REVERSE"){
    //     this->hand_.Reverse();

    // }else if(word_list[0] == "SWAP"){
    //     if(this->opponent_ != nullptr){
    //         std::swap(this->hand_, this->opponent_->hand_);
    //     }
        
    // }
    // Define regular expressions
    std::regex drawRegex(R"(DRAW (\d+) CARD\(S\))");
    std::regex playRegex(R"(PLAY (\d+) CARD\(S\))");
    std::regex reverseRegex("REVERSE HAND");
    std::regex swapRegex("SWAP HAND WITH OPPONENT");
    std::smatch match;

    const std::string &instruction = card.getInstruction();

    if (std::regex_match(instruction, drawRegex))
    {
        if (std::regex_search(instruction, match, drawRegex))
        {
            int num = std::stoi(match[1]);
            for (int i = 0; i < num; ++i)
            {
                drawPointCard();
            }
        }
    }
    else if(std::regex_match(instruction, playRegex))
    {
        if (std::regex_search(instruction, match, playRegex))
        {
            int num = std::stoi(match[1]);
            for (int i = 0; i < num; ++i)
            {
                playPointCard();
            }
        }
    }
    else if(std::regex_match(instruction, reverseRegex))
    {
        hand_.Reverse();
    }
    else if(std::regex_match(instruction, swapRegex))
    {
        std::swap(this->hand_, opponent_->hand_);
    }
    else
    {
        std::cout << "This instruction is not a valid action" << std::endl;
    }
}

//Draws a PointCard and places it in the Player's hand_ unless pointdeck_ is empty
//in which case, nothing happens
void Player::drawPointCard()
{
    if (pointdeck_ != nullptr) {
    PointCard card = pointdeck_->Draw();
    hand_.addCard(std::move(card));
  }
}

//Plays a PointCard from the Player's hand_ and increases the Player's score_
//unless hand_ is empty in which case, nothing happens
void Player::playPointCard()
{
    if((this->hand_.isEmpty()) == true)
    {} //do nothing
    else
    {
        this->score_ += this->hand_.PlayCard();
    }
}

//Sets the opponent_ as opponent
void Player::setOpponent(Player* opponent)
{
    this->opponent_ = opponent;
}

//Returns the opponent_
Player* Player::getOpponent()
{
    return opponent_;
}

//Sets the actiondeck_ as actiondeck
void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
    this->actiondeck_ = actiondeck;
}

//Returns the actiondeck_
Deck<ActionCard>* Player::getActionDeck()
{
    return actiondeck_;
}

//Sets the pointdeck_ as pointdeck
void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
    this->pointdeck_ = pointdeck;
}

//Returns the pointdeck_
Deck<PointCard>* Player::getPointDeck()
{
    return pointdeck_;
}