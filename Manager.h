#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QLabel>
#include <QString>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

class Manager : public QObject {
    Q_OBJECT
public:
    Manager(QObject *parent = nullptr);
    virtual ~Manager() {}

    void setViewport(QLabel*);
public slots:
    void setDirDialog();
    void displayImage(Mat);
signals:
    void setDir(QString, QString);
private:
    QLabel *m_viewport;
};

#endif // MANAGER_H
