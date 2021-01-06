#include "healtheffectcard.h"

HealthEffectCard::HealthEffectCard(int h): hearts_number(h==0? rand()%8+3 : h){};

HealthEffectCard::~HealthEffectCard()= default;

int HealthEffectCard::getHeartsNumber() const
{
    return hearts_number;
};

bool HealthEffectCard::operator==(const Card& c) const
{
    return Card::operator==(c) && static_cast<const HealthEffectCard&>(c).getHeartsNumber()==getHeartsNumber();
};

bool HealthEffectCard::operator!=(const Card& c) const
{
    return Card::operator!=(c) && static_cast<const HealthEffectCard&>(c).getHeartsNumber()!=getHeartsNumber();
};
