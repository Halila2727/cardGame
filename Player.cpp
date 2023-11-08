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

    const std::string &instruction = card.getInstruction();

    if (std::regex_match(instruction, drawRegex)) {
        std::smatch match;
        if (std::regex_search(instruction, match, drawRegex)) {
        int num_cards_to_draw = std::stoi(match[1]);
        for (int i = 0; i < num_cards_to_draw; ++i) {
            drawPointCard();
        }
        }
    } else if (std::regex_match(instruction, playRegex)) {
        std::smatch match;
        if (std::regex_search(instruction, match, playRegex)) {
        int num_cards_to_play = std::stoi(match[1]);
        for (int i = 0; i < num_cards_to_play; ++i) {
            playPointCard();
        }
        }
    } else if (std::regex_match(instruction, reverseRegex)) {
        // Reverse the player's hand
        hand_.Reverse();

    } else if (std::regex_match(instruction, swapRegex)) {
        Hand temp = this->hand_;
        this->hand_ = opponent_->hand_;
        opponent_->hand_ = temp;
    } else {
        std::cout << "Unsupported action: " << instruction << std::endl;
    }
}

// Draw a point card and place it in the player's hand
void Player::drawPointCard()
{
    if (pointdeck_ != nullptr) {
    PointCard card = pointdeck_->Draw();
    hand_.addCard(std::move(card));
  }
}

// Play a point card from the player's hand and update the player's score
void Player::playPointCard()
{
    if((this->hand_.isEmpty()) == true)
    {} //do nothing
    else
    {
        this->score_ += this->hand_.PlayCard();
    }
}

// Set the opponent of the player
void Player::setOpponent(Player* opponent)
{
    this->opponent_ = opponent;
}

// Get a pointer to the player's opponent
Player* Player::getOpponent()
{
    return opponent_;
}

// Set the action deck of the player
void Player::setActionDeck(Deck<ActionCard>* actiondeck)
{
    this->actiondeck_ = actiondeck;
}

// Get a pointer to the player's action deck
Deck<ActionCard>* Player::getActionDeck()
{
    return actiondeck_;
}

// Set the point deck of the player
void Player::setPointDeck(Deck<PointCard>* pointdeck)
{
    this->pointdeck_ = pointdeck;
}

// Get a pointer to the player's point deck
Deck<PointCard>* Player::getPointDeck()
{
    return pointdeck_;
}