#include <QDir>
#include <QFileDialog>
#include <QDebug>
#include <QString>
#include <QPixmap>
#include <QImage>

#include "Manager.h"

Manager::Manager(QObject *parent) : QObject(parent) {

}

void Manager::setViewport(QLabel *lbl) {
    m_viewport = lbl;
    lbl->setAlignment(Qt::AlignCenter);
}

void Manager::setDirDialog() {
    QDir dir;
    QString fullName = QFileDialog::getOpenFileName(nullptr, "Set dir", ".", "Images(*.png *jpg *.bmp)");
    if (fullName != "") {
        QString fName = QFileInfo(fullName).fileName();
        QString fPatch = QFileInfo(fullName).path() + '/';

        emit setDir(fPatch, fName);
    }
}

void Manager::displayImage(Mat imgCV) {
    QImage img(imgCV.data, imgCV.cols, imgCV.rows, imgCV.step, QImage::Format_RGB888);
    img = img.scaledToHeight(m_viewport->size().height());
    m_viewport->setPixmap(QPixmap::fromImage(img));
}
