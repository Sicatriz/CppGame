#ifndef AUDIO_H
#define AUDIO_H

#include <qmediaplayer.h>
#include <QAudioOutput>
#include <QObject>

class Audio: public QObject
{ Q_OBJECT
public:
    Audio();
    void playBullet() const;
    void playBulletHit() const;
    void playShipCollisionSound();
    void playBackgroundMusic() const;
    void playGameOver() const;
    void playBuffSound() const;


    QMediaPlayer * music;
    QAudioOutput * audioOutput;
};

#endif // AUDIO_H
