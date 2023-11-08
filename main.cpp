#include <cassert>
#include "Card.hpp"
#include "ActionCard.hpp"
#include "PointCard.hpp"
#include "Deck.hpp"
#include "Hand.hpp"
//#include "Player.hpp"

int main()
{
    //Test ActionCard class
    std::cout << "----ACTION CARD----\n\n";
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
    std::cout << "\n\n----POINT CARD----\n\n";
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
    std::cout << "\n\n----DECK----\n\n";

    Deck<ActionCard> actionDeck;
    assert(actionDeck.IsEmpty() == true);
    //ActionCard drawnActionCard = actionDeck.Draw();

    actionDeck.AddCard(act5);
    assert(actionDeck.IsEmpty() == false);

    actionDeck.AddCard(act6);
    actionDeck.AddCard(act4);

    ActionCard drawnActionCard = actionDeck.Draw();
    assert(drawnActionCard.getInstruction() == "DRAW 4 CARDS");
    drawnActionCard = actionDeck.Draw();
    assert(drawnActionCard.getInstruction() == "PLAY 5 CARDS");
    // drawnActionCard = actionDeck.Draw();
    // assert(drawnActionCard.getInstruction() == "PLAY 5 CARDS");

    // Test Hand class
    std::cout << "\n\n----HAND----\n\n";
    Hand hand;
    assert(hand.isEmpty() == true);

    PointCard pointCard2;
    pointCard2.setInstruction("5");
    pointCard2.setDrawn(true);

    hand.addCard(std::move(pointCard2));
    assert(hand.isEmpty() == false);

    int points = hand.PlayCard();
    assert(points == 5);
    assert(hand.isEmpty() == true);

    Deck<PointCard> pointDeck;
    pointDeck.AddCard(po4);
    pointDeck.AddCard(po7);
    pointDeck.AddCard(po3);

    hand.addCard(pointDeck.Draw());
    hand.addCard(pointDeck.Draw());
    hand.addCard(pointDeck.Draw());

    points += hand.PlayCard();
    std::cout << "Number of points: " << points<< "\n";
    assert(points == 15);
    points += hand.PlayCard();
    assert(points == 16);
    points += hand.PlayCard();
    assert(points == 114);

    pointDeck.AddCard(po4);
    pointDeck.AddCard(po7);
    pointDeck.AddCard(po3);

    hand.addCard(pointDeck.Draw());
    hand.addCard(pointDeck.Draw());
    hand.addCard(pointDeck.Draw());

    hand.Reverse();
    points += hand.PlayCard();
    assert(points == 212);
    points += hand.PlayCard();
    assert(points == 213);
    points += hand.PlayCard();
    assert(points == 223);
    


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
