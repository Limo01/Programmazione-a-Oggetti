#include "iZod.h"
#include "wav.h"

iZod::Brano::Brano(FileAudio* p) : ptr(p->clone()) {};

iZod::Brano::Brano(const Brano& b) : ptr(b.ptr->clone()) {};

iZod::Brano::~Brano() { delete ptr; };

iZod::iZod() {};

iZod::Brano& iZod::Brano::operator=(const Brano& b)
{
	if(this != &b)
	{
		delete ptr;
		ptr = b.ptr->clone();
	}
	return *this;
}

std::vector<Mp3> iZod::mp3(double dim, unsigned int br) const
{
	std::vector<Mp3> v;
	for(auto cit= brani.begin(); cit != brani.end(); cit++)
	{
		Mp3* p = dynamic_cast<Mp3*>(cit->ptr);
		if (p != nullptr && p->getSize() >= dim && p->getBitrate() >= br)
			v.push_back(*p);
	}
	return v;
};

std::vector<FileAudio*> iZod::braniQual() const
{
	std::vector<FileAudio*> v;
	for(auto cit= brani.begin(); cit!=brani.end(); cit++)
	{
		if((cit->ptr)->qualita())
		{
			if (dynamic_cast<Wav*>(cit->ptr) == nullptr || static_cast<Wav*>(cit->ptr)->isLossless())
				v.push_back(cit->ptr);
		}
	}
	return v;
};

void iZod::insert(Mp3* p)
{
	bool trovato = false;
	for (auto it = brani.begin(); it != brani.end() && !trovato; it++)
	{
		trovato = *(it->ptr) == *p;
	}
	if (!trovato)
		brani.push_back(p);
};

void iZod::insert(FileAudio* p)
{
	bool trovato = false;
	for (auto it = brani.begin(); it != brani.end() && !trovato; it++)
	{
		trovato = *(it->ptr) == *p;
	}
	if (!trovato)
		brani.push_back(p);
};