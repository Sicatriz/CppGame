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

