#include <string>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <chrono>

class DeckShuffler
{
	public:
		void ShuffleDeck(int cards[]);
		void PrintDeck(int cards[]);
};

void DeckShuffler::ShuffleDeck(int cards[]){

	typedef std::chrono::high_resolution_clock myclock;
  	myclock::time_point beginning = myclock::now();

  	myclock::duration d = myclock::now() - beginning;
  	unsigned seed2 = d.count();

	for(int i = 0; i < 9; i ++){
		std::default_random_engine generator;
		generator.seed (seed2);
		std::uniform_int_distribution<int> distribution(0,9);
		// generates number in the range 1..6 
		int dice_roll = distribution(generator); 

		int swap;
		swap = cards[i];
		cards[i] = cards[dice_roll];
		cards[dice_roll] = swap;
	}

}

void DeckShuffler::PrintDeck(int cards[]){
	// shuffle the shit outta these cards
	for(int i = 0; i < 9; i ++){
		std::cout << cards[i];
	}
}

int main()
{
	int cards[10] = {1,2,3,4,5,6,7,8,9,0};
	DeckShuffler  *deck = new DeckShuffler();
	deck->ShuffleDeck(cards);
	deck->PrintDeck(cards);

	return 0;
}