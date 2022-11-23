#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class MyRect: public QObject, public QGraphicsRectItem
{
   Q_OBJECT // myrect needs to be an Qobject for movement
public:
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawn();
};

#endif // MYRECT_H
