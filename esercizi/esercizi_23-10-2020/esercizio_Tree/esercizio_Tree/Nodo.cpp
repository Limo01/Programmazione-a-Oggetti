class Nodo { 
	friend class Tree;
	private:
		Nodo(char c = '*', Nodo* s = 0, Nodo* d = 0) : info(c), sx(s), dx(d) {}
		char info; 
		Nodo* sx; 
		Nodo* dx; 
};