#ifndef PROCESSING_H
#define PROCESSING_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QMutex>
#include <QVector>
#include <QTimer>
#include <QWaitCondition>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

class Processing : public QObject {
    Q_OBJECT
public:
    Processing(QObject *parent = 0);
    virtual ~Processing();

    void start();
public slots:
    void setDir(QString, QString);
    void playPauseProcessing();
private slots:
    void updateImage();
signals:
    void isUpdated(Mat);
private:
    QThread m_thread;
    QMutex m_mutex;
    QTimer m_timer;
    QString m_patch;
    QVector<QString> m_pictureList;
    int m_iPicture = 0;
    int m_index = 0;
    bool m_state = 0; //0 - play; 1 - pause
};

#endif // PROCESSING_H
