#include <cassert>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
#include "Player.hpp"

int main()
{
    
    // Test ActionCard class
    ActionCard actionCard;
    actionCard.setInstruction("DRAW 2 CARDS");
    assert(actionCard.isPlayable() == true);

    // Test PointCard class
    PointCard pointCard;
    pointCard.setInstruction("10");
    assert(pointCard.isPlayable() == true);

    // Test Deck class
    Deck<ActionCard> actionDeck;
    ActionCard actionCard1;
    actionCard1.setInstruction("DRAW 2 CARDS");
    actionDeck.AddCard(actionCard1);
    assert(!actionDeck.IsEmpty());
    ActionCard drawnActionCard = actionDeck.Draw();
    assert(drawnActionCard.getInstruction() == "DRAW 2 CARDS");

    // Test Hand class
    Hand hand;
    assert(hand.isEmpty() == true);
    PointCard pointCard2;
    pointCard2.setInstruction("5");
    hand.addCard(std::move(pointCard2));
    assert(!hand.isEmpty());
    int points = hand.PlayCard();
    assert(points == 5);

    // Test Player class
    Player player;
    Player opponent;
    player.setOpponent(&opponent);
    Deck<ActionCard> actionDeck2;
    player.setActionDeck(&actionDeck2);
    Deck<PointCard> pointDeck;
    player.setPointDeck(&pointDeck);

    // You can continue adding more tests for Player class and other functions as needed.

    return 0;
}
