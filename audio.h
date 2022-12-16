#ifndef AUDIO_H
#define AUDIO_H

#include <qmediaplayer.h>
#include <QAudioOutput>
#include <QObject>

class Audio: public QObject
{ Q_OBJECT
public:
    Audio();
    void playBullet(float bulletVolume) const;
    void playBulletHit(int volume) const;
    void playShipCollisionSound(float crashVolume);
    void playBackgroundMusic(float backgroundVolume) const;
    void playGameOver(int volume) const;
    void playBuffSound(int volume) const;


    QMediaPlayer * music;
    QAudioOutput * audioOutput;
private:
    const short int volume = 1;
    const  float backgroundVolume = 0.3;
    const  float bulletVolume = 0.5;
    const float crashVolume = 0.7;
};

#endif // AUDIO_H
