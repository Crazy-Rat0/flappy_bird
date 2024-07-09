#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bird.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bird* a_bird;
    QTimer* bird_drop_timer;
    QTimer* bird_cartoon_timer;

private:
    Ui::MainWindow *ui;
private slots:
    void updateBirdDrop();
    void updateBirdCartoon();
    void onFlyBtnClicked();
};
#endif // MAINWINDOW_H
