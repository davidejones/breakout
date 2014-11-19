#include "GameSound.h"

using namespace std;

GameSound::GameSound()
{
    bgchannel = 0;
    channel = 0;
    extradriverdata = 0;
	result = FMOD::System_Create(&system);
    result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);

    string filename = "./media/background.wav";
    result = system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &bgsound);
    result = bgsound->setMode(FMOD_LOOP_NORMAL);
    result = system->playSound(bgsound, 0, false, &bgchannel);

    filename = "./media/breakbrick.wav";
    result = system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &effect1);
    result = effect1->setMode(FMOD_LOOP_OFF);

    filename = "./media/lostlife.wav";
    result = system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &effect2);
    result = effect2->setMode(FMOD_LOOP_OFF);

    filename = "./media/levelcomplete.wav";
    result = system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &effect3);
    result = effect3->setMode(FMOD_LOOP_OFF);

    filename = "./media/paddlehit.wav";
    result = system->createSound(filename.c_str(), FMOD_DEFAULT, 0, &effect4);
    result = effect4->setMode(FMOD_LOOP_OFF);
}

void GameSound::update()
{
	system->update();
}

void GameSound::terminate()
{
	result = bgsound->release();
    result = effect1->release();
    result = effect2->release();
    result = effect3->release();
    result = effect4->release();
    result = system->close();
    result = system->release();
}

void GameSound::playSoundEffect(string name)
{
    if(name == "brickbreak")
    {
        result = system->playSound(effect1, 0, false, &channel);
    } else if(name == "lostlife") {
        result = system->playSound(effect2, 0, false, &channel);
    } else if(name == "levelcomplete") {
        result = system->playSound(effect3, 0, false, &channel);
    } else if(name == "paddlehit") {
        result = system->playSound(effect4, 0, false, &channel);
    }
    
}
