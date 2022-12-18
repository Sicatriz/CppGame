#ifndef AUDIO_H
#define AUDIO_H

#include <qmediaplayer.h>
#include <QAudioOutput>
#include <QObject>

/**************************************/
/**************************************/
/*********  AUDIO FUNCTIONS  **********/
/**************************************/
/**************************************/

namespace insemi
{
class Audio: public QObject
{ Q_OBJECT
public:
    Audio();

    // play audio functions
    void playBullet(float bulletVolume) const;
    void playBulletHit(int volume) const;
    void playShipCollisionSound(float crashVolume);
    void playBackgroundMusic(float backgroundVolume) const;
    void playGameOver(int volume) const;
    void playBuffSound(int volume) const;

    // mediaplayer instances
    QMediaPlayer * music;
    QAudioOutput * audioOutput;
private:

    // volume setting by audiotype  ( 1 for 100% volume and 0 for volume off)
    const short int volume = 1;
    const  float backgroundVolume = 0.3;
    const  float bulletVolume = 0.5;
    const float crashVolume = 0.7;
};
}

#endif // AUDIO_H
