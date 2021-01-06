#include "playercardseffectcard.h"

PlayerCardsEffectCard::PlayerCardsEffectCard(int c): cards_number(c==0? rand()%4+2 : c){};

PlayerCardsEffectCard::~PlayerCardsEffectCard()= default;

int PlayerCardsEffectCard::getCradsNumber() const
{
    return cards_number;
};

bool PlayerCardsEffectCard::operator==(const Card& c) const
{
    return Card::operator==(c) && static_cast<const PlayerCardsEffectCard&>(c).getCradsNumber()==getCradsNumber();
};

bool PlayerCardsEffectCard::operator!=(const Card& c) const
{
    return Card::operator!=(c) && static_cast<const PlayerCardsEffectCard&>(c).getCradsNumber()!=getCradsNumber();
};
