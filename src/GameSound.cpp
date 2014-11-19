#include "GameSound.h"

using namespace std;

GameSound::GameSound()
{    
    if (!music.openFromFile("./media/background.wav"))
    {
        cout << "error " << endl;
    }
    music.setLoop(true);
    music.play();
}

void GameSound::update()
{

}

void GameSound::terminate()
{

}

void GameSound::playSoundEffect(string name)
{
    if(name == "brickbreak")
    {
        if (!buffer.loadFromFile("./media/breakbrick.wav"))
        {
            cout << "error " << endl;
        }

    } else if(name == "lostlife") {
        
        if (!buffer.loadFromFile("./media/lostlife.wav"))
        {
            cout << "error " << endl;
        }

    } else if(name == "levelcomplete") {
        
        if (!buffer.loadFromFile("./media/levelcomplete.wav"))
        {
            cout << "error " << endl;
        }

    } else if(name == "paddlehit") {
        
        if (!buffer.loadFromFile("./media/paddlehit.wav"))
        {
            cout << "error " << endl;
        }
    }
    soundeffect.setBuffer(buffer);
    soundeffect.setLoop(false);
    soundeffect.play();
}
