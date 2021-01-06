#ifndef DEEPPTR_H
#define DEEPPTR_H

template<class T>
class DeepPtr
{
private:
    T* ptr;
public:
    /**
     * @brief DeepPtr => Costruttore della classe DeepPtr
     * @param p => T*, puntatore all'oggetto
     */
    DeepPtr(T* p=nullptr):ptr(p){};

    /**
     * @brief DeepPtr => Costruttore di copia della classe DeepPtr
     * @param p => DeepPtr, oggetto da copiare passato per riferimento costante. Il tipo T deve implementare il metodo clone
     */
    DeepPtr(const DeepPtr& p): ptr(p.ptr->clone()){};

    /**
     * @brief Distruttore della classe DeepPtr
     */
    ~DeepPtr(){delete ptr;};

    /**
     * @brief operator =
     * @param p => DeepPtr, oggetto da assegnare passato per riferimento costante
     * @return DeepPtr, dereferenzizione di this con ptr clonato ritornato per referenza
     */
    DeepPtr& operator=(const DeepPtr& p)
    {
        if(this != &p)
        {
            delete ptr;
            ptr= p.ptr->clone();
        }
        return *this;
    };

    /**
     * @brief get
     * @return T*, puntatore interno alla classe
     */
    T* get() const
    {
        return ptr;
    };

    /**
     * @brief operator ->
     * @return T*, puntatore interno alla classe
     */
    T* operator->() const
    {
        return ptr;
    };

    /**
     * @brief operator *
     * @return T, dereferenziazione del puntatore interno alla classe passato per referenza
     */
    T& operator*() const
    {
        return *ptr;
    };
};
#endif // DEEPPTR_H
