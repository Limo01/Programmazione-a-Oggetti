#ifndef FILEAUDIO_H
#define FILEAUDIO_H

#include <iostream>

class FileAudio {
private:
	std::string titolo;
	double size;
public:
	FileAudio(std::string, double);
	virtual FileAudio* clone() const = 0;
	virtual bool qualita() const = 0;
	virtual ~FileAudio();
	virtual bool operator==(const FileAudio&) const;
	double getSize() const;
};
#endif