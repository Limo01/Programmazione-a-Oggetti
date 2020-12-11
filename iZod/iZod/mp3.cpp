#include "mp3.h"

Mp3::Mp3(std::string t, double s, int k) :FileAudio(t, s), kbits(k) {};

Mp3* Mp3::clone() const
{
	return new Mp3(*this);
};

bool Mp3::qualita() const
{
	return kbits >= sogliaQualita;
};

unsigned int Mp3::getBitrate() const
{
	return kbits;
};

bool Mp3::operator==(const FileAudio& f) const
{
	return FileAudio::operator==(f) && kbits == static_cast<const Mp3&>(f).kbits;
};

const unsigned int Mp3::sogliaQualita = 192;