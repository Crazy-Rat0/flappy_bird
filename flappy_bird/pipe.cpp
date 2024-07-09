#include "pipe.h"

pipe::pipe(QWidget *parent, int ax, int h, int flag) : QPushButton(parent)
{
    if (flag) { // 下
        this->move(ax, 448 - h);
        this->resize(70, 250);
        this->setStyleSheet("background-image: url(:/Images/pipe2.png);"
                            "background-repeat: no-repeat;"
                            "background-color: rgba(0, 0, 0, 0);");
    }
    else {  // 上
        this->move(ax, h - 250);
        this->resize(70, 250);
        this->setStyleSheet("background-image: url(:/Images/pipe1.png);"
                            "background-repeat: no-repeat;"
                            "background-color: rgba(0, 0, 0, 0);");
    }
}

void pipe::movePipe()
{
    this->move(this->x() - 4, this->y());
}

pipeList::pipeList(QWidget *parent) : QLabel(parent)
{
    int h_up, h_down, gap;
    for (int i = 0; i < pipeCount; i++) {
        h_up = QRandomGenerator::global()->bounded(398);
        gap = QRandomGenerator::global()->bounded(50, 448 - h_up);
        h_down = 448 - h_up - gap;
        pipe_list[i][0] = new pipe(parent, i * 200, h_up, 0);
        pipe_list[i][1] = new pipe(parent, i * 200, h_down, 1);
    }
}
