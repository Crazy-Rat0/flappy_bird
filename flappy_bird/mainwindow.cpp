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

    bird_drop_timer = new QTimer(this);
    connect(bird_drop_timer,&QTimer::timeout,a_bird,&bird::drop);
    bird_drop_timer->start(25);//25ms drop a unit


    bird_cartoon_timer = new QTimer(this);
    connect(bird_cartoon_timer,&QTimer::timeout,a_bird,&bird::change_image);
    bird_cartoon_timer->start(100);



    connect(ui->flyBtn,&QPushButton::clicked,a_bird,&bird::fly);
    connect(a_bird,&QPushButton::clicked,a_bird,&bird::fly);

}

MainWindow::~MainWindow()
{
    delete ui;
}

