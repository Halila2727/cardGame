OBJECTS = Card.o Player.o Hand.o ActionCard.o PointCard.o Deck.o
CXXFLAGS=
LDFLAGS=
CXX=g++


main: main.o $(OBJECTS)
	$(CXX) -o main main.o

tests: tests.o $(OBJECTS)
	$(CXX) -o tests tests.o $(OBJECTS)

main.o: main.cpp $(OBJECTS)

tests.o: tests.cpp $(OBJECTS)
	g++ -c -std=c++11 -Wall tests.cpp

Player.o: Player.cpp Player.hpp Hand.hpp ActionCard.hpp PointCard.hpp Deck.hpp

Hand.o: Hand.cpp Hand.hpp PointCard.hpp

Deck.o: Deck.cpp Deck.hpp Card.hpp

PointCard.o: PointCard.cpp PointCard.hpp Card.hpp

ActionCard.o: ActionCard.cpp ActionCard.hpp Card.hpp

Card.o: Card.cpp Card.hpp

clean:
	rm -f *.o *.gch