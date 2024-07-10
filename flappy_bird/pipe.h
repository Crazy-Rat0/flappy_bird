#ifndef PIPE_H
#define PIPE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QRandomGenerator>

class pipe : public QPushButton
{
    Q_OBJECT

    friend class pipeList;
    friend class MainWindow;
private:
    pipe(QWidget *parent, int ax, int h, int flag);
    void movePipe();
    int ax; // 管子横坐标
    int h;  // 管子高度
    int flag;   // 区分上下两种管子
};

class pipeList : public QLabel
{
    Q_OBJECT

    friend class MainWindow;
public:
    int getCount() { return pipeCount; }
    pipeList(QWidget *parent);
private:
    const static int pipeCount = 128;
    pipe* pipe_list[pipeCount][2];
};

#endif // PIPE_H
