class Vettore
{
	private:
		int* vett;
		int dim;
	public:
		Vettore() : vett(0), dim(0) {};
		Vettore(int);
		int getDim() const;
		void append(const Vettore&);
		int& operator[](int) const;
		bool operator==(const Vettore&) const;
		Vettore& operator=(const Vettore& v);
};

Vettore operator+(const Vettore& v1, const Vettore& v2);
std::ostream& operator<<(std::ostream& os, const Vettore& v);