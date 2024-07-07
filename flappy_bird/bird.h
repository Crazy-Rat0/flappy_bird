#ifndef BIRD_H
#define BIRD_H
#include <QPushButton>
#include <QWidget>


class bird:public QPushButton
{
public:
    bird(QWidget* temp);
    int JumpSec;//used to store the time of bird droping without flying interrupt
    int image_index;//used to make the images being cartoon
    int last_image_index;//used to store the last index of cartoon
public slots:
    void drop();
    void fly();
    void change_image();
};

#endif // BIRD_H
