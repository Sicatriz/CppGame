#include "audio.h"

Audio::Audio(): QObject()
{
    music = new QMediaPlayer();
    audioOutput = new QAudioOutput();
}

// FIRE BULLET SOUND
void Audio::playBullet()
{
        music->setAudioOutput(audioOutput);
        music->setSource(QUrl("qrc:/sounds/sounds/shoot1.wav"));
        music->audioOutput()->setVolume(0.5);
        music->play();
}

// BULLET IMPACT SOUND
void Audio::playBulletHit()
{
    music->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/sounds/sounds/Explosion.wav"));
    music->audioOutput()->setVolume(1);
    music->play();
}

void Audio::playShipCollisionSound()
{
    int ran = rand()%5;

    music->setAudioOutput(audioOutput);

    if(ran%5 == 0)
    {
        music->setSource(QUrl("qrc:/sounds/sounds/adios.wav"));
    }
    else if(ran%5 == 1)
    {
        music->setSource(QUrl("qrc:/sounds/sounds/shouting_karen.wav"));
    }
    else if(ran%5 == 2)
    {
        music->setSource(QUrl("qrc:/sounds/sounds/cry_karen.wav"));
    }
    else if(ran%5 == 3)
    {
        music->setSource(QUrl("qrc:/sounds/sounds/death_1_ian.wav"));
    }
    else if(ran%5 == 4)
    {
        music->setSource(QUrl("qrc:/sounds/sounds/death_5_sean.wav"));
    }
    else
    {
        music->setSource(QUrl("qrc:/sounds/sounds/death_8_sean.wav"));
    }

    music->audioOutput()->setVolume(1);
    music->play();
}

// BACKGROUND SOUND
void Audio::playBackgroundMusic()
{
    music->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/sounds/sounds/slow-travel.wav"));
    audioOutput->setVolume(0.3);
    music->play();
}

// GAME OVER
void Audio::playGameOver()
{
    music->setAudioOutput(audioOutput);
    music->setSource(QUrl("qrc:/sounds/sounds/gameOver_karen.wav"));
    music->audioOutput()->setVolume(1);
    music->play();
}

