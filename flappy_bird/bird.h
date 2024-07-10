#ifndef BIRD_H
#define BIRD_H

#include <QPushButton>
#include <QWidget>
#include "pipe.h"

class bird:public QPushButton
{
    Q_OBJECT
public:
    bird(QWidget* temp);
    int JumpSec;//used to store the time of bird droping without flying interrupt
    int image_index;//used to make the images being cartoon
    int last_image_index;//used to store the last index of cartoon
    bool Isdead = 0;
    bool Ifdead();
    void Setdead();
public slots:
    //void drop();
    //void fly();
    void change_image();
    void bird_change(int y);

};

#endif // BIRD_H
