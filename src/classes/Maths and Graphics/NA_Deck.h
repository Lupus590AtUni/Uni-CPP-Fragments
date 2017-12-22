// Random values which are not numbers
// Terminology is a deck of cards but can be anything
// Cards are identified via strings

#pragma once
#include <string>
using std::string;

#include <vector>
using std::vector;

class NA_Deck
{
private:
	vector<string> cards;

public:
	NA_Deck();
	~NA_Deck();
	void addCard(const string id, const unsigned int count = 1); // count can be increased to have more of the same card, doesn't add a card if count is 0
	string drawCard(); // returns empty string if deck is empty
	unsigned int size();
};

