#include "wav.h"

Wav::Wav(std::string t, double s, int f, bool l) :FileAudio(t, s), frequenza(f), lossless(l) {}

Wav* Wav::clone() const
{
	return new Wav(*this);
};

bool Wav::qualita() const
{
	return frequenza >= sogliaQualita;
};

bool Wav::isLossless() const
{
	return lossless;
};

const unsigned int Wav::sogliaQualita = 96;