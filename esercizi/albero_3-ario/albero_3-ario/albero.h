template<class T> class albero;//dichiarazione incompleta
template<class T> std::ostream& operator<<(std::ostream& os, const albero<T>& a);

template<class T>
class albero
{
	friend std::ostream& operator<< <T>(std::ostream&, const albero<T>&);
	private:
		class nodo {
			public:
				T info;
				nodo* sx, * cx, * dx;
				nodo(const T& x, nodo* s = 0, nodo* c = 0, nodo* d = 0) :info(x), sx(s), cx(c), dx(d) {}
		};

		nodo* root;

		static void distruggi(nodo* r)
		{
			if (r)
			{
				distruggi(r->sx);
				distruggi(r->cx);
				distruggi(r->dx);
				delete r;
			}
		}

		static nodo* copia(nodo* r)
		{
			if (!r)
				return nullptr;
			return new nodo(r->info, copia(r->sx), copia(r->cx), copia(r->dx));
		}

		static bool search_ric(const T& x, nodo* r)
		{
			if (!r)
				return false;
			if (r->info == x)
				return true;
			return search_ric(x, r->sx) || search_ric(x, r->cx) || search_ric(x, r->dx);
		}

		static bool equals_ric(nodo* r1, nodo* r2)
		{
			if (!r1 && !r2)
				return true;
			if (!r1 || !r2)
				return false;
			return r1->info == r2->info && equals_ric(r1->sx, r2->sx) && equals_ric(r1->cx, r2->cx) && equals_ric(r1->dx, r2->dx);
		}

		static std::ostream& print_ric(std::ostream& os, nodo* r)
		{
			if (!r) return os;
			print_ric(os, r->sx);
			print_ric(os, r->cx);
			print_ric(os, r->dx);
			return os << r->info << " ";//T deve supportare operator<<
		}

	public:
		albero() :root(nullptr) {};
		albero(const albero& a) : root(copia(a.root)) {};

		~albero()
		{
			if (root)
				distruggi(root);
		}

		void insert(const T& x)
		{
			root = new nodo(x, copia(root), copia(root), root);
		}

		bool search(const T& x) const
		{
			return search_ric(x, root);
		}

		albero& operator=(const albero& a)
		{
			if (this != &a)
			{
				distruggi(root);
				root = copia(a.root);
			}
			return *this;
		}

		bool operator==(const albero& a) const
		{
			return equals_ric(root, a.root);
		}
};

template <class T>
std::ostream& operator<<(std::ostream& os, const albero<T>& a)
{
	return albero<T>::print_ric(os, a.root);
}