#ifndef BIRD_H
#define BIRD_H
#include <QPushButton>
#include <QWidget>


class bird:public QPushButton
{
public:
    bird(QWidget* temp);
public slots:
    void drop();
    void fly();
};

#endif // BIRD_H
