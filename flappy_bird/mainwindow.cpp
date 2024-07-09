#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pipe.h"
#include "bird.h"
#include "QTimer"
#include "QIcon"
#include "QLabel"
#include "QVBoxLayout"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gameOverLabel(new QLabel(this))
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Images/bird.ico"));//modify icon

    pipe_list = new pipeList(this);

    a_bird = new bird(this);

    bird_drop_timer = new QTimer(this);
    connect(bird_drop_timer, &QTimer::timeout, this, &MainWindow::updateBirdDrop);
    bird_drop_timer->start(25);//25ms drop a unit


    bird_cartoon_timer = new QTimer(this);
    connect(bird_cartoon_timer, &QTimer::timeout, this, &MainWindow::updateBirdCartoon);
    bird_cartoon_timer->start(100);

    connect(ui->flyBtn, &QPushButton::clicked, this, &MainWindow::onFlyBtnClicked);
    connect(a_bird, &QPushButton::clicked, this, &MainWindow::onFlyBtnClicked);

    pipe_move_timer = new QTimer(this);
    for (int i = 0; i < pipe_list->pipeCount; i++) {
        connect(pipe_list->pipe_list[i][0], &QPushButton::clicked, this, &MainWindow::onFlyBtnClicked);
        connect(pipe_list->pipe_list[i][1], &QPushButton::clicked, this, &MainWindow::onFlyBtnClicked);
        connect(pipe_move_timer, &QTimer::timeout, pipe_list->pipe_list[i][0], &pipe::movePipe);
        connect(pipe_move_timer, &QTimer::timeout, pipe_list->pipe_list[i][1], &pipe::movePipe);
    }
    pipe_move_timer->start(25);
    // 初始化 gameOverLabel
    gameOverLabel->setPixmap(QPixmap(":/Images/gameover.png"));
    gameOverLabel->setAlignment(Qt::AlignCenter);
    gameOverLabel->setVisible(false);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(gameOverLabel, 0, Qt::AlignCenter);
    centralWidget()->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateBirdDrop()
{
    if (!a_bird->Ifdead()) {
        a_bird->drop();
    } else {
        bird_drop_timer->stop();
        bird_cartoon_timer->stop();
        showGameOver();
    }
}

void MainWindow::updateBirdCartoon()
{
    if (!a_bird->Ifdead()) {
        a_bird->change_image();
    } else {
        bird_cartoon_timer->stop();
    }
}
void MainWindow::onFlyBtnClicked()
{
    if (!a_bird->Ifdead()) {
        a_bird->fly();
    } else {

    }
}

void MainWindow::showGameOver()
{
    gameOverLabel->setVisible(true); // 显示 GAME OVER 图标
}

