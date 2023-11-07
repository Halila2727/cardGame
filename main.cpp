#include <cassert>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
//#include "Hand.hpp"
//#include "Player.hpp"

int main()
{
    //Test ActionCard class
    ActionCard act1;
    act1.setInstruction("SWAP HAND WITH OPPONENT");
    act1.setDrawn(true);
    assert(act1.isPlayable() == true);
    std::cout << "Original Card: " << act1.getInstruction() << std::endl;

    ActionCard act2(act1);
    assert(act2.getInstruction() == act1.getInstruction());
    assert(act2.isPlayable() == true);
    std::cout << "Copied Card: " << act2.getInstruction() << std::endl;

    ActionCard act3(std::move(act1));
    assert(act3.isPlayable() == true);
    act3.setInstruction("REVERSE HAND");
    assert(act3.isPlayable() == true);

    std::cout << "\nOriginal Card: " << act1.getInstruction() << std::endl;
    std::cout << "Copied Card: " << act2.getInstruction() << std::endl;
    std::cout << "Moved Card: " << act3.getInstruction() << std::endl;

    ActionCard act4;
    act4.setInstruction("DRAW 4 CARDS");
    act4.setDrawn(true);
    assert(act4.isPlayable() == true);

    ActionCard act5;
    act5.setDrawn(false);
    act5.setInstruction("PLAY 5 CARDS");
    assert(act5.isPlayable() == false);

    ActionCard act6;
    act6.setDrawn(true);
    act6.setInstruction("PLAY 5 CARDS");
    assert(act6.isPlayable() == true);

    ActionCard act7;
    act7.setDrawn(true);
    act7.setInstruction("PLAGUE");
    assert(act7.isPlayable() == false);

    // Test PointCard class
    PointCard po1;
    po1.setInstruction("10");
    po1.setDrawn(true);
    assert(po1.isPlayable() == true);
    std::cout << "Original Card: " << po1.getInstruction() << std::endl;

    PointCard po2(po1);
    assert(po2.getInstruction() == po1.getInstruction());
    assert(po2.isPlayable() == true);
    std::cout << "Copied Card: " << po2.getInstruction() << std::endl;

    PointCard po3(std::move(po1));
    assert(po3.isPlayable() == true);

    std::cout << "Original Card: " << po1.getInstruction() << std::endl;
    std::cout << "Copied Card: " << po2.getInstruction() << std::endl;
    std::cout << "Moved Card: " << po3.getInstruction() << std::endl;

    PointCard po4;
    po4.setInstruction("98");
    po4.setDrawn(true);
    assert(po4.isPlayable() == true);

    PointCard po5;
    po5.setInstruction("988");
    po5.setDrawn(true);
    assert(po5.isPlayable() == false);

    PointCard po6;
    po6.setInstruction("98");
    po6.setDrawn(false);
    assert(po6.isPlayable() == false);

    PointCard po7;
    po7.setInstruction("1");
    po7.setDrawn(true);
    assert(po7.isPlayable() == true);

    PointCard po8;
    po8.setInstruction("hello");
    po8.setDrawn(true);
    assert(po8.isPlayable() == false);

    // Test Deck class
    Deck<ActionCard> actionDeck;
    assert(actionDeck.IsEmpty() == true);
    //ActionCard drawnActionCard = actionDeck.Draw();

    actionDeck.AddCard(act1);
    actionDeck.AddCard(act2);
    assert(!actionDeck.IsEmpty());

    act5.setDrawn(true);
    actionDeck.AddCard(act5);
    assert(act5.isPlayable() == true);

    ActionCard drawnActionCard = actionDeck.Draw();
    assert(drawnActionCard.getInstruction() == "PLAY 5 CARDS");

    // // Test Hand class
    // Hand hand;
    // assert(hand.isEmpty() == true);
    // PointCard pointCard2;
    // pointCard2.setInstruction("5");
    // hand.addCard(std::move(pointCard2));
    // assert(!hand.isEmpty());
    // int points = hand.PlayCard();
    // assert(points == 5);

    // // Test Player class
    // Player player;
    // Player opponent;
    // player.setOpponent(&opponent);
    // Deck<ActionCard> actionDeck2;
    // player.setActionDeck(&actionDeck2);
    // Deck<PointCard> pointDeck;
    // player.setPointDeck(&pointDeck);

    return 0;
}
