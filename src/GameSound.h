#ifndef GAMESOUND_H
#define GAMESOUND_H

#include "fmod.hpp"
#include "fmod_errors.h"
#include <iostream>
#include <string>

class GameSound
{
private:
	FMOD::System     *system;
    FMOD::Sound      *bgsound, *effect1, *effect2, *effect3, *effect4;
    FMOD::Channel    *channel, *bgchannel;
    FMOD_RESULT       result;
    unsigned int      version;
    void             *extradriverdata;
public:
	GameSound();
	void update();
	void terminate();
	void playSoundEffect(std::string name);
};

#endif