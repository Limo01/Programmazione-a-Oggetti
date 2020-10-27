#include "Nodo.cpp";

class Tree {
	public:
		Tree() : root(nullptr) {}
		Tree(const Tree&); // dichiarazione costruttore di copia
		~Tree();//distruttore
		Tree& operator=(const Tree& t);
	private:
		Nodo* root;
		static Nodo* copiaAlbero(const Nodo*);
		static void distruggi(Nodo* r);
};

Nodo* Tree::copiaAlbero(const Nodo* r)
{
	if (r!=nullptr)
		return new Nodo(r->info, copiaAlbero(r->sx), copiaAlbero(r->dx));
	else
		return 0;
}

void Tree::distruggi(Nodo* r)
{
	if(r!=nullptr)
	{
		distruggi(r->sx);
		distruggi(r->dx);
		delete r;
	}
}

Tree::Tree(const Tree& t): root(copiaAlbero(t.root)){}

Tree::~Tree()
{
	if (root)
		distruggi(root);
}

Tree& Tree::operator=(const Tree& t)
{
	if(this != &t)
	{
		distruggi(root);
		root = copiaAlbero(t.root);
	}
	return *this;
}