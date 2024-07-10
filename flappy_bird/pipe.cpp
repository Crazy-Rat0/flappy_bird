#include "pipe.h"

pipe::pipe(QWidget *parent, int ax, int h, int flag) : QPushButton(parent)
{
    if (flag) { // 下
        this->move(ax, 448 - h); // 下管道从底部开始
        this->resize(70, h); // 设置下管道高度
        this->setStyleSheet("background-image: url(:/Images/pipe2.png);"
                            "background-repeat: no-repeat;"
                            "background-color: rgba(0, 0, 0, 0);");
    }
    else {  // 上
        this->move(ax, 0); // 上管道从顶部开始
        this->resize(70, h); // 设置上管道高度
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
        h_up = QRandomGenerator::global()->bounded(100, 200); // 上管道高度在 100 到 200 之间
        gap = 150; // 管道之间的间隙固定为 150
        h_down = 448 - h_up - gap; // 下管道高度自动调整

        pipe_list[i][0] = new pipe(parent, i * 200 + 400, h_up, 0); // 上管道
        pipe_list[i][1] = new pipe(parent, i * 200 + 400, h_down, 1); // 下管道
    }
}
