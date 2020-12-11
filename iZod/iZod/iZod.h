#ifndef IZOD_H
#define IZOD_H

#include "fileAudio.h"
#include "mp3.h"
#include <vector>

class iZod
{
private:
	class Brano
	{
	public:
		FileAudio* ptr;
		Brano(FileAudio*);
		Brano(const Brano&);
		~Brano();
		Brano& operator=(const Brano&);
	};

	std::vector<Brano> brani;
public:
	iZod();
	std::vector<Mp3> mp3(double, unsigned int) const;
	std::vector<FileAudio*> braniQual() const;
	void insert(Mp3*);
	void insert(FileAudio*);
};
#endif