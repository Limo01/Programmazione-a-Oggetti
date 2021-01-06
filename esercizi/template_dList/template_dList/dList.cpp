/*
ESERCIZIO.

Definire un template di classe dList<T> i cui oggetti rappresentano una struttura dati lista doppiamente concatenata (doubly linked list) per elementi di uno stesso tipo T. Il template dList<T> deve soddisfare i seguenti vincoli:

1. Gestione della memoria senza condivisione.

2. dList<T> rende disponibile un costruttore dList(unsigned int k, const T& t) che costruisce una
lista contenente k nodi ed ognuno di questi nodi memorizza una copia di t.

3. dList<T> permette l’inserimento in testa ed in coda ad una lista in tempo O(1) (cioe` costante):
-- Deve essere disponibile un metodo void insertFront(const T&) con il seguente comportamento: dl.insertFront(t) inserisce l’elemento t in testa a dl in tempo O(1).
-- Deve essere disponibile un metodo void insertBack(const T&) con il seguente comportamento: dl.insertBack(t) inserisce l’elemento t in coda a dl in tempo O(1).

4. dList<T> rende disponibile un opportuno overloading di operator< che implementa l’ordinamento lessicografico (ad esempio, si ricorda che per l'ordinamento lessicografico tra stringhe abbiamo che "campana" < "cavolo" e che "buono" < "ottimo").

5. dList<T> rende disponibile un tipo iteratore costante dList<T>::const_iterator i cui oggetti permettono di iterare sugli elementi di una lista.
*/

template <class T>
class dList
{
private:
	class nodo
	{
	public:
		T info;
		nodo* prev, * next;
		nodo(const T& t, nodo* p = 0, nodo* n = 0) : info(t), prev(p), next(n) {}
	};
	nodo* first, * last;

	static void destroy(nodo* n)
	{
		if (n != nullptr)
		{
			destroy(n->next);
			delete n;
		}
	};

	static void deep_copy(nodo* src, nodo*& first, nodo*& last)
	{
		if (src)
		{
			first = last = new nodo(src->info);
			nodo* aux = src->next;

			while (aux)
			{
				last = new nodo(aux->info, last);
				last->prev->next = last;
				aux = aux->next;
			}
		}
		else first = last = nullptr;
	};

	static bool isLess(const nodo* l1, const nodo* l2)
	{
		if (!l1 && !l2) return false;
		if (!l1) return true;
		if (!l2) return false;
		if (l1->info < l2->info) return true;
		if (l1->info > l2->info) return false;
		return isLess(l1->next, l2->next);
	};

public:
	dList(unsigned int k, const T& t) : first(nullptr), last(nullptr)
	{
		for (unsigned int j = 0; j < k; ++j)
			insertFront(t);
	};

	dList(const dList& l)
	{
		deep_copy(l.first, first, last);
	};

	~dList()
	{
		destroy(first);
	};

	void insertFront(const T& t)
	{
		if (first)
		{
			first = new nodo(t, nullptr, first);
			first->next->prev = first;
		}
		else first = last = new nodo(t);
	};

	void insertBack(const T& t)
	{
		if (last)
		{
			last = new nodo(t, last, nullptr);
			last->prev->next = last;
		}
		else first = last = new nodo(t);
	};

	bool operator<(const dList& l) const
	{
		if (this == &l) return false;//1 < 1 sempre false
		return isLess(first, l->first);
	};

	dList& operator=(const dList& l)
	{
		if (this != &l)
		{
			destroy(first);
			deep_copy(l.first, first, last);
		}
		return *this;
	};

	class const_iterator
	{
		friend dList<T>;
	private:
		const nodo* ptr;
		bool past_the_end;
		const_iterator(nodo* p, bool pte = false) :ptr(p), past_the_end(pte) {};
	public:
		const_iterator() : ptr(nullptr), past_the_end(false) {};

		const_iterator& operator++()
		{
			if (ptr != nullptr)
			{
				if (!past_the_end)
				{
					if (ptr->next != nullptr)
					{
						ptr = ptr->next;
					}
					else
					{
						ptr = ptr + 1;
						past_the_end = true;
					}
				}
			}
			return *this;
		};

		const_iterator operator++(int)
		{
			const_iterator aux(*this);

			if (ptr != nullptr)
			{
				if (!past_the_end)
				{
					if (ptr->next != nullptr)
					{
						ptr = ptr->next;
					}
					else
					{
						ptr = ptr + 1;
						past_the_end = true;
					}
				}
			}
			return aux;
		};

		const_iterator& operator--()
		{
			if (ptr != nullptr)
			{
				if (ptr == first)
				{
					ptr = nullptr;
				}
				else if (!past_the_end)
				{
					ptr = ptr->prev;
				}
				else
				{
					ptr = ptr - 1;
					past_the_end = false;
				}
			}
			return *this;
		};

		const_iterator& operator--(int)
		{
			const_iterator aux(*this);

			if (ptr != nullptr)
			{
				if (ptr == first)
				{
					ptr = nullptr;
				}
				else if (!past_the_end)
				{
					ptr = ptr->prev;
				}
				else
				{
					ptr = ptr - 1;
					past_the_end = false;
				}
			}
			return aux;
		};

		bool operator==(const const_iterator& cit)
		{
			return ptr == cit.ptr;
		};

		bool operator!=(const const_iterator& cit)
		{
			return ptr != cit.ptr;
		};

		const T& operator*() const
		{
			return ptr->info;
		};

		const T* operator->() const
		{
			return &(ptr->info);
		};
	};

	const_iterator begin() const
	{
		return const_iterator(first, false);
	};

	const_iterator end() const
	{
		return const_iterator(last + 1, true);
	};
};