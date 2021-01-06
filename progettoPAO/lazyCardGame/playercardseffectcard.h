#ifndef PLAYERCARDSEFFECTCARD_H
#define PLAYERCARDSEFFECTCARD_H

#include "card.h"

class PlayerCardsEffectCard : public Card
{
private:
    int cards_number;

public:
    /**
     * @brief PlayerHandEffectCard => Costruttore della classe PlayerHandEffectCard
     * @param int => numero di carte dell'effetto
     */
    PlayerCardsEffectCard(int=0);

    /**
     * @brief ~PlayerHandEffectCard => Distruttore della classe PlayerHandEffectCard
     */
    virtual ~PlayerCardsEffectCard();

    /**
     * @brief clone
     * @return clone dell'oggetto di invocazione
     */
    virtual Card* clone() const = 0;

    /**
     * @brief getCradsNumber
     * @return numero di carte dell'effetto
     */
    int getCradsNumber() const;

    /**
     * @brief operator ==
     * @param Card => carta da confrontare
     * @return true se le due carte sono uguali, false altrimenti
     */
    virtual bool operator==(const Card&) const;

    /**
     * @brief operator !=
     * @param Card => carta da confrontare
     * @return true se le due carte sono diverse, false altrimenti
     */
    virtual bool operator!=(const Card&) const;
};

#endif // PLAYERCARDSEFFECTCARD_H
