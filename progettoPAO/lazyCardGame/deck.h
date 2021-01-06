#ifndef DECK_H
#define DECK_H

#include <ostream>

template<class T>
class Deck
{
private:   
    int MAX_SIZE;
    int size;
    T* cards;

    /**
     * @brief deepCopy => Funzione per copiare un array di carte
     * @param t => T*, array di carte da copiare
     * @param size => int, dimensione dell'array da copiare
     * @return array di carte copiato
     */
    static T* deepCopy(T* t, const int size)
    {
        T* aux= new T[size];

        for(int i=0; i<size; i++)
            aux[i]= t[i];

        return aux;
    };

public:
    /**
     * @brief Deck => Costruttore della classe Deck
     * @param s => int, massima grandezza del mazzo
     */
    Deck(int s=52): MAX_SIZE(s), size(0), cards(new T[MAX_SIZE]){};

    /**
     * @brief Deck => Costruttore di copia della classe Deck
     * @param d => Deck, deck da copiare
     */
    Deck(const Deck& d): MAX_SIZE(d.MAX_SIZE), size(d.size), cards(deepCopy(d.cards, d.size)){};

    /**
     * @brief ~Deck => Distruttore della classe Deck
     */
    ~Deck(){delete[] cards;};

    /**
     * @brief getSize
     * @return numero di carte presenti nel decks
     */
    int getSize() const
    {
        return size;
    };

    /**
     * @brief isEmpty
     * @return true se il mazzo è vuoto, false altrimenti
     */
    bool isEmpty() const
    {
        return size==0;
    };

    /**
     * @brief push_top => Inserimento in cima al deck. Metodo più efficiente per inserire una carta nel deck
     * @param t => T, carta da aggiungere
     */
    void push_top(const T& t)
    {
        if(size < MAX_SIZE)
        {
            cards[size]=t;
            size++;
        }
        else throw std::length_error("Deck<T>::push_top(const T&): reached maximum size");
    };

    /**
     * @brief push_bottom => Inserimento in fondo al mazzo
     * @param t => T, carta da aggiungere
     */
    void push_bottom(const T& t)
    {
        if(size < MAX_SIZE)
        {
            T aux, aux2;
            aux= cards[0];
            cards[0]= t;

            for(int i=1; i<=size; i++)
            {
                aux2= cards[i];
                cards[i]= aux;
                aux= aux2;
            }
            size++;
        }
        else throw std::length_error("Deck<T>::push_bottom(const T&): reached maximum size");
    };

    /**
     * @brief drawCard
     * @return carta pescata
     */
    T drawCard()
    {
        if(!isEmpty())
        {
            size--;
            T aux= cards[size];
            return aux;
        }
        else throw std::range_error("Deck<T>::drawCard(): Deck<T> is empty");
    };

    /**
     * @brief shuffle => Mescola le carte
     */
    void shuffle()
    {
        if(size>1)
        {
            int n1, n2;
            T aux;

            for(int i=0; i<size; i++)
            {
                n1= (rand() % size);//primo numero casuale
                n2= (rand() % size);//secondo numero casuale

                aux= cards[n1];
                cards[n1]= cards[n2];
                cards[n2]= aux;
            }
        }
    };

    /**
     * @brief operator =
     * @param d => Deck, deck da copiare
     * @return deck copiato
     */
    Deck& operator=(const Deck& d)
    {
        if(this != &d)
        {
            delete[] cards;
            cards= deepCopy(d.cards, d.size);
            size= d.size;
            MAX_SIZE= d.MAX_SIZE;
        }
        return *this;
    };

    /**
     * @brief operator []
     * @param i => int, indice della carta da ottenere
     * @return carta
     */
    T& operator[](int i) const
    {
        if(i<size && i>=0)
            return cards[i];
        else throw std::out_of_range("Deck<T>::operator[](int): index is out of range or Deck<T> is empty");
    };

    //const Iterator: La visita del mazzo visualizza l'ordine con il quale verrano pescate le carte: in particolare begin() ha come riferimento la prossima carta che verrà pescata
    class Const_iterator
    {
        friend class Deck <T>;
    private:
        T* ptr;
        int size;
        int visited;

        /**
         * @brief Const_iterator => Costruttore privato della classe Const_iterator
         * @param p => T*, array da iterare
         * @param s => int, dimensione dell'array
         */
        Const_iterator(T* p, int s): ptr(p), size(s), visited(0){};

    public:
        /**
         * @brief operator ++ prefisso
         * @return elemento successivo dell'iterazione
         */
        Const_iterator& operator++()
        {
            if(size>0)
            {
                ptr--;
                size--;
            }
            return *this;
        };

        /**
         * @brief operator ++ (int) postfisso
         * @return elemento corrente dell'iterazione e passa al successivo
         */
        Const_iterator operator++(int)
        {
            Const_iterator aux(*this);
            if(size>0)
            {
                ptr--;
                size--;
                visited++;
            }
            return aux;
        };

        /**
         * @brief operator -- prefisso
         * @return elemento precedente dell'iterazione
         */
        Const_iterator& operator--()
        {
           if(visited>0)
           {
               ptr++;
               size++;
               visited--;
           }
           return *this;
        };

        /**
         * @brief operator -- (int) postfisso
         * @return elemento corrente dell'iterazione e passa al precedente
         */
        Const_iterator operator--(int)
        {
            Const_iterator aux(*this);
            if(visited>0)
            {
                ptr++;
                size++;
                visited--;
            }
            return aux;
        };

        /**
         * @brief operator ==
         * @param i => Const_iterator, iteratore da confrontare passato per referenza
         * @return true se i due iteratori sono uguali, false altrimenti
         */
        bool operator==(const Const_iterator& i)
        {
            return ptr== i.ptr;
        };

        /**
         * @brief operator !=
         * @param i => Const_iterator, iteratore da confrontare passato per referenza
         * @return true se i due iteratori sono diversi, false altrimenti
         */
        bool operator!=(const Const_iterator& i)
        {
            return ptr != i.ptr;
        };

        /**
         * @brief operator *
         * @return T, valore puntatore dereferenziato come riferimento costante
         */
        const T& operator*() const
        {
            return *ptr;
        };

        /**
         * @brief operator ->
         * @return puntatore costante puntato dell'iteratore
         */
        const T* operator->() const
        {
            return ptr;
        };
    };

    /**
     * @brief begin
     * @return inizio dell'iteratore
     */
    Const_iterator begin() const
    {
        Const_iterator i(cards, 0);
        return Const_iterator(&cards[size-1], size);
    };

    /**
     * @brief end
     * @return fine dell'iteratore
     */
    Const_iterator end() const
    {
        return Const_iterator(&cards[0]-1, 0);
    };
};

template <class T>
std::ostream& operator<<(std::ostream& o, const Deck<T>& d)
{
    o << "{ ";
    for(auto cit= d.begin(); cit!=d.end(); cit++)
    {
        o << *cit << " ";
    }
    return o << "}";
}

#endif // DECK_H
