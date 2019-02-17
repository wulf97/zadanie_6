#include <QDebug>
#include <QFile>
#include <QDir>

#include "Processing.h"

Processing::Processing(QObject *parent) : QObject(parent) {
    this->moveToThread(&m_thread);
    m_timer.moveToThread(&m_thread);
    m_thread.start();
}

Processing::~Processing() {
    m_thread.quit();
    m_thread.wait();
}


void Processing::start() {
    m_timer.start(1000);
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(updateImage()));
}

/*************** Слоты ****************/
void Processing::setDir(QString fPatch, QString fName) {
    QDir dir(fPatch);
    QStringList filter;
    QFileInfoList fList;

    filter << "*.png" << "*.jpg" << "*.bmp";
    dir.setNameFilters(filter);
    fList = dir.entryInfoList();

    m_patch = fPatch;
    m_pictureList.clear();
    for (int i = 0; i < fList.size(); i++) {
        if (fList[i].fileName() == fName) {
            m_iPicture = i;
            m_index = i;
        }

        m_pictureList.push_back(fList[i].fileName());
    }

    if (m_pictureList.size() > 1)
        emit start();
}

void Processing::playPauseProcessing()
{
    if (m_state == 0){
        m_timer.stop();
        m_state = 1;
    }
    else {
        m_timer.start(1000);
        m_state = 0;
    }
}

void Processing::updateImage() {
    Mat img;
    if (m_pictureList.size() > 0) {
        if (m_index < m_pictureList.size() - 1) {
            m_index++;
        } else {
            m_index = 0;
        }

        qDebug() << "[" << m_index << "]" << m_pictureList[m_index] << endl;

        img = imread(QString(m_patch + m_pictureList[m_index]).toStdString());

        if (!img.empty()) {
            cvtColor(img, img, CV_BGR2RGB);
            emit isUpdated(img);
        }
    }
}
