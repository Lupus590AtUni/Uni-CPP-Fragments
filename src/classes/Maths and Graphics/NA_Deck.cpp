#include "stdafx.h"
#include "NA_Deck.h"
#include "NA_MathsLib.h"

NA_Deck::NA_Deck()
{
}


NA_Deck::~NA_Deck()
{
}

void NA_Deck::addCard(const string id, const unsigned int count)
{
	if (count == 0)
	{
		return;
	}

	for (int i = 0; i < count; i++)
	{
		cards.push_back(id);
	}
}

string NA_Deck::drawCard()
{
	if (size() == 0)
	{
		return "";
	}

	// pick a random number between 0  and card count
	extern NA_MathsLib na_maths;
	const unsigned int roll = na_maths.dice(size()-1);

	// find the card, remove it from the deck and return it to caller
	const string card = cards[roll];
	cards.erase(cards.begin() + roll);
	return card;

}

unsigned int NA_Deck::size()
{
	return cards.size();
}
