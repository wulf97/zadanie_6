//#include <unistd.h>
#include <QDebug>
#include <QThread>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Processing.h"
#include "Manager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    qDebug() << "Main thread: " << this->thread()->currentThreadId() << endl;
    Manager *manager = new Manager(this);
    Processing *pr = new Processing();

    manager->setViewport(ui->viewLabel);
    connect(ui->setDirButton, SIGNAL(released()), manager, SLOT(setDirDialog()));
    connect(manager, SIGNAL(setDir(QString, QString)), pr, SLOT(setDir(QString, QString)));
    connect(pr, SIGNAL(isUpdated(Mat)), manager, SLOT(displayImage(Mat)));
    connect(ui->playPauseButton, SIGNAL(released()), pr, SLOT(playPauseProcessing()));
}

MainWindow::~MainWindow() {
    delete ui;
}
