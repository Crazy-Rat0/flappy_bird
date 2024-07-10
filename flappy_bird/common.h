#ifndef COMMON_H
#define COMMON_H

#include <QObject>
class common:public QObject
{
    Q_OBJECT
public:
    common(int y=202);
    //virtual ~common();
    int bird_y;
    //int bird_x;
public slots:
    void drop();
    void fly();
signals:
    void bird_y_change(int y);
    //void bird_x_change(int x);
};

#endif // COMMON_H
