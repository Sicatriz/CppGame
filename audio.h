#ifndef AUDIO_H
#define AUDIO_H

#include <qmediaplayer.h>
#include <QAudioOutput>
#include <QObject>

class Audio: public QObject
{ Q_OBJECT
public:
    Audio();
    void playBullet();
    void playBulletHit();
    void playShipCollisionSound();
    void playBackgroundMusic();
    void playGameOver();


    QMediaPlayer * music;
    QAudioOutput * audioOutput;
};

#endif // AUDIO_H
