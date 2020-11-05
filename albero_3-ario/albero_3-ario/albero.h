template<class T>
class albero
{
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

		bool search(const T& x)
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
};