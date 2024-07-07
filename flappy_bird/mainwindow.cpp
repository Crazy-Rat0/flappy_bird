#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bird.h"
#include "QTimer"
#include "QIcon"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Images/bird.ico"));//modify icon

    a_bird = new bird(this);
    bird_timer = new QTimer(this);
    connect(bird_timer,&QTimer::timeout,a_bird,&bird::drop);
    bird_timer->start(25);//25ms drop a unit
    connect(ui->flyBtn,&QPushButton::clicked,a_bird,&bird::fly);
    connect(a_bird,&QPushButton::clicked,a_bird,&bird::fly);

}

MainWindow::~MainWindow()
{
    delete ui;
}

