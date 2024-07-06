#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bird.h"
#include "QTimer"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a_bird = new bird(this);
    bird_timer = new QTimer(this);
    connect(bird_timer,&QTimer::timeout,a_bird,&bird::drop);
    bird_timer->start(500);
    connect(ui->flyBtn,&QPushButton::clicked,a_bird,&bird::fly);
    connect(a_bird,&QPushButton::clicked,a_bird,&bird::fly);

}

MainWindow::~MainWindow()
{
    delete ui;
}

