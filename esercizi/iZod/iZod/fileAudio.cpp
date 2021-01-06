#include "fileaudio.h"
#include <typeinfo>

FileAudio::FileAudio(std::string t, double s) : titolo(t), size(s) {}

FileAudio::~FileAudio() {};

double FileAudio::getSize() const
{
	return size;
}

bool FileAudio::operator==(const FileAudio& f)const
{
	return titolo == f.titolo && size == f.size && typeid(*this) == typeid(f);
}