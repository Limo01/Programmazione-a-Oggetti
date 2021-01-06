#include "cardcreator.h"

CardCreator::CardCreator()= default;

CardCreator::~CardCreator()= default;

DeepPtr<Card> CardCreator::createSingleAttackCard(int v) const
{
    return DeepPtr<Card>(new SingleAttackCard(v));
};

DeepPtr<Card> CardCreator::createMultipleAttackCard(int v) const
{
    return DeepPtr<Card>(new MultipleAttackCard(v));
};

DeepPtr<Card> CardCreator::createHealCard(int v) const
{
    return DeepPtr<Card>(new HealCard(v));
};

DeepPtr<Card> CardCreator::createSkipTurnCard() const
{
    return DeepPtr<Card>(new SkipTurnCard());
};

DeepPtr<Card> CardCreator::createDrawCardsCard(int v) const
{
    return DeepPtr<Card>(new DrawCardsCard(v));
};

DeepPtr<Card> CardCreator::createDiscardCardsCard(int v) const
{
    return DeepPtr<Card>(new DiscardCardsCard(v));
};

DeepPtr<Card> CardCreator::createRandomCard() const
{
    int random= rand()%6;

    switch(random)
    {
    case 0:
        return createSingleAttackCard();
    case 1:
        return createMultipleAttackCard();
    case 2:
        return createHealCard();
    case 3:
        return createDiscardCardsCard();
    case 4:
        return createSkipTurnCard();
    }
    return createDrawCardsCard();
};

Deck<DeepPtr<Card>> CardCreator::createRandomDeck(int n) const
{
    srand(time(0));
    Deck<DeepPtr<Card>> d(n);

    for(int i=0; i<n; i++)
        d.push_top(createRandomCard());

    return d;
};
