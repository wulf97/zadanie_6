#include "MainWindow.h"
#include <QApplication>
#include <opencv2/core.hpp>

using namespace cv;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qRegisterMetaType<Mat>("Mat");

    return a.exec();
}
