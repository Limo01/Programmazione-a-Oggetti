#ifndef MP3_H
#define MP3_H

#include "fileAudio.h"

class Mp3 : public FileAudio 
{
private:
	unsigned int kbits;
public:
	static const unsigned int sogliaQualita;
	Mp3(std::string, double, int);
	Mp3* clone() const override;
	bool qualita() const override;
	unsigned int getBitrate() const;
	virtual bool operator==(const FileAudio&) const override;
};
#endif