#ifndef GAMESOUND_H
#define GAMESOUND_H

#include <SFML/Audio.hpp>
#include <iostream>
#include <string>

class GameSound
{
private:
    sf::SoundBuffer buffer;
    sf::Music music;
    sf::Sound soundeffect;
public:
	GameSound();
	void update();
	void terminate();
	void playSoundEffect(std::string name);
};

#endif