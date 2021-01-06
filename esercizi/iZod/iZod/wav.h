#ifndef WAV_H
#define WAV_H

#include "fileAudio.h"

class Wav : public FileAudio 
{
private:
	unsigned int frequenza;
	bool lossless;
public:
	static const unsigned int sogliaQualita;
	Wav(std::string, double, int, bool);
	Wav* clone() const override;
	bool qualita() const override;
	bool isLossless() const;
};
#endif